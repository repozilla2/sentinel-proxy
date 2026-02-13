# The Actuator-Boundary Safety Problem

## Summary

When an AI/ROS/planner stack gains authority to issue actuator commands,
failures become motion.

Most safety mechanisms in embodied systems operate at higher layers:
- Prompt constraints
- Policy nodes
- Behavior trees
- Runtime monitors on the same compute

These share failure modes with the upstream controller.

Sentinel addresses a narrower question:

> What enforces physical limits if upstream software is wrong, compromised, or adversarial?

---

## Threat Model

We assume:

1. Upstream compute can:
   - Miscalculate
   - Hallucinate
   - Be misconfigured
   - Crash or wedge
   - Be adversarially prompted
   - Be compromised

2. Actuator commands are transmitted over a bus (e.g., UART/CAN/etc).

3. The actuator will execute any syntactically valid command it receives.

We do **not** assume:
- Malicious hardware tampering
- Mechanical design failures
- Sensor spoofing
- Human misuse
- Certification compliance

This is not a full safety system.
It is a boundary enforcement layer.

---

## The Black Box Control Gap

In most ROS systems:

AI → Controller → Driver → Actuator

There is no independent deterministic boundary between "intent" and "motion".

If limits exist, they are often:
- Soft
- Software-only
- Co-resident with the planner
- Not reproducibly tested
- Not auditable by third parties

This creates a gap:

> Safety claims at the actuation boundary are often narrative, not reproducible.

---

## Sentinel’s Narrow Claim

Sentinel does NOT claim:

- Alignment
- Human safety
- Certification compliance
- Full-system security

Sentinel claims:

1. Out-of-bounds actuator commands are clamped deterministically.
2. Enforcement events are logged.
3. Behavior is testable via a conformance harness.
4. Evidence artifacts can be reproduced independently.

If this claim cannot be reproduced, it does not count.

---

## Why This Layer Might Matter

As embodied systems scale:

- Model robustness improves
- Planning improves
- Capability increases

But authority over motion increases as well.

If actuator-boundary invariants are not standardized early,
deployment norms may form without reproducible enforcement.

Sentinel explores whether:

> "Actuator safety evidence" can become a standard artifact in embodied AI research.

---

## Open Questions

- Is this layer leverageful relative to perception or planning risks?
- Does REWRITE-by-default meaningfully reduce bypass incentives?
- What would make an enforcement harness credible to you?
- What prior art should this integrate with?

Feedback welcome.
