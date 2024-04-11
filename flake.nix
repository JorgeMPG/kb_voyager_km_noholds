{
  description = "Devshell for QMK configs";

  inputs.devshell.url = "github:numtide/devshell";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, flake-utils, devshell, nixpkgs, ... }:
    flake-utils.lib.eachDefaultSystem (system: {
      devShells.default =
        let
          pkgs = import nixpkgs {
            inherit system;
            overlays = [ devshell.overlays.default ];
          };
          
        in
        pkgs.devshell.mkShell {
          name = "qmk-shell";
          packages = with pkgs; [
            qmk
          ];

          commands = [
            {
              name = "new-layout";
              command = ''
                CURRENT_DIR="$PWD"
                qmk new-keymap
                IFS='=' read CONF_KEY KEYBOARD < <(qmk config user.keyboard)
                IFS='=' read CONF_KEY KEYMAP < <(qmk config user.keymap)
                KEYMAPS_FOLDER="~/lab/qmk_firmware_zsa/keyboards/$KEYBOARD/keymaps"
                mv "$KEYMAPS_FOLDER/$KEYMAP" "$CURRENT_DIR/$KEYMAP" 
                cd "$KEYMAPS_FOLDER"
                ln -s "$CURRENT_DIR/$KEYMAP"
                cd "$CURRENT_DIR"
              '';
              category = "qmk";
              help = "Create a new keymap using the defaul keyboard and keymap";
            }
            {
              name = "compile";
              command = "qmk compile";
              category = "qmk";
              help = "Compile default layout for default keyboard";
            }
            {
              name = "compile-zsa";
              command = "qmk compile -kb voyager -km default";
              category = "qmk";
              help = "Compile the zsa default layout for voyager";
            }
            {
              name = "compile-noholds";
              command = "qmk compile -kb voyager -km noholds";
              category = "qmk";
              help = "Compile 'noholds' custom layout for voyager";
            }
            {
              name = "set-qmk-home";
              command = "qmk config user.qmk_home=\"~/lab/qmk_firmware_zsa/\"";
              category = "qmk-config";
              help = "Set the qmk home to the qmk_firmware folder under ~/lab";
            }
            {
              name = "default-qmk-kb-voyager";
              command = "qmk config user.keyboard=voyager";
              category = "qmk-config";
              help = "Select 'voyager' as the default keyboard";
            }
            {
              name = "default-qmk-km-noholds";
              command = "qmk config user.keymap=noholds";
              category = "qmk-config";
              help = "Select 'noholds' as the default keymap";
            }
          ];
        };
    });
}
