#!/bin/sh

BIN=ienum_test

gcc -std=c89 -ansi -pedantic -Wall -I.. \
   -o "$BIN" \
   "$BIN".c \
   my_enum.c \
   other_enum.c \
    && ./"$BIN"