# Em C
#
# Makefile - Example
# by PUC-Minas - CRC - 2026-1
#
# Usage:
#       make            -> limpa tela, compila, mostra warnings, roda
#       make compile    -> apenas compila
#       make run        -> apenas roda
#       make clean      -> apaga o executavel
#
NAME   = main
EXT    = .c
CC     = gcc
LIBS   = -lm
CFLAGS = -g -Wall -I.

# ---------------------------------------------------------------
# Deteccao do sistema operacional
# ---------------------------------------------------------------
ifeq ($(OS),Windows_NT)
    # Windows
    SHELL   = cmd
    EXEC    = $(NAME).exe
    RUN     = $(EXEC)
    RM      = del /Q
    NULL    = 2>nul
    CLS     = cls
else
    # macOS / Linux
    EXEC    = $(NAME)
    RUN     = ./$(EXEC)
    RM      = rm -f
    NULL    = 2>/dev/null
    CLS     = clear
endif

# ---------------------------------------------------------------
# Alvos
# ---------------------------------------------------------------
# alvo padrao: limpa tela ANTES de compilar, assim warnings ficam visiveis
all:
	@$(CLS)
	@$(MAKE) --no-print-directory clean
	@$(MAKE) --no-print-directory compile
	@$(MAKE) --no-print-directory run

compile: $(NAME)$(EXT)
	@$(CC) -o $(NAME) $(NAME)$(EXT) $(LIBS) $(CFLAGS)

run:
	@$(RUN)
	@$(RM) $(EXEC) $(NULL)

.PHONY: clean
clean:
	@$(RM) $(EXEC) $(NULL)