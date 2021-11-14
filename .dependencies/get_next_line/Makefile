# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 16:43:13 by dde-oliv          #+#    #+#              #
#    Updated: 2021/08/26 16:49:57 by dde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
FILES 		= 	get_next_line_utils.c get_next_line.c
OBJS 		=	$(FILES:.c=.o)
FLAGS 		= 	-Wall -Wextra -Werror
NAME 		=	libgnl.a
RM 			=	rm -f

###################################################################

all:		$(NAME)
				
$(NAME):	$(OBJS)
				@ar rc $(NAME) $(OBJS)

%.o:		%.c 
				@$(CC) -c $(FLAGS) $< 

clean:
				@$(RM) $(OBJS)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
