# Evidence Packs

This directory contains sample and future Evidence Packs (EP-*), which are machine-readable artifacts intended to make actuator-boundary safety claims reproducible and comparable.

## What an Evidence Pack contains

- Build metadata (firmware build ID, commit hash, config hash)
- SSC contract reference (caps, mode semantics)
- Conformance test results (including malformed traffic + fuzzing/anti-wedge)
- Performance reporting as distributions (P50/P95/P99) within a declared envelope
- Integrity tooling fields (hash-chain + verifier) when enabled

## Sample pack

- `EP-20260211-001.json` — sample format for review (contains placeholders for measured values)

## Notes

- Video is illustrative; timing claims should be measured externally (e.g., logic analyzer RX→TX).
- Evidence Packs are evidence-scoped and do not imply certification.
