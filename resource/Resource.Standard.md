# Resource Standard for GalEngine
To make sure every thing inside the engine running as its design, developers should follow this standard.

## Table of Contents

- [Font](#font)
- [Image](#image)
- [Music](#music)

## Font

Font file must be like formats in list below.

- TrueType
- Type 1
- CFF
- OpenType
- SFNT
- X11 PCF
- Windows FNT
- BDF
- PFR
- Type 42

Font encode must be utf-8 or utf-32. In our engine, unicode string are widely used.

## Image

Image file must be like formats in list below.

- bmp
- png
- tga
- jpg
- gif
- psd
- hdr
- pic
- pnm

Image file formats in list below are **not supported**.

- jpeg with arithmetic coding
- ASCII pnm

## Music

Sound file must be like formats in list below.

- WAV (PCM only)
- OGG/Vorbis
- FLAC
- MP3