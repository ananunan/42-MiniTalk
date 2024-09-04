# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 21:27:32 by aeberius          #+#    #+#              #
#    Updated: 2024/09/04 13:35:06 by aeberius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 Makefile Rules                               #
################################################################################

# Makefile settings
MAKEFLAGS += -s

# Compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror

# Project names
NAME = server client
NAME_BONUS = server_bonus client_bonus

# Directories and libraries
LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)libft.a

# Source files for server and client
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_SRCS_BONUS = server_bonus.c
CLIENT_SRCS_BONUS = client_bonus.c

# Object files
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

# Default target: Compile everything
all: $(NAME)
	@clear
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

# Linking the final executables
$(NAME): $(LIBFT) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(CC) $(FLAGS) -o server $(SERVER_OBJS) $(LIBFT)
	$(CC) $(FLAGS) -o client $(CLIENT_OBJS) $(LIBFT)

# Building the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_BONUS): $(LIBFT) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	$(CC) $(FLAGS) -o server_bonus $(SERVER_OBJS_BONUS) $(LIBFT)
	$(CC) $(FLAGS) -o client_bonus $(CLIENT_OBJS_BONUS) $(LIBFT)

# Cleaning object files
clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full cleanup, including executables and library
fclean: clean
	rm -rf server client server_bonus client_bonus
	rm -rf $(LIBFT)
	@clear
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Cleaned Successfully! ║"
	@echo "╚══════════════════════════╝"

# Rebuild everything from scratch
re: fclean all

# Leak testing using Valgrind
leak: re
	valgrind --leak-check=full --show-leak-kinds=all ./server

# Phony targets to avoid filename conflicts
.PHONY: all clean fclean re bonus leak
