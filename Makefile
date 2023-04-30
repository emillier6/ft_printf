# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emillier <emillier@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 14:23:50 by emillier          #+#    #+#              #
#    Updated: 2023/04/30 15:01:11 by emillier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	gcc
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar -rcs

SRCS  = ft_printf.c conversion_cs.c\
		conversion_pdiuxX.c

D_OBJ = obj
#.o
OBJ = $(addprefix $(D_OBJ)/, $(SRCS:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRCS:.c=.d))
#Bonus .o
B_OBJ = $(addprefix $(D_OBJ)/, $(BONUS:.c=.o))
B_DEP = $(addprefix $(D_OBJ)/, $(BONUS:.c=.d))

all:	dir $(NAME)
-include $(DEP)
-include $(B_DEP)
dir: 
	@mkdir -p $(D_OBJ)
$(D_OBJ)/%.o:%.c
	@$(CC) -MMD $(FLAGS) -c $< -o $@
$(NAME):	${OBJ}
	@$(LIBC) $(NAME) $(OBJ)
	@touch $(NAME)

.PHONY: clean fclean re
clean:
	@$(RM) $(D_OBJ) bonus
fclean: clean
	@$(RM) $(NAME)
re: fclean all
