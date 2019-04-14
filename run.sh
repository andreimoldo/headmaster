#! /usr/bin/env bash

xinit ./xinitrc -- `which Xephyr` :1 -screen 800x600 -host-cursor -ac
