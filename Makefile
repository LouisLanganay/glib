##
## EPITECH PROJECT, 2023
## glib
## File description:
## Makefile
##

NAME = main
CC = gcc

VPATH := src

vpath %.c $(VPATH)

SRC := main.c

INC_DIR := includes
LIB_DIR := ./lib/gl
LIB_NAME := gl
CFLAGS = -iquote $(INC_DIR) -L$(LIB_DIR) -l$(LIB_NAME) -g \
		-l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio
LIBFLAGS = -lgl

BUILD_DIR = build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)
	@ echo "Compilation done"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ make -s -C ${LIB_DIR}
	@ $(CC) $(CFLAGS) $(LIBFLAGS) -c $< -o $@
	@ echo "$(CC)    $<"

$(NAME): $(OBJ) $(SRC)
	@ mkdir -p $(BUILD_DIR)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS)

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@ $(RM)	$(OBJ)

fclean: clean
	@ make fclean -s -C $(LIB_DIR)
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM)	$(NAME)
	@ $(RM) $(UNIT)

re: fclean all

.PHONY: clean fclean re
