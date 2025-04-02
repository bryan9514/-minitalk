# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 11:56:34 by brturcio          #+#    #+#              #
#    Updated: 2025/03/25 13:38:54 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===COMPILATION SETTINGS===

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinc
RM			= rm -f

#=======DIRECTORIES========

SRC_DIR		= src
OBJ_DIR		= obj

#=====EXECUTABLE NAMES=====

NAME_CLIENT		= client
NAME_SERVER		= server
BONUS_CLIENT	= client_bonus
BONUS_SERVER	= server_bonus

#======SOURCE FILES========

SRC_CLIENT		= $(SRC_DIR)/client.c  $(SRC_DIR)/utils.c
SRC_SERVER		= $(SRC_DIR)/server.c  $(SRC_DIR)/utils.c
SRC_CLIENT_BONUS		= $(SRC_DIR)/client_bonus.c $(SRC_DIR)/utils.c
SRC_SERVER_BONUS		= $(SRC_DIR)/server_bonus.c $(SRC_DIR)/utils.c

#======OBJECT FILES========

OBJ_CLIENT			= $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER			= $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT_BONUS	= $(SRC_CLIENT_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER_BONUS	= $(SRC_SERVER_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#=======DEFAULT RULE========

all: 	$(OBJ_DIR) $(NAME_CLIENT) $(NAME_SERVER) 
bonus: 	$(OBJ_DIR) $(BONUS_CLIENT) $(BONUS_SERVER) $(OBJ_DIR)

#========COMPILATION========

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
#=====OBJECT COMPILATION======

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#======CLEAN OBJECT FILES=====

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "🧹 Object files removed"

#=========FULL CLEAN===========

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)
	@echo "🧹 Executables removed"

#=========RECOMPILE============

re: fclean all

#===========PHONY==============

.PHONY: all clean fclean re


