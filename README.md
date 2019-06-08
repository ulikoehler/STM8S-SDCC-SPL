# STM8S-SDCC-SPL
STM8S Standard peripheral library for SDCC, split into individual files for small binaries.

*Note:* SDCC 3.4.3+ is required!

This work is heavily based on [STM8-SPL-SDCC](https://github.com/ulikoehler/STM8S-SDCC-SPL), intending to fix the following issues with it:

* SDCC 3.5.x on Ubuntu 18.04 is not recognized properly and produces *#error traps require SDCC >=3.4.3*
* The original repository contains much more than the neccessary files in `inc` and `src`, including docs as `.chm` etc.
* There are various other (non-critical) warning messages

My goal with this repository is to provide minimal source code for the SPL that can be used in SDCC without producing huge binaries (because SDCC at least up to 3.5.x does not support dead code removal, i.e. it will not remove functions that you don't use).

Also see my [SDCC STM8 CMake configuration blogpost](https://techoverflow.net/2019/06/08/a-working-sdcc-stm8-cmake-configuration/) and my [demo project](https://github.com/ulikoehler/stm8s-discovery-sdcc-blink) which includes demos both with and without SPL.

*Note*: The SPL demo is not available *yet*!

## How to use

*Note:* This repo was tested with SDCC 3.5.x on Ubuntu 18.04. If you really need to use older SDCC versions and they don't work, please submit a bug report or preferably a pull request.

Add `STM8S-SDCC-SPL/conf` and `STM8S-SDCC-SPL/inc` to the include path of your build system.

First, you need to define your STM8S model using the preprocessor. I recommend using a flag like `-DSTM8S105`. See `conf/stm8s_conf.h` for all the available models.

Each function has its separate file so your resulting binary doesn't get unneccessarily large. The include files declare all functions for that module, however, and `stm8s.h`.
So in order to use e.g. `CLK_HSIPrescalerConfig()`, you need to include `stm8s_clk.h` and compile in `stm8s_clk_HSIPrescalerConfig.c`.

The best way to use this library is to compile a library from all the source files and then link that library in SDCC. SDCC will only pull in what functions it needs.
See the [demo project](https://github.com/ulikoehler/stm8s-discovery-sdcc-blink) for an example on how to do that.

*Note:* This example is not yet available.

## LICENSE

This work, just like the works it is based on, is licensed under the MCD-ST Liberty Software license agreement. See `LICENSE.pdf` for details.