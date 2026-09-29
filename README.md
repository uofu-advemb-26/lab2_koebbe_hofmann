# advemb26_lab2_koebbe_hofmann

Lab 2: Writing testable code.

## What the firmware does
- **LED blink**: the on-board LED toggles every 500 ms, except once every 11
  iterations, which gives one 1 s OFF gap every 5.5 s.
- **Serial case swap**: each character typed over USB serial is echoed back
  with its letter case swapped (`Hello` → `hELLO`).
