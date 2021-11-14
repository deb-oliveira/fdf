# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 14:58:34 by dde-oliv          #+#    #+#              #
#    Updated: 2021/11/14 12:02:40 by dde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
FILES_PATH	=	src
FILES 		= 	$(FILES_PATH)/main.c
OBJS_PATH	=	objs
OBJS 		=	$(OBJS_PATH)/$(notdir $(FILES:.c=.o))
FLAGS 		= 	-Wall -Wextra -Werror
LIBRARIES	= 	-lbsd -lmlx -lXext -lX11 -lm
LIBFT_PATH	= 	.dependencies/libft
LIBFT		=	$(LIBFT_PATH)/libft.a
GNL_PATH	= 	.dependencies/get_next_line
GNL 		= 	$(GNL_PATH)/libgnl.a
NAME 		=	./fdf
RM 			=	rm -f

###################################################################

all:		$(OBJS_PATH) $(NAME)

$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)
				
$(NAME):	$(OBJS) $(LIBFT) $(GNL)
				$(CC) $(FLAGS) $(OBJS) $(LIBRARIES) $(LIBFT) $(GNL) -o fdf

$(OBJS_PATH)/%.o:		$(FILES_PATH)/%.c
				$(CC) -c $(FLAGS) $< -o $(addsuffix .o, $(OBJS_PATH)/$(basename $(@F)))

$(LIBFT):
				@make -C $(LIBFT_PATH)

$(GNL):
				@make -C $(GNL_PATH)
				
clean:
				@$(RM) $(OBJS)

fclean:		clean
				@make fclean -C $(LIBFT_PATH)
				@make fclean -C $(GNL_PATH)
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re $(LIBFT) $(GNL)
