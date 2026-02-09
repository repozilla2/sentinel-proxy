Contributing to Sentinel

Sentinel is not just code; it is a safety device.

Contributions are held to a higher standard of rigor than typical open-source projects because changes can invalidate safety evidence and alter physical behavior.

If you are unsure whether a change is safe, do not merge it without running the appropriate verification gates.

⸻

1. Safety Philosophy (Read First)

Sentinel follows an evidence-first safety model:
	•	Safety claims are earned through reproducible tests, not intent.
	•	Code changes invalidate prior safety evidence unless explicitly documented as non-functional (e.g., comments or formatting only).
	•	Verification requirements depend on which subsystem is touched, not on contributor intent.

The authoritative definition of safety invariants and stop behavior lives in:

docs/01-invariant-contract-v0.1.md


⸻

2. Firmware Safety Standards

Code within safety-critical paths (including firmware/, firmware/core, and any future safety_kernel modules) must adhere to the following rules:
	•	No Dynamic Allocation
malloc, new, and standard dynamic string manipulation are forbidden in the runtime safety loop.
Use static buffers and fixed-size data structures only.
	•	Deterministic Execution
No blocking delays, sleeps, or non-deterministic loops inside safety_tick() or equivalent enforcement paths.
	•	Fail-Safe Defaults
All switch statements must include a default case that triggers a SAFE_STOP or emits an explicit error log.
Silent fall-through is not acceptable.
	•	Explicit Typing
Use fixed-width types (uint32_t, int16_t, etc.).
Generic int is discouraged in safety-critical logic.

Violations of these rules will result in the PR being rejected, regardless of functionality.

⸻

3. The Verification Harness (The Gates)

You cannot merge code without proving it maintains safety invariants.

Sentinel uses a gate-based verification ladder.
Not all gates are required for every change — required gates depend on what the change affects.

Core Gates (Currently Enforced)
	•	Gate 0 — Sanity
Must pass:

./harness/gate0_sanity.py

Verifies MCU stability and baseline execution.

	•	Gate 3 — Containment
Must pass:

./harness/gate3_containment.py

Verifies default-deny policy and REWRITE/clamp enforcement behavior.

Important Notes
	•	Gate numbering follows the Sentinel Evidence-First Roadmap (see website and Manifund project).
	•	Parser changes, policy logic changes, or kernel changes may require additional gates (e.g., fuzzing or full re-verification) as defined in CHANGELOG.md.
	•	If a change invalidates previous evidence, that must be stated explicitly in the PR.

⸻

4. Submitting a Pull Request

All pull requests must include the following:
	1.	Context
What safety invariant, SSC rule, or enforcement path does this change touch?
	2.	Evidence
A pasted summary of the relevant gate execution logs (including pass/fail and any metrics).
	3.	Risk Assessment
Does this change invalidate previous fuzzing, containment, or latency evidence?
If yes, specify which evidence must be re-run.

PRs that do not include these three items will not be reviewed.

⸻

5. Scope Discipline

Sentinel is intentionally conservative.
	•	Contributions that add features without evidence will be rejected.
	•	Refactors that reduce clarity or traceability will be rejected.
	•	“Minor” changes that affect safety behavior are not minor.

This is how we maintain trust in a system that controls physical motion.

⸻

6. Questions and Responsible Disclosure

If you are unsure how a change affects safety, ask before coding.

For potential safety or security issues that could enable bypass, wedge, or loss-of-control behavior, please report privately:

keith@invariantgovernor.com

Public disclosure will be coordinated after mitigation and evidence re-verification.

⸻

Thank you for treating Sentinel as a safety system, not a code playground.
