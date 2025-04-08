# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 17:08:44 by brturcio          #+#    #+#              #
#    Updated: 2024/11/23 09:26:43 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES = $(addsuffix .c, ft_printf ft_putchar ft_putstr ft_putnum ft_identify_type ft_puthexa)

OBJS := $(FILES:%.c=%.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY :  all clean fclean re
