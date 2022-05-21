# Microwalk Pin GitHub Workflow Example

This repository features a simple example for running the Microwalk GitHub analysis workflow with C code.

It makes use of [microwalk-pin-action](https://github.com/microwalk-project/microwalk-pin-action) to analyze the targets `microwalk/target-*.c` and generate a leakage report.

The target code calls functions from our `libexample` library, as defined in the [src](src) folder. In the `master` branch, those are empty and thus constant-time. In the example pull request ["#1 Add leakage"](https://github.com/microwalk-project/example-c/pull/1) (for branch `add-leakage`), the functions are filled with leaking code, that is subsequently detected by the Microwalk analysis.

The SARIF-formatted leakage report is sent back to GitHub and displayed both in the pull request UI (for everyone) and in the repository's "Security" tab (for users with write access only).
