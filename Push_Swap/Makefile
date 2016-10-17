# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2016/05/20 22:29:39 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Corr_PS

SRC			=	src/main.c
SRC			+=	src/test1.c
SRC			+=	src/test2.c
SRC			+=	src/test3.c
SRC			+=	src/test4.c
SRC			+=	src/test5.c
SRC			+=	src/test6.c
SRC			+=	src/test7.c
SRC			+=	src/test8.c

SRCO		=	$(SRC:.c=.o)
HEADERSLIB	=	libftprintf/includes
HEADERS		=	includes
CC			=	gcc
CFLAGS		=

all: $(NAME)

re: fclean all

%.o: %.c
	@echo "\033[32mCorr_PS  :\033[0m [Compilation:\033[33m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERSLIB) -I $(HEADERS)

$(NAME): $(SRCO)
	@make -C libftprintf/
	@$(CC)  $(CFLAGS) -o $@ $^ libftprintf/libftprintf.a
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "[\033[36m------ OK - Corr_PS -------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "\033[32muse: ./$(NAME) [./push_swap]\033[0m"

clean:
	@echo "\033[32mCorr_PS  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@make clean -C libftprintf/
	@rm -f $(SRCO)

fclean:
	@echo "\033[32mCorr_PS  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)
	@echo "\033[32mCorr_PS  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@make fclean -C libftprintf/
	@rm -f $(NAME)

.PHONY: re clean fclean all
