# Reproduce an Evidence Pack in ~5 minutes (TRL-4 bench)

Goal: generate a valid Evidence Pack JSON that conforms to `evidence/schema.json`.

## Prereqs
- Python 3.10+
- Repo cloned
- A bench setup OR run in “simulated injection” mode

## Steps
1) Clone:
   git clone https://github.com/repozilla2/sentinel-proxy
   cd sentinel-proxy

2) Validate the sample pack (schema-only check):
   - Open `evidence/schema.json`
   - Open `evidence/packs/EP-20260211-001.json`
   - Confirm required fields exist:
     firmware_build_id, config_hash, enforcement_count, wedge_count, latency_distribution

3) Generate a new pack (placeholder generator)
   - Copy the sample pack:
     cp evidence/packs/EP-20260211-001.json evidence/packs/EP-YYYYMMDD-TEST.json
   - Replace:
     - build_id / timestamp
     - trial_count / enforcement_count
     - latency_distribution values (if measured)

4) What “success” looks like
- File exists under `evidence/packs/`
- Fields match schema
- wedge_count = 0 (or explicitly explained)

## Notes
- Video is illustrative; timing claims should be measured externally (logic analyzer RX→TX).
- This is evidence-scoped and not a certification claim.
