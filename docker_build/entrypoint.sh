#!/bin/bash

echo -e "Which keyboard are planning to update? (e=ergodox, i=id75, p=preonic)"
read keyboard

if [[ "$keyboard" == "e" ]]
then
    echo -e "Flashing \e[1mleft \e[0mhalf of your keyboard. Press enter when ready."
    read ok
    make ergodox_infinity:gbastkowski:dfu-util

    echo -e "Flashing \e[1mright \e[0mhalf of your keyboard. Press enter when ready."
    read ok
    make ergodox_infinity:gbastkowski:dfu-util MASTER=right

    echo -e "Done"
    exit 0
fi

if [[ "$keyboard" == "i" ]]
then
    make idobo:gbastkowski:dfu
    exit 0
fi

if [[ "$keyboard" == "p" ]]
then
    make preonic:gbastkowski:dfu
    exit 0
fi
