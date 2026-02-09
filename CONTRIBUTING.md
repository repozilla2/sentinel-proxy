# Contributing to Sentinel

Sentinel is not just code; it is a safety device. Contributions are held to a higher standard of rigor than typical open-source projects.

## 1. Firmware Safety Standards
Code within the `firmware/core` and `safety_kernel` directories must adhere to strict safety patterns:
* **No Dynamic Allocation:** `malloc`, `new`, and standard string manipulation are strictly forbidden in the runtime loop. Use static buffers.
* **Deterministic Execution:** No blocking delays or non-deterministic loops inside the `safety_tick()`.
* **Fail-Safe Defaults:** Switch statements must always have a `default` case that triggers a `SAFE_STOP` or error log.
* **Explicit Typing:** Use `uint32_t`, `int16_t`, etc., not generic `int`.

## 2. The Verification Harness (The Gates)
You cannot merge code without proving it maintains safety invariants.
* **Gate 0 (Sanity):** Must pass `./harness/gate0_sanity.py` (MCU stability).
* **Gate 3 (Containment):** Must pass `./harness/gate3_containment.py` (Policy enforcement).

## 3. Submitting a Pull Request
All PRs must include:
1.  **Context:** What safety invariant does this touch?
2.  **Evidence:** A pasted summary of the relevant Gate execution logs.
3.  **Risk Assessment:** Does this change invalidate previous fuzzing results?
