# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 11:42:48 by emaniez           #+#    #+#              #
#    Updated: 2015/03/23 10:35:10 by emaniez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include

.PHONY: all, $(NAME), clean, fclean, re, norme
SRC_PATH = ./src/

SRC_NAME = main.c \
		   signal_mgmt.c \
		   i_command_you.c \
		   command_treatment.c \
		   find_path.c \
		   build_hash_table.c \
		   search_execs.c \
		   populate_table.c \
		   builtins.c \
		   get_env_var.c \
		   get_env_name.c \
		   replace_env_var.c \
		   cd.c \
		   pwd.c \
		   env.c \
		   setenv.c \
		   unsetenv.c \
		   copy_env.c \
		   con_env_arr.c \

OBJ_PATH = ./obj/
INC_PATH = ./includes/

LIB_PATH = ./libft/
LIB_NAME = libft.a
LIBINC_PATH = $(LIB_PATH)/includes

NAME = ft_minishell1

CC = gcc
CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
INC = ./includes/ft_sh.h

all: $(NAME)

$(NAME) : $(OBJ)	
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(CMLX) $(LIB) -o $(NAME) $(OBJ) 
	@echo "$(NAME) : executable file compiled successfully"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I$(LIBINC_PATH) -I$(INC_PATH) -o $@ -c $<

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@echo "$(NAME) : object files deleted successfully"

fclean: clean
	@rm -f $(LIB)
	@echo "$(LIB_NAME) : library file deleted succesfully"
	@rm -f $(NAME)
	@echo "$(NAME) : executable file deleted successfully"

re: fclean all

norme_proj:
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h

norme_lib:
	@make -C $(LIB_PATH) norme
