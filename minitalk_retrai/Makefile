# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 08:12:09 by brturcio          #+#    #+#              #
#    Updated: 2025/04/08 09:02:07 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT		= client
NAME_SERVER		= server
BONUS_CLIENT	= client_bonus
BONUS_SERVER	= server_bonus

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -Iinc -Ilibft -Ift_printf
RM				= rm -f

SRC_DIR			= src
OBJ_DIR			= obj

LIBFT_DIR		= libft
PRINTF_DIR		= ft_printf
LIBFT 			= $(LIBFT_DIR)/libft.a
PRINTF 			= $(PRINTF_DIR)/libftprintf.a

LDFLAGS			= -L$(LIBFT_DIR) -L$(PRINTF_DIR)
LDLIBS			= -lft -lftprintf

SRC_CLIENT			= $(SRC_DIR)/client.c  $(SRC_DIR)/utils.c $(SRC_DIR)/printf_text.c
SRC_SERVER			= $(SRC_DIR)/server.c  $(SRC_DIR)/utils.c $(SRC_DIR)/printf_text.c
SRC_CLIENT_BONUS	= $(SRC_DIR)/client_bonus.c $(SRC_DIR)/utils_bonus.c $(SRC_DIR)/printf_text_bonus.c
SRC_SERVER_BONUS	= $(SRC_DIR)/server_bonus.c $(SRC_DIR)/utils_bonus.c $(SRC_DIR)/printf_text_bonus.c

OBJ_CLIENT			= $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER			= $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT_BONUS	= $(SRC_CLIENT_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER_BONUS	= $(SRC_SERVER_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(OBJ_DIR) $(LIBFT) $(PRINTF) $(BONUS_CLIENT) $(BONUS_SERVER)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "✅ Libft compiled"

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)
	@echo "✅ Printf compiled"

$(NAME_CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	@echo "✅ Client compiled"

$(NAME_SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	@echo "✅ Server compiled"

$(BONUS_CLIENT): $(OBJ_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	@echo "✅ Bonus client compiled"

$(BONUS_SERVER): $(OBJ_SERVER_BONUS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	@echo "✅ Bonus server compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) clean -s -C $(LIBFT_DIR)
	@$(MAKE) clean -s -C $(PRINTF_DIR)
	@echo "✅ clean done"

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@$(MAKE) fclean -s -C $(PRINTF_DIR)
	@echo "✅ fclean done"

re: fclean all

.PHONY: all bonus clean fclean re

