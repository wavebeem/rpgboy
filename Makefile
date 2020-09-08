BOARD = arduboy:avr:arduboy
PORT = /dev/cu.usbmodem14101
FILE = $(PWD)/rpgboy.ino

install:
	arduino-cli compile -u -b $(BOARD) -p $(PORT)

images:
	arduboy image tobytes --input=src/sprite_slime1.png > src/sprite_slime1.cpp
	arduboy image tobytes --input=src/sprite_slime2.png > src/sprite_slime2.cpp

.PHONY: install
