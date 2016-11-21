#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/11 15:48:23 by luccasim          #+#    #+#              #
#    Updated: 2016/11/14 17:21:19 by luccasim         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra $(INC)
INC		=	-I includes/
HEAD	=	$(shell find includes -name '*.h' -type f)
SRC		=	$(shell find . -name '*.c' -type f)
OBJ		=	$(patsubst %.c, %.o, $(SRC))
NAME	=	libft.a

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) Created!"

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
