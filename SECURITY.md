Security Policy

Sentinel is a safety-critical system.
Security vulnerabilities are treated as safety issues when they could enable loss of control, bypass of enforcement, or invalidation of safety evidence.

⸻

Reporting a Vulnerability

If you discover a vulnerability that could affect physical safety, containment, or evidence integrity, please report it privately.

This includes (but is not limited to):
	•	Bypass of rewrite/clamp logic or policy enforcement
	•	Crashing or wedging the interposer into an unsafe state (DoS)
	•	Spoofing or confusing telemetry or Independent Witness inputs
	•	Circumventing Field Mode or other physical enforcement mechanisms
	•	Any issue that invalidates published safety evidence without detection

Do not open a public GitHub issue for safety or security bypasses.

Please report findings to:

📧 security@invariantgovernor.systems

Include, where possible:
	•	A clear description of the issue
	•	A minimal reproduction method
	•	Which gate(s) or safety layer(s) are affected
	•	Any evidence that existing verification would fail to detect the issue

⸻

Coordinated Disclosure

We follow a coordinated disclosure model appropriate for safety-critical systems.
	•	We aim to acknowledge reports within 48 hours
	•	We will coordinate a disclosure timeline, typically up to 90 days, to allow investigation, remediation, and evidence re-verification
	•	Public disclosure will occur only after mitigations are in place and affected evidence has been invalidated or re-issued

Timelines may be adjusted if an issue presents an immediate physical safety risk.

⸻

Research & Testing Policy

We explicitly encourage constructive safety research.

If you can demonstrate a credible method to:
	1.	Bypass rewrite/clamp enforcement
	2.	Induce an unsafe or wedged execution state
	3.	Evade or spoof telemetry or Independent Witness validation
	4.	Invalidate safety evidence without triggering re-verification

…we want to know.

Findings that materially improve Sentinel’s safety posture may be credited in documentation or changelogs, subject to responsible disclosure practices.

⸻

Scope Notes
	•	Sentinel does not currently operate a public bug bounty program.
	•	This policy applies to software, firmware, and hardware interaction surfaces.
	•	Issues affecting only documentation or non-functional content should be reported via normal GitHub issues.

⸻

Philosophy

Sentinel’s security posture exists to support a single goal:

Make unsafe physical behavior impossible — and make safety claims auditable.

Thank you for helping us treat security as part of safety, not an afterthought.
