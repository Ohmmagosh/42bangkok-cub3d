## **************************************************************************** #
##                                                                              #
##                                                         :::      ::::::::    #
##    Makefile                                           :+:      :+:    :+:    #
##                                                     +:+ +:+         +:+      #
##    By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+         #
##                                                 +#+#+#+#+#+   +#+            #
##    Created: 2023/03/12 02:35:33 by psuanpro          #+#    #+#              #
##    Updated: 2023/03/12 18:38:01 by psuanpro         ###   ########.fr        #
##                                                                              #
## **************************************************************************** #

NAME		= cub3d

MAIN		= main.c
MAIN_DIR	= ./

CC			= gcc
#CFLAGS		= -g -Wall -Werror -Wextra -Imlx
CFLAGS		= -g -Wall -Werror -Wextra

SRC_DIR		= ./src/

MODULE1		= input.c \
				valid_texture.c \
				valid_texture_utils.c \
				valid_texture_utils1.c \
				valid_map.c \
				valid_map_utils.c \
				valid_path.c \
				valid_file.c \
				set_map.c \
				set_map_utils.c \
				set_tex.c

MODULE2		= process.c \
				camera.c \
				mapshow.c \
				drawwall.c \
				tdraw.c \
				hooker.c

MODULE3		= free.c

MODULE4		= init.c \
				init_utils.c

MODULE5		= print_msg_utils.c \
				print_str.c \
				file_utils.c \
				str_utils.c \
				int_utils.c


MODULE1_DIR	= ./src/input/
MODULE2_DIR = ./src/process/
MODULE3_DIR = ./src/free/
MODULE4_DIR = ./src/init/
MODULE5_DIR = ./src/utils/

LIB_DIR		= ./lib/
MLX = mlx/libmlx.a
INCLUDE_MLX = -framework OpenGL -framework AppKit
LIBFT = libft/libft.a
LIB =	${addprefix $(LIB_DIR),$(LIBFT)} \
		#${addprefix $(LIB_DIR),$(MLX)}


OBJ_DIR		= ./obj/

OBJS		= ${addprefix $(OBJ_DIR),$(MODULE1:.c=.o)} \
			  ${addprefix $(OBJ_DIR),$(MODULE2:.c=.o)} \
			  ${addprefix $(OBJ_DIR),$(MODULE3:.c=.o)} \
			  ${addprefix $(OBJ_DIR),$(MODULE4:.c=.o)} \
			  ${addprefix $(OBJ_DIR),$(MODULE5:.c=.o)} \
			  ${addprefix $(OBJ_DIR),$(MAIN:.c=.o)}

RM = rm -rf


