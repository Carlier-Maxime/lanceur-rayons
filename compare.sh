#!/bin/bash

MY_PATH=$(dirname "$0")

"$MY_PATH"/bin/compareImage "$MY_PATH"/"$1" "$MY_PATH"/"$2"
