#!/bin/sh

# Build the spritesheet
grit gfx/spritesheet.png -gt -gB8 -Mh4 -Mw2 -m! -gTFF00FF

# Copy the source files to the source directory
mv spritesheet.h ./source
mv spritesheet.s ./source

# Generate the menu background tile data
grit gfx/menu.bmp -gt -gB4 -mRtpf -mLs

# Copy the source files to the source directory
mv menu.h ./source
mv menu.s ./source
