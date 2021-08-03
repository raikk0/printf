# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 19:53:54 by throdrig          #+#    #+#              #
#    Updated: 2021/08/03 17:04:06 by throdrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= #-Wall -Wextra -Werror 
LIB1		= ar -rcs
LIB2		= ranlib
RM			= rm -rf
NAME		= libftprintf.a 

SRCS		=	ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strdup.c ft_memcpy.c ft_strlen.c ft_printf_utils.c

BONUS_S		=	ft_printf_bonus.c

BONUS_O		= $(BONUS_S:.c=.o)
OBJS		= $(SRCS:.c=.o)
PROGRAM		= main.out

all:		msg $(NAME)

msg:		
			@echo "Compiling ..."

.c.o:
			@$(CC) $(CFLAGS) -c  -fPIC $< -o $(<:.c=.o)

$(NAME):	$(OBJS) 
			@$(LIB1) $(NAME) $(OBJS)
			@$(LIB2) $(NAME)

bonus:		$(NAME) $(BONUS_O)
			$(LIB1) $(NAME) $(BONUS_O)
			$(LIB2) $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME) $(PROGRAM) *.a

compile:	fclean $(NAME)
			$(CC) -static main.c -L . -lftprintf $(CFLAGS) -lbsd -o $(PROGRAM)

so:			
			gcc -nostartfiles -shared -o libftprintf.so $(OBJS)

re:			fclean all

norme:		
			norminette ft_*.c libftprintf.h

.PHONY:		all clean fclean re compile .c.o $(NAME)