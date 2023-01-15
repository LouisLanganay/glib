##
## EPITECH PROJECT, 2023
## glib
## File description:
## Makefile
##

include Makefile_colors.mk

NAME = libgl.a


VPATH := ./window
VPATH += ./events
VPATH += ./buttons

vpath %.c $(VPATH)

SRC := gl_create_window.c
SRC += gl_create_event.c
SRC += gl_check_events.c
SRC += gl_create_button.c
SRC += gl_draw_button.c
SRC += gl_buttons_hovered.c
SRC += gl_button_change_state.c



INC_DIR := ../../includes
INC_NAME := gl.h
BUILD_DIR = build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)
	@ echo -e "${_B_GREEN}[SUCCES]${_END} Compilation done"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) $(LIBFLAGS) -c $< -o $@
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(CC)    $<${_END}"

$(NAME): $(OBJ) $(SRC)
	@ mkdir -p $(BUILD_DIR)
	@ ar rc $(NAME) $(OBJ)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(AR)    $(NAME)${_END}"
	@ cp ${INC_NAME} ${INC_DIR}
	@ echo -e "${_BLACK}${_BB_WHITE}-> cp      ${INC_NAME} ${INC_DIR}${_END}"

clean:
	@ $(RM) *.gcda
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcda${_END}"
	@ $(RM) *.gcno
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcno${_END}"
	@ $(RM)	$(OBJ)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(OBJ)${_END}"
	@ echo -e "${_B_RED}[CLEAN]${_END} Clean done"

fclean: clean
	@ $(RM) -r $(BUILD_DIR)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(BUILD_DIR)${_END}"
	@ $(RM)	$(NAME)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(NAME)${_END}"
	@ echo -e "${_B_RED}[FCLEAN]${_END} Fclean done"

re: fclean all

.PHONY: clean fclean re
