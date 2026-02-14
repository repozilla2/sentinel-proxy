# How to Evaluate Sentinel / Obex (SSC Actuation Clamp v1)

This project is an evidence-first attempt to make actuator-boundary safety claims reproducible rather than narrative.

## What is the claim (v1)?

**Claim:** An SSC-defined Actuation Clamp can deterministically rewrite/clamp out-of-bounds actuator commands on the wire, and produce evidence artifacts that can be independently rerun and inspected.

**Non-claims:** This is not a safety-rated device, not certification, and not a human-safety guarantee.

## What should exist today (public artifacts)

1) **Threat model + claim boundary**
- `docs/PROBLEM.md`

2) **Normative spec**
- SSC v1.1 draft: `docs/ssc/SSC_v1_1.md`

3) **Evidence pack format + sample**
- Evidence packs: `evidence/packs/README.md`
- Sample pack: `evidence/packs/EP-20260211-001.json`

4) **Demo reference**
- Video demo link (repo/website)

## What would convince you this is real?

A. **Reproducibility**
- Evidence Pack contains build ID + config hash + test counts
- A third party can run the harness and generate a comparable pack

B. **Robustness**
- Malformed traffic handling is explicit
- Fuzzing/anti-wedge tests exist
- Wedge count is reported and expected to be zero

C. **Measurement discipline**
- Latency is reported as distributions (P50/P95/P99) within a declared envelope
- Measurement method is explicit (e.g., external logic analyzer RX→TX), not “video verified”

## Key risks to check (and why)

1) **Parser wedge / lock-up**
- If it wedges, it becomes a new failure mode
- Expect explicit anti-wedge tests and watchdog posture

2) **Bypass incentives**
- Drop/stop on every violation encourages workarounds
- Field Mode default is REWRITE-by-default to reduce nuisance trips

3) **Scope creep / overclaiming**
- Look for strict claim discipline and gate-locked “fieldable” features (interlock, tamper resistance, certification)

## What success looks like at the $15k milestone

- SSC v1.1 tagged release (public)
- Conformance Harness v1 tagged release (public)
- Evidence Pack schema + verifier tooling (public)
- At least one “fresh” Evidence Pack produced by the harness under a declared envelope

If these artifacts don’t exist in a reviewable form, the milestone isn’t shipped.

## Where to start (fast path)

1) Read `docs/PROBLEM.md` (2–3 minutes)
2) Skim SSC v1.1 draft (5 minutes)
3) Open the sample evidence pack JSON (2 minutes)
