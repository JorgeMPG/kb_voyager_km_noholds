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

## Design decissions
This is an evolution of my layout for the Moonlander keyboard. The guiding principles are similar:

### 1. Mirror halves
I like having all non-alpha keys available for both hands.
It started with the OSL layer for mods, where it seemed useful to have replicated so one could `Alt-Tab`/`Cmd-Tab` or `\-<number>` (switch to <number> window in my tmux) with either hand, as I switch mouse use from right hand to left every couple of weeks. It then grew to include the number layer, as I would randomly pick up my phone with either hand to look up One Time Codes from my authenticator app. It is great to be able to just reach to the keyboard with whatever hand is free and bring up the numpad. Then, I found myself annoyed that some symbols required a given hand, so I mirrored that as well. Eventually, all layers were duplicated to have a mirrored version. I find this very convenient. My brain seems better able to remember the relative position of the keys and switch hands on the fly rather than remembering key associations to a given hand.
This has some big drawbacks. First, it duplicates the number of layers, which may make the binary too big to flash to certain controllers. It also restricts the available space for keys. You have to fit everything for the layer on one half. I get some use of the other half by replicating the mod layer there, but I don't put overflow keys there, as the idea is to avoid requiring both hands on the keyboard for a symbol, number, arrow press.
Overall, I find it convenient, so most keys are mirrored. Just the alphas remain, which I may attempt in the future to be able to type one-handed. But that's a bridge too far for now.

### 2. Reduce hold keys
Pain in my pinky pushed me to enable sticky mods (at the OS level) to combat that by requiring just a tap on Shift, Ctrl, Cmd. Programable keyboards freed my pinkies from mod duties, but I found it increasingly uncomfortable to hold down the thumb, especially on thumb keys to the outside of the rest possition. After some experimentation, I found it easier to tap more instead of holding keys down. Thus modifiers now live mainly on a OSL accesible with a thumb tap. This transforms all mods into a two-key press. For me, the tradeoff is worth it as my pinky and thumb pain is gone.
Incidentally, this is the reason I started this repo. My layout uses one-shot modifiers on a one-shot layer. Recent updates to QMK fixed the OSM to not trigger OSL reset, as a tap should be considered a hold that should modify the 'real' key press on the layer. But my use case relies on a tap to a OSM reverting the OSL to the base layer for the next, modified key press. Luckily, this functionality can be mimicked with a custom check in `post_process_record_user` (thanks to [KoFish](https://github.com/KoFish) for this workaround in response to https://github.com/qmk/qmk_firmware/issues/22566 ).

Disable OSL on OSM tap:
```c
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_ONE_SHOT_MOD(keycode) && is_oneshot_layer_active() && record->event.pressed) {
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    }
    return;
}
```

