#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:11:21 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/12/06 17:47:31 by ncruz-ne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# If Makefile @ <project root>/TESTS: make <command> -f TESTS/Makefile from root

NAME = getnextline.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

OBJS = get_next_line.o get_next_line_utils.o

OBJS_BONUS = get_next_line_bonus.o get_next_line_utils_bonus.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(NAME) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	touch .bonus


TESTS_DIR = TESTS
TESTS_SRCS_DIR = $(TESTS_DIR)/srcs
TESTS_OBJS_DIR := $(TESTS_DIR)/objs
EXE_DIR := $(TESTS_DIR)/exe
MAIN_SRCS := $(wildcard $(TESTS_SRCS_DIR)/main*.c)
MAIN_BASENAMES := $(notdir $(MAIN_SRCS:.c=))
MAIN_OBJS := $(patsubst $(TESTS_SRCS_DIR)/%.c, $(TESTS_OBJS_DIR)/%.o, $(MAIN_SRCS))

# $(TESTS_DIR):
# 	git clone --depth 1 --filter=blob:none --sparse \
# 	https://github.com/neusamcn/42Lisboa-CC-gnl/tree/main $(TESTS_DIR)
# 	cd $(TESTS_DIR)
# 	git sparse-checkout set TESTS

# Executables directory and names
EXEC := $(patsubst %, $(EXE_DIR)/%, $(MAIN_BASENAMES))

# Ensure the objects and exe directories exist (order-only prerequisites)
$(TESTS_OBJS_DIR):
	@mkdir -p $(TESTS_OBJS_DIR)

$(EXE_DIR):
	@mkdir -p $(EXE_DIR)
	@cd $(EXE_DIR)
	@curl -L \
	'https://raw.githubusercontent.com/neusamcn/42Lisboa-CC-gnl/refs/heads/main/TESTS/exe/valgrind_all.sh'
	@cd ..
	@echo "/$(EXE_DIR) created and valgrind_all.sh imported."

#	import valgrind_all.sh 

# Compile TESTS/srcs/%.c into TESTS/objs/%.o
$(TESTS_OBJS_DIR)/%.o: $(TESTS_SRCS_DIR)/%.c | $(TESTS_OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link executables into TESTS/exe from objects in TESTS/objs
$(EXE_DIR)/%: $(TESTS_OBJS_DIR)/%.o $(NAME) | $(EXE_DIR)
	$(CC) $(CFLAGS) -g $< $(NAME) -o $@

run: $(EXEC)
	@for exe in $(EXEC); do \
		echo "Running $$exe..."; \
		./$$exe; \
	done

valgrind: $(EXEC)
	./$(EXE_DIR)/valgrind_all.sh

clean:
	-rm -f $(OBJS) $(MAIN_OBJS) $(OBJS_BONUS) .bonus

fclean: clean
	-rm -f $(NAME) $(EXEC)

re: fclean all

tclean: fclean
	@rm -fr $(TESTS_OBJS_DIR)
	@echo "/$(TESTS_OBJS_DIR) and its contents deleted."
	@rm -fr $(TESTS_DIR)/valgrind
	@echo "/$(TESTS_DIR)/valgrind and its contents deleted."
	@rm -fr $(TESTS_DIR)/outputs
	@echo "/$(TESTS_DIR)/outputs and its contents deleted."

.PHONY: all clean fclean re run valgrind bonus tclean