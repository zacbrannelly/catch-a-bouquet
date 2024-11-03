#!/bin/sh

# Build sprite tile data
python3 scripts/build_gfx.py \
  --image-paths "gfx/spritesheet.png, gfx/puppy.png" \
  --output-base-name gfx \
  --output-dir source

# Build font tile data
python3 scripts/build_font.py \
  --font-path gfx/font.png \
  --output-base-name font \
  --output-dir source

# Generate the menu background tile data
grit gfx/menu.bmp -gt -gB4 -mRtpf -mLs -pn 13

# Copy the source files to the source directory
mv menu.h ./source
mv menu.s ./source

# Generate the game over background tile data
grit gfx/game_over.bmp -gt -gB4 -mRtpf -mLs -pn 14 -ps 2

# Copy the source files to the source directory
mv game_over.h ./source/game_over_gfx.h
mv game_over.s ./source/game_over_gfx.s