BRED =\033[1;31m
BGRN =\033[1;32m
BYEL =\033[1;33m
RES = \033[0m
BLU = \033[0;34m

COMPILE = echo "$(BGRN)$(NAME) compiled....$(RES)"
CLEAN = echo "$(BYEL)$(NAME) clean....$(RES)"
FCLEAN = echo "$(BRED)$(NAME) fclean....$(RES)"

LOAD = bash ./src/script/animation.sh $(MODULE1) $(MODULE2) $(MODULE3) $(MODULE4) $(MODULE5);
CUBE =  echo '$(BLU)________$(RES)/\\\\\\\\\\\\\\\\\\$(BLU)________________$(RES)/\\\\\\$(BLU)____________$(RES)/\\\\\\\\\\\\\\\\\\\\$(BLU)___$(RES)/\\\\\\\\\\\\\\\\\\\\\\\\$(BLU)____$(RES)         '; \
		echo ' $(BLU)_____$(RES)/\\\\\\////////$(BLU)________________$(RES)\\/\\\\\\$(BLU)__________$(RES)/\\\\\\///////\\\\\\$(BLU)_$(RES)\\/\\\\\\////////\\\\\\$(BLU)__$(RES)        '; \
		echo '  $(BLU)___$(RES)/\\\\\\/$(BLU)_________________________$(RES)\\/\\\\\\$(BLU)_________$(RES)\\///$(BLU)______$(RES)/\\\\\\$(BLU)__$(RES)\\/\\\\\\$(BLU)______$(RES)\\//\\\\\\$(BLU)_$(RES)       '; \
		echo '   $(BLU)__$(RES)/\\\\\\$(BLU)______________$(RES)/\\\\\\$(BLU)____$(RES)/\\\\\\$(BLU)_$(RES)\\/\\\\\\$(BLU)________________$(RES)/\\\\\\//$(BLU)___$(RES)\\/\\\\\\$(BLU)_______$(RES)\\/\\\\\\$(BLU)_$(RES)      '; \
		echo '    $(BLU)_$(RES)\\/\\\\\\$(BLU)_____________$(RES)\\/\\\\\\$(BLU)___$(RES)\\/\\\\\\$(BLU)_$(RES)\\/\\\\\\\\\\\\\\\\\\$(BLU)_________$(RES)\\////\\\\\\$(BLU)__$(RES)\\/\\\\\\$(BLU)_______$(RES)\\/\\\\\\$(BLU)_$(RES)     '; \
		echo '     $(BLU)_$(RES)\\//\\\\\\$(BLU)____________$(RES)\\/\\\\\\$(BLU)___$(RES)\\/\\\\\\$(BLU)_$(RES)\\/\\\\\\////\\\\\\$(BLU)___________$(RES)\\//\\\\\\$(BLU)_$(RES)\\/\\\\\\$(BLU)_______$(RES)\\/\\\\\\$(BLU)_$(RES)    '; \
		echo '      $(BLU)__$(RES)\\///\\\\\\$(BLU)__________$(RES)\\/\\\\\\$(BLU)___$(RES)\\/\\\\\\$(BLU)_$(RES)\\/\\\\\\$(BLU)__$(RES)\\/\\\\\\$(BLU)__$(RES)/\\\\\\$(BLU)______$(RES)/\\\\\\$(BLU)__$(RES)\\/\\\\\\$(BLU)_______$(RES)/\\\\\\$(BLU)__$(RES)   '; \
		echo '       $(BLU)____$(RES)\\////\\\\\\\\\\\\\\\\\\_$(RES)\\//\\\\\\\\\\\\\\\\\\$(BLU)__$(RES)\\/\\\\\\\\\\\\\\\\\\$(BLU)__$(RES)\\///\\\\\\\\\\\\\\\\\\/$(BLU)___$(RES)\\/\\\\\\\\\\\\\\\\\\\\\\\\/$(BLU)___$(RES)  '; \
		echo '        $(BLU)_______$(RES)\\/////////$(BLU)___$(RES)\\/////////$(BLU)___$(RES)\\/////////$(BLU)_____$(RES)\\/////////$(BLU)_____$(RES)\\////////////$(BLU)_____$(RES) ';

#input
${OBJ_DIR}%.o: ${MODULE1_DIR}%.c
	$(CC) -g -c -o $@ $^

#process
${OBJ_DIR}%.o: ${MODULE2_DIR}%.c
	$(CC) -g -c -o $@ $^

#free
${OBJ_DIR}%.o: ${MODULE3_DIR}%.c
	$(CC) -g -c -o $@ $^

#init
${OBJ_DIR}%.o: ${MODULE4_DIR}%.c
	$(CC) -g -c -o $@ $^

${OBJ_DIR}%.o: ${MODULE5_DIR}%.c
	$(CC) -g -c -o $@ $^

all: ${OBJ_DIR} ${NAME}
#@$(LOAD)
	@sleep 0.5
	@$(CUBE)



${OBJ_DIR}:
	@mkdir -p $(OBJ_DIR)

${OBJ_DIR}%.o: ${MAIN_DIR}%.c
	$(CC) -c -o $@ $^

${NAME}: ${OBJS}
	@make -C lib/libft
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)
#@make -C lib/mlx
#$(CC) $(OBJS) -o $(INCLUDE_MLX) $(NAME) $(LIB) $(CFLAGS)

run:
	./cub3d map/minimalist.cub

clean:
	@make -C lib/libft clean
	@make -C lib/mlx clean
	@echo "$(BYEL)Mlx Clean....$(RES)"
	@$(RM) $(OBJ_DIR)
	@$(RM) *.dSYM
	@$(CLEAN)

fclean: clean
	@make -C lib/libft fclean
	@$(RM) $(NAME)
	@$(FCLEAN)

re: fclean all
