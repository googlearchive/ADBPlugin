#!/bin/bash

BASEDIR=`dirname "$0"`

chmod +x "$BASEDIR/adb"
#echo $@
"$BASEDIR/adb" $@