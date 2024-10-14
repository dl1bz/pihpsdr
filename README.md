# pihpsdr

CFC patch by DL1BZ

This is a modified version by DL1BZ of pihpsdr from https://github.com/dl1ycf/pihpsdr with activated CFC and some small optimization for macOS. 

The CFC activation and it's configuration profile is only hard-coded in the src/transmitter.c, no access from GUI at this time.
CFC function can be activated if set `#define USE_CFC` at begin of file transmitter.c and will be only ON if TX-EQ is ON.
Look into transmitter.c in the function tx_set_equalizer(TRANSMITTER *tx) for adjust the CFC by yourself.
I add a lot of comments for understand how you need to do. The CFC is part of the WDSP library, but up to my patch piHPSDR don't use it.
For understand: CFC = Continuous Frequency Compressor = Multiband-Compressor, which can selective compress different AF frequencies more or less.
That can be produce in addition a more accurate TX SSB audio like only a plain overall compressor.

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


