kb: sofle
km: neonsofle

Flash using the correct command below:

# for pro micro-based builds
qmk flash -kb sofle/rev2 -km neonsoflemac -bl avrdude-split-left
qmk flash -kb sofle/rev2 -km neonsoflemac -bl avrdude-split-right

# for Elite C or dfu bootloader builds
qmk flash -kb sofle/rev2 -km neonsofle -bl dfu-split-left
qmk flash -kb sofle/rev2 -km neonsofle -bl dfu-split-right

These commands can be mixed if, for example, you have an Elite C on the left and a pro micro on the right.

Note: its not recommended to try to use QMK Toolbox
