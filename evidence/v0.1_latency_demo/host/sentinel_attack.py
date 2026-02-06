import serial
import time
import sys

# --- CONFIGURATION ---
# Note: Users must update this port for their own machine
SERIAL_PORT = '/dev/cu.usbmodem186720801' 
BAUD_RATE = 9600

def connect_to_sentinel():
    try:
        print(f"Connecting to Sentinel Hardware at {SERIAL_PORT}...")
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        time.sleep(2) # Allow MCU reset
        ser.reset_input_buffer()
        print("STATUS: ONLINE. READY FOR INVARIANT TESTING.")
        return ser
    except Exception as e:
        print(f"ERROR: Could not connect to {SERIAL_PORT}")
        print("Tip: Check your USB cable and update SERIAL_PORT in the script.")
        sys.exit(1)

def send_attack(ser, angle):
    print(f"\n[UPSTREAM] Requesting Actuator Position: {angle}°")
    
    # Send the "Unsafe" command
    command = f"{angle}\n"
    ser.write(command.encode('utf-8'))
    
    # Wait for Sentinel (Teensy) to process and reply
    time.sleep(0.1) 
    
    # Read the hardware's actual action
    if ser.in_waiting > 0:
        response = ser.readline().decode('utf-8').strip()
        # Parse the response "Moving to: X"
        if "Moving to:" in response:
            try:
                executed_angle = int(response.split(":")[1].strip())
                
                # THE FIREWALL CHECK
                if executed_angle != angle:
                    print(f"!!! INTERVENTION DETECTED !!!")
                    print(f"[SENTINEL] BLOCKED request for {angle}°")
                    print(f"[SENTINEL] CLAMPED value to safe limit: {executed_angle}°")
                    print(f"RESULT: SAFETY INVARIANT ENFORCED.")
                else:
                    print(f"[SENTINEL] Command {angle}° is within Safe Envelope. Allowed.")
            except:
                print(f"[PARSE ERROR] {response}")
        else:
            print(f"[HARDWARE RAW]: {response}")

# --- ATTACK LOOP ---
if __name__ == "__main__":
    ser = connect_to_sentinel()
    
    print("\n--- SENTINEL V0.1 STRESS TEST ---")
    print("Try sending unsafe values (e.g., -50, 200, 500).")
    print("Type 'quit' to exit.")
    
    try:
        while True:
            user_input = input("\nInject Value: ")
            if user_input.lower() == 'quit': break
            
            try:
                val = int(user_input)
                send_attack(ser, val)
            except ValueError:
                print("Please enter a valid integer.")
                
    except KeyboardInterrupt:
        print("\nDisconnecting...")
    finally:
        ser.close()
