# Em C++
#
# Makefile - Example
# by PUC-Minas - CRC - 2026-1
#
# Usage:
#       make
#       make -f Makefile
#       make compile
#       make run
#       make clean
#
NAME   = main
CC     = g++
EXT    = .cpp
LIBS   = -lm
CFLAGS = -g -Wall -I.
SHELL  = cmd

all: backup compile run clean

backup:
	copy $(NAME).cpp $(NAME).bak

compile:
	$(CC) -o $(NAME) $(NAME)$(EXT) $(LIBS) $(CFLAGS)
# pause

run:
	@cls
	@$(NAME).exe
	@cls

.PHONY: clean
clean:
	@del /Q $(NAME).exe 2>nul
	@del /Q $(NAME).bak 2>nul