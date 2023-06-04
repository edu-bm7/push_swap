# C Compiler (Clang-12)
CC := clang
# PipeX Variables
NAME := push_swap
NAME_BONUS := checker
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
		validation/parameters_validation.c\
		validation/has_repeat.c\
		validation/free_hash_table.c\
		operations/swap_operations.c\
		operations/push_operations.c\
		operations/rotate_operations.c\
		operations/reverse_rotate_operations.c\
		operations/utils_operations.c\
		init_stacks/init_stacks.c\
		init_stacks/stack_operations.c\
		sort/sort_stacks.c\
		sort/sort_utils.c\
		sort/get_placements.c\
		sort/assign_stacks_values.c\
		sort/calculate_movements_b.c\
		sort/init_movements.c\
		sort/init_movements_r_rr.c\
		apply_movements/apply_movements.c\
		apply_movements/apply_rotations.c\
		apply_movements/apply_reverse_rotations.c\
		markups/markup.c\
		index/index.c\
		command.c\
		free.c\
		print.c\
		)

BONUS = $(addprefix $(BONUS_DIR)/, main_bonus.c\
		validation/parameters_validation_bonus.c\
		validation/has_repeat_bonus.c\
		validation/free_hash_table_bonus.c\
		init_stacks/init_stacks_bonus.c\
        init_stacks/stack_operations_bonus.c\
        operations/swap_operations_bonus.c\
        operations/push_operations_bonus.c\
        operations/rotate_operations_bonus.c\
        operations/reverse_rotate_operations_bonus.c\
        operations/utils_operations_bonus.c\
        sort/sort_bonus.c\
        free_bonus.c\
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
	@$(CC) $(OBJS) -o $@ -L$(LIBFT_DIR) -lft
	@echo "--------------------------"
	@echo "push_swap binary created."
	@echo "--------------------------"

$(NAME_BONUS): $(BONUS_OBJS) | libft
	@$(CC) $(BONUS_OBJS) -o $@ -L$(LIBFT_DIR) -lft
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
