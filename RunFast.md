VFP11 works in IEEE-754 full compliance mode, unless RunFast mode is enabled.
RunFast is enabled by default by iPhoneOS, QNX, and possibly other operating systems.

To enable it manualy, you must alter the FPSCR register:
  * Set its bit 24 (Flush-To-Zero mode),
  * Set its bit 25 (Default NaN mode),
  * Clear bits 8,9,10,11,12 and 15 (exception bits).

In RunFast mode, the VFP11:
  * Treats subnormal inputs as positive zeros,
  * Treats outputs that are tiny as positive zeros,
  * Treats NaN as default NaNs,
  * Returns the default result as specified per ieee-754 for overflow, division by zero and invalid or inexact operation conditions, with no additional latency
  * Process everything in hardware, without trapping to the OS.