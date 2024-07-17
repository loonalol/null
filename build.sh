#!/bin/bash
INCLUDE_LOCATION="/opt/homebrew/include"
LIB_LOCATION="/opt/homebrew/lib"
gcc main.c ./window/render.c -o main -I"$INCLUDE_LOCATION" -L"$LIB_LOCATION" -lglfw -framework OpenGL
