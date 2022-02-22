# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 14:58:34 by dde-oliv          #+#    #+#              #
#    Updated: 2022/02/22 15:15:04 by dde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
FILES_PATH	=	src
FILES 		= 	$(FILES_PATH)/handleEvents.c 	\
				$(FILES_PATH)/handleErrors.c 	\
				$(FILES_PATH)/main.c \
				$(FILES_PATH)/imgProperties.c \
				$(FILES_PATH)/mapConfig.c \
				$(FILES_PATH)/imgDraw.c \
				$(FILES_PATH)/bresen_draw.c \
				$(FILES_PATH)/draw_map.c \
				$(FILES_PATH)/utils.c
OBJS_PATH	=	objs
OBJS 		=	$(addprefix $(OBJS_PATH)/,$(notdir $(FILES:.c=.o)))
FLAGS 		= 	-Wall -Wextra -Werror
LIBRARIES	= 	-lbsd -lmlx -lXext -lX11 -lm
LIBFT_PATH	= 	.dependencies/libft
LIBFT		=	$(LIBFT_PATH)/libft.a
GNL_PATH	= 	.dependencies/get_next_line
GNL 		= 	$(GNL_PATH)/libgnl.a
NAME 		=	fdf
RM 			=	rm -f
MINILIBX	= 	$(shell ls .dependencies/minilibx-linux/)

###################################################################

##all:		$(OBJS_PATH) $(NAME)

all: $(OBJS_PATH) $(NAME)
	

minilibx-install:
	@echo Installing minilibx...
	rm -rf .dependencies/minilibx-linux
	git clone https://github.com/42Paris/minilibx-linux .dependencies/minilibx-linux
	sudo apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev
	make -C .dependencies/minilibx-linux
	sudo mv -n .dependencies/minilibx-linux/man/man1 /usr/local/man/
	sudo mv -n .dependencies/minilibx-linux/libmlx.a /usr/lib
	sudo mv -n .dependencies/minilibx-linux/mlx.h /usr/include/
	make clean -C .dependencies/minilibx-linux

$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)
				
$(NAME):	$(OBJS) $(LIBFT) $(GNL)
				$(CC) $(FLAGS) $(OBJS) $(LIBRARIES) $(LIBFT) $(GNL) -fsanitize=address -o fdf

$(OBJS_PATH)/%.o:	$(FILES_PATH)/%.c
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
