# pihpsdr

This is a modified version by DL1BZ of pihpsdr from https://github.com/dl1ycf/pihpsdr with activated CFC and optimization for macOS
The CFC activation and it's configuration profile is only hard-coded in the src/transmitter.c at this time.

***

**If you encounter problems with "pulling", look at this:** https://github.com/dl1ycf/pihpsdr/releases/download/v2.3/RenewRepo.pdf


**piHPSDR Manual:** https://github.com/dl1ycf/pihpsdr/releases/download/v2.3/piHPSDR-Manual.pdf

Standalone code for HPSDR,
supporting both the old (P1) and new (P2) HPSDR protocols, as well as the SoapySDR framework.

It runs on Linux (including RaspPi 3/4/5) and MacOS (using the "Homebrew" working environment).

***
Consult the Manual (**link given above**) on how to compile/install piHPSDR on your machine

-Appendix J: LINUX compile from sources (including RaspPi)

-Appendix K: MacOS compile from sources
***

Latest features:

- in-depth manual (**link given above**)
- HermesLite-II I/O-board support
- audio recording (RX capture) and playback (TX)
- repository shrinked quite a bit by removing some binary files (much better now if you use WLAN)
- automatic installation procedures for compilation from the sources, for Linux (including RaspPi) and MacOS
  (Appendix J, K).
- dynamic screen resizing in the "Screen" menu, including transitions
  between full-screen and window mode
- CW audio peak filter (in the Filter menu)


