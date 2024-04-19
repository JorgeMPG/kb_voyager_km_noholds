# The 'noholds' Voyager keymap
QMK keymap for the ZSA Voyager keyboard that focuses on one-shot modifiers and layers to avoid key holds.

NOTE: Work in progress!

## Why

[<img alt="XKCD 1172: Workflow" align="right" src="https://imgs.xkcd.com/comics/workflow.png">](https://xkcd.com/1172)

The latest update to the Oryx configurator has pulled in a fix for one-shot layers that breaks my setup.

I put my one-shot modifiers on the one-shot layer. I could tap OSL, tap a OSM and be back on the base layer for the next key press, that would fire with the modifier applied. This has been fixed so that tapping a OSM does not register as a key press that disables the OSL. While the fix makes sense for the concept of a OSL, it makes it hard to apply an OSM to a key on the base layer without holding. So instead of figuring out a different approach to my keymap and be happy with Oryx, Keymapp and all that ZSA goodness, I've opted for 'fixing' the fix on a custom layout thanks to the QMK project (and ZSA's commitment to open source firmware for their keyboards).

<br clear="right"/>

## Use
It requires the qmk fork by zsa (or the qmk firmware repo once the Voyager keyboard has been added).
1. Clone the qmk_firmware repository locally.
2. Link the 'noholds' folder from 'qmk_firmware/keyboards/voyager/keymaps'.
3. Compile the keymap.
4. Flash the compiled keymap to a voyager keyboard.
