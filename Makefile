# C Compiler (Clang-12)
CC := clang
# PipeX Variables
NAME := push_swap
NAME_BONUS := .push_swap_bonus.txt
INC_DIR := includes
OBJS_DIR := objects
BONUS_OBJS_DIR := bonus_objects
MANDATORY_DIR := mandatory
BONUS_DIR := bonus
# Libft Variables
LIBFT_DIR := libft
LIBFT := libft.a

CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(INC_DIR) -g3
ifdef DEBUG
	CFLAGS += -D DEBUG=1
endif
SRCS = $(addprefix $(MANDATORY_DIR)/, main.c\
		parameters_validation.c\
		has_repeat.c\
		swap_operations.c\
		push_operations.c\
		rotate_operations.c\
		reverse_rotate_operations.c\
		utils_operations.c\
		init_stack_a.c\
		sort_stacks.c\
		sort_utils.c\
		init_stack_b_vars.c\
		calculate_movements_a.c\
		calculate_movements_b.c\
		init_movements.c\
		apply_movements.c\
		apply_rotations.c\
		apply_reverse_rotations.c\
		free_hash_table.c\
		debug.c\
		)

BONUS = $(addprefix $(BONUS_DIR)/, main_bonus.c\
        		)

OBJS = $(patsubst $(MANDATORY_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
BONUS_OBJS = $(patsubst $(BONUS_DIR)%.c, $(BONUS_OBJS_DIR)%.o, $(BONUS))
# All Src subdirectories
SRC_SUBDIR := $(shell find $(MANDATORY_DIR) -type d)
BONUS_SUBDIR := $(shell find $(BONUS_DIR) -type d)
# Objects Subdirectories
OBJS_SUBDIR := $(subst $(MANDATORY_DIR), $(OBJS_DIR), $(SRC_SUBDIR))
BONUS_OBJS_SUBDIR := $(subst $(BONUS_DIR), $(BONUS_OBJS_DIR), $(BONUS_SUBDIR))

$(NAME): $(OBJS) | libft
	@if [ -d "$(BONUS_OBJS_DIR)" ]; then \
      		rm -rf $(BONUS_OBJS_DIR); \
      		rm -f $(NAME); \
      	fi
	@$(CC) $(OBJS) -o $@ -L$(LIBFT_DIR) -lft
	@echo "--------------------------"
	@echo "push_swap binary created."
	@echo "--------------------------"

$(NAME_BONUS): $(BONUS_OBJS) | libft
	@if [ -d "$(OBJS_DIR)" ]; then \
  		rm -rf $(OBJS_DIR); \
  		rm -f $(NAME); \
  	fi
	@$(CC) $(BONUS_OBJS) -o pipex -L$(LIBFT_DIR) -lft
	@touch $@
	@echo "--------------------------"
	@echo "Checker binary created."
	@echo "--------------------------"

libft:
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(MANDATORY_DIR)/%.c
	@if [ ! -d "$(OBJS_DIR)" ]; then \
		mkdir -p $(OBJS_SUBDIR); \
	fi
	$(CC) $(CFLAGS) -c $? -o $@

$(BONUS_OBJS_DIR)/%.o: $(BONUS_DIR)/%.c
	@if [ ! -d "$(BONUS_OBJS_DIR)" ]; then \
		mkdir -p $(BONUS_OBJS_SUBDIR); \
	fi
	@$(CC) $(CFLAGS) -c $? -o $@


.PHONY: all clean fclean re log libft bonus

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(BONUS_OBJS_DIR)
	@echo "--------------------------"
	@echo "push_swap and checker objects removed."
	@echo "--------------------------"
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "push_swap and checker removed."
	@echo "--------------------------"
	@make fclean -C $(LIBFT_DIR)

re: fclean all

bonus: $(NAME_BONUS)

log:
	@echo "push_swap Source Files:" $(SRCS)
	@printf "\n"
	@echo "push_swap Objects Files:" $(OBJS)
	@printf "\n"
