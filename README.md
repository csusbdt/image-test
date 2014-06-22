image-test
==========

## Overview

This is a temporary project to compare the quality of image and text rendering
of various approaches for the purpose of build visual novels.

This project will compare the following three frameworks:

(1) SDL2 texture API with SDL_image and SDL2_ttf.
(2) Web browser.
(3) Unity.
(4) Other.

## Status

__(1) SDL2 texture API with SDL_image and SDL2_ttf.__

The code is in the folder sdl2.  There is currently a build script to build
for OS X and an OS X executable a.out.  It needs a build script for Windows
and a Windows executable.

__(2) Web browser.__

The code is in the folder web.  To run, open index.html in a browser.

__(3) Unity.__

This needs to be done.

__(4) Other.__

I'd like to get stb_truetype.h working with subpixel rendering.
I'd also like to try using OpenGL in place of the SDL texture API.

## Results

Compared to SDL, text renders much more nicely by browsers.

Also, browsers scale images better.

