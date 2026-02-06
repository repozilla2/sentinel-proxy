# Invariant Contract v0.1: Velocity Limiter

## 1. Definition
The **Sentinel Hardware** guarantees that the rotational velocity of the target actuator shall never exceed the defined **Safe Operating Limit (SOL)**, regardless of the command received from the upstream Controller (AI/ROS).

## 2. Parameters
| Parameter | Value | Unit | Description |
| :--- | :--- | :--- | :--- |
| `MAX_VELOCITY` | 500 | RPM | The hard ceiling for actuator rotation speed. |
| `LATENCY_MAX` | 100 | µs | Maximum time to process and clamp a command packet. |

## 3. Enforcement Mechanism
* **Input:** Feetech STS `WRITE` command to Register `0x2E` (Goal Speed).
* **Logic:**
    * IF `Goal_Speed` > `MAX_VELOCITY`:
    * THEN Overwrite `Goal_Speed` = `MAX_VELOCITY`.
    * AND Log `VIOLATION_EVENT` to Audit Interface.

## 4. Failure Modes
* **Power Loss:** Actuator bus is tri-stated (Hi-Z); motor halts.
* **Watchdog Timeout:** If Sentinel firmware hangs, hardware watchdog resets device in <10ms.
