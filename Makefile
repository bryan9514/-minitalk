# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 11:56:34 by brturcio          #+#    #+#              #
#    Updated: 2025/04/05 22:11:43 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinc
RM		= rm -f

SRC_DIR		= src
OBJ_DIR		= obj

NAME_CLIENT	= client
NAME_SERVER	= server
BONUS_CLIENT	= client_bonus
BONUS_SERVER	= server_bonus

SRC_CLIENT		= $(SRC_DIR)/client.c  $(SRC_DIR)/utils.c $(SRC_DIR)/printf_text.c
SRC_SERVER		= $(SRC_DIR)/server.c  $(SRC_DIR)/utils.c $(SRC_DIR)/printf_text.c
SRC_CLIENT_BONUS	= $(SRC_DIR)/client_bonus.c $(SRC_DIR)/utils_bonus.c $(SRC_DIR)/printf_text_bonus.c
SRC_SERVER_BONUS	= $(SRC_DIR)/server_bonus.c $(SRC_DIR)/utils_bonus.c $(SRC_DIR)/printf_text_bonus.c

OBJ_CLIENT		= $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER		= $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT_BONUS	= $(SRC_CLIENT_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER_BONUS	= $(SRC_SERVER_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: 	$(OBJ_DIR) $(NAME_CLIENT) $(NAME_SERVER)
bonus: 	$(OBJ_DIR) $(BONUS_CLIENT) $(BONUS_SERVER) $(OBJ_DIR)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)
	@echo "✅ Client compiled"

$(NAME_SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)
	@echo "✅ Server compiled"

$(BONUS_CLIENT): $(OBJ_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(BONUS_CLIENT) $(OBJ_CLIENT_BONUS)
	@echo "✅ Bonus client compiled"

$(BONUS_SERVER): $(OBJ_SERVER_BONUS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(BONUS_SERVER) $(OBJ_SERVER_BONUS)
	@echo "✅ Bonus server compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "✅ clean done"

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)
	@echo "✅ fclean done"

re: fclean all

.PHONY: all clean fclean re


