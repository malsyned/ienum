#!/bin/sh

BIN=ienum_test

gcc -Wall -o "$BIN" \
   "$BIN".c \
   my_enum.c \
   other_enum.c \
    && ./"$BIN"
