#!/usr/bin/env bash
set -o errexit \
    -o nounset \
    -o pipefail

source='TesterFont.fontsrc/TesterFont.cpp'
destination='TesterFont.h'
sketch='FontTester.ino'

patch_font(){
  sed \
    -e '/^#.*$/d' \
    -e 's@^    \(.*_bitmap,\)$@    (uint8_t  *)\1@' \
    -e 's@^    \(.*glyphs,\)$@    (GFXglyph  *)\1@' \
    "$source" \
    > "$destination"
}

push_sketch(){
  /Applications/Arduino.app/Contents/MacOS/Arduino --upload "$sketch"
}

patch_font
push_sketch