# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

---

## ⚠️ Verification Invalidation Policy

**Critical:** This project is evidence-driven. Code changes invalidate previous safety evidence unless explicitly marked as **documentation-only**.

Documentation-only changes are limited to comments, markdown, formatting, or non-functional text that does **not** alter execution, configuration, or safety semantics.

Use the following tags to determine required re-verification:

* `[⚠️ RE-RUN: G2]` — Protocol parser changed. Re-run fuzzing & MITM soak tests.
* `[⚠️ RE-RUN: G3]` — Policy logic changed. Re-run conformance suite.
* `[⚠️ RE-RUN: ALL]` — Core kernel or hardware change. Full system re-verification required.

---

## [Unreleased]

### Added
* `[⚠️ RE-RUN: ALL]` Initial public release of TRL-4 firmware kernel.
* Implemented **Rewrite/Clamp** enforcement strategy for FeeTech STS3215.
* Added Gate 0 (MCU sanity) and Gate 1 (plant characterization) Python harness.
* Dual-license structure: Apache 2.0 (software) + CERN-OHL-P-2.0 (hardware).

### Security
* Established **Default Deny** command allowlist architecture.
