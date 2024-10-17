#!/bin/sh

# Build sprite tile data
python3 scripts/build_gfx.py \
  --image-paths "gfx/spritesheet.png, gfx/puppy.png" \
  --output-base-name gfx \
  --output-dir source

# Generate the menu background tile data
grit gfx/menu.bmp -gt -gB4 -mRtpf -mLs

# Copy the source files to the source directory
mv menu.h ./source
mv menu.s ./source
