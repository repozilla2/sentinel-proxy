Evidence Philosophy — SSC / Obex (Invariant Governor Systems)

Why Evidence Comes First

SSC + Obex are a conformance and enforcement stack, not an algorithmic feature.

In safety-critical systems, claims without reproducible evidence are liabilities.
Our approach is to treat evidence as a first-class artifact, not an afterthought.

We do not claim “safety.”
We publish what we tested, how we tested it, and what the results support.

⸻

The Core Principle

If a third party cannot independently reproduce the conformance claim, the claim does not count.

This principle governs:
	•	code changes
	•	releases
	•	public statements
	•	funding milestones

⸻

What Counts as Evidence

For SSC/Obex, evidence consists of:
	1.	Frozen Code State

	•	A tagged release (e.g., v0.1.5-frozen)
	•	No post-hoc modification

	2.	Reproducible Tests

	•	Deterministic harness scripts
	•	Explicit gate definitions

	3.	Raw Logs

	•	Unfiltered event records
	•	No hand-picked metrics

	4.	Derived Metrics

	•	Distributions (P50 / P95 / P99)
	•	Never a single “best-case” number

	5.	Context

	•	Actuator class
	•	Test configuration
	•	Scope of supported claims

⸻

The Gate Model

We advance conformance claims through explicit gates:
	•	Gate 0–3: TRL-4 (bench containment)
	•	Gate 4: TRL-5 (telemetry witness)
	•	Gate 5–6: fieldable posture + SSC-P1 compatibility
	•	Gate 7: TRL-6 (independent witness)

Each gate:
	•	expands what may be claimed
	•	invalidates prior evidence if code changes

⸻

Evidence Invalidation

Any code change that affects:
	•	protocol parsing
	•	enforcement logic
	•	timing behavior
	•	hardware interfaces

automatically invalidates prior evidence.

This is enforced via:
	•	CHANGELOG re-run tags
	•	frozen evidence directories
	•	release discipline

⸻

Why This Matters to Funders

This project is structured so that:
	•	funding produces public artifacts, not promises
	•	progress is auditable by independent reviewers
	•	downstream certification efforts are not blocked by missing groundwork

Funding SSC/Obex is funding:

a reusable conformance and evidence engine for actuator-boundary enforcement in embodied AI

⸻

What SSC/Obex Does Not Do
	•	It does not certify robots
	•	It does not guarantee human safety
	•	It does not replace mechanical design or risk analysis

It enforces deterministic actuator-boundary constraints and publishes reproducible evidence of conformance.

⸻

⸻

What changed (so you can keep it consistent everywhere)
	•	Replaced Sentinel with SSC/Obex (standard + reference implementation).
	•	Tightened “safety claim” → “conformance claim” in the core principle (this matters).
	•	Replaced “reduces risk” language with “enforces constraints + publishes evidence” (less liability, more precise).
