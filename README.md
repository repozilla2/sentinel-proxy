Sentinel — Physics Firewall (IGS)

Status: v0.1.5 — Frozen Master (Evidence Baseline)
License: MIT
Hardware Target: Teensy 4.1 + Feetech STS3215 Servo

“The AI can hallucinate all it wants. The physics will not comply.”

What this is

Sentinel is an open-source Physics Firewall for robotics.
It is a hardware interposer that sits between an upstream controller (including AI/LLM-based systems) and a physical actuator, enforcing non-negotiable safety invariants in real time.

Sentinel does not try to make AI smarter.
It makes unsafe physical commands impossible.

What it does (v0.1)
	•	Observes actuator commands on the serial bus
	•	Detects violations of a defined invariant (velocity limit)
	•	Clamps unsafe commands to a safe value before they reach the motor
	•	Emits a forensic log and a visible alert when an intervention occurs

What it is not
	•	Not AI alignment
	•	Not software guardrails
	•	Not multi-joint control (yet)
	•	Not a safety certification claim

Architecture (hardware interposer)

[ Untrusted Controller / AI ]
           |
       USB Serial
           |
     [ Sentinel ]
           |
     1-Wire UART
           |
      [ Actuator ]

Sentinel does not originate commands. It only observes, validates, and conditionally modifies commands already in flight.

Current invariant (v0.1)
	•	MAX_SPEED clamp on WRITE commands to the actuator target position register

Future versions extend to additional invariants (e.g., torque limits, keep-out constraints).

Reproducibility & safety

All tests are performed with a fixed procedure and documented artifacts.
Physical tests must follow the Safety Protocol defined in the invariant contract.

Documentation (authoritative)
	•	Invariant Contract (v0.1): docs/01-invariant-contract-v0.1.md
	•	Test Matrix (v0.1): docs/02-test-matrix-v0.1.md
	•	Evidence Pack (v0.1): docs/03-evidence-pack-v0.1.md
	•	Assets (logs, media): docs/assets/

Repository layout

sentinel/
├─ firmware/        # Teensy firmware (enforcement logic)
├─ tools/           # Test harness / attack generator
├─ hardware/        # PCB & wiring (future)
└─ docs/            # Contracts, tests, evidence

License

MIT — intended for broad adoption across makers, labs, and integrators.

⸻

Invariant Governor Systems (IGS)
Open-source hardware enforcement for actuator safety.

⸻
