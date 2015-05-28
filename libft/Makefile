# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaniez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 16:09:39 by emaniez           #+#    #+#              #
#    Updated: 2015/03/23 10:20:28 by emaniez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re, norme

SRC_PATH = ./src/

SRC_NAME = ft_printf.c \
		   ft_asprintf.c \
		   ft_retprintf.c \
		   pf_read_loop.c \
		   pf_parser.c \
		   pf_typedef.c \
		   pf_redirection.c \
		   pf_css.c \
		   pf_csp.c \
		   pf_csd.c \
		   pf_csdlm.c \
		   pf_cso.c \
		   pf_csolm.c \
		   pf_csu.c \
		   pf_csulm.c \
		   pf_csx.c \
		   pf_csxlm.c \
		   pf_csc.c \
		   pf_struct_fill.c \
		   pf_sign_print.c \
		   pf_width_mgmt.c \
		   pf_pre_print.c \
		   pf_width_parse.c \
		   pf_prec_parse.c \
		   pf_string_mgmt.c \
		   pf_len_calc.c \
		   pf_post_print.c \
		   pf_itoa.c \
		   pf_wstrsub.c \
		   ft_atoi.c \
		   ft_atol.c \
		   ft_bzero.c \
		   ft_dub_char_check.c \
		   ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isnumerical.c \
		   ft_islower.c \
		   ft_isprint.c \
		   ft_isspace.c \
		   ft_isupper.c \
		   ft_itoa.c \
		   ft_uitoa.c \
		   ft_lstnew.c \
		   ft_lstadd.c \
		   ft_lstdel.c \
		   ft_lstdelone.c \
		   ft_lstmap.c \
		   ft_lstiter.c \
		   ft_lst_create_node.c \
		   ft_lst_create.c \
		   ft_lst_init.c \
		   ft_lst_len.c \
		   ft_lst_link.c \
		   ft_lst_push.c \
		   ft_lst_unshift.c \
		   ft_lst_del_node.c \
		   ft_lst_pop.c \
		   ft_lst_toppop.c \
		   ft_lst_free.c \
		   ft_lst_free_node.c \
		   ft_memalloc.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memdel.c \
		   ft_memmove.c \
		   ft_memset.c \
		   ft_numlen.c \
		   ft_unumlen.c \
		   ft_pow.c \
		   ft_putchar.c \
		   ft_putchar_fd.c \
		   ft_putwchar.c \
		   ft_wcharlen.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putnbr_fd.c \
		   ft_putstr.c \
		   ft_putstr_fd.c \
		   ft_strcat.c \
		   ft_strchr.c \
		   ft_strchrstr.c \
		   ft_strchrstrinv.c \
		   ft_strclr.c \
		   ft_strcmp.c \
		   ft_strcpy.c \
		   ft_strdel.c \
		   ft_strdup.c \
		   ft_strdup_f.c \
		   ft_strequ.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strjoin.c \
		   ft_strjoin_fb.c \
		   ft_strjoin_fl.c \
		   ft_strjoin_fr.c \
		   ft_strnjoin.c \
		   ft_wstrjoin_f.c \
		   ft_charjoin.c \
		   ft_charjoin_f.c \
		   ft_wcharjoin.c \
		   ft_wcharjoin_f.c \
		   ft_strlcat.c \
		   ft_linelen.c \
		   ft_strlen.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strncpy.c \
		   ft_strnequ.c \
		   ft_strnew.c \
		   ft_strnstr.c \
		   ft_strrchr.c \
		   ft_strsplit.c \
		   ft_spaces_split.c \
		   ft_strstr.c \
		   ft_strsub.c \
		   ft_wstrsub.c \
		   ft_strtrim.c \
		   ft_tolower.c \
		   ft_tolowerstr.c \
		   ft_toupper.c \
		   ft_toupperstr.c \
		   ft_dec2hex.c \
		   ft_strrev.c \
		   ft_oct_conv.c \
		   ft_padding.c \
		   ft_strpadding.c \
		   ft_abs.c \
		   get_next_line.c \
		   get_next_line_basic.c \
		   ft_endianness.c \
		   ft_issort_strnumarray.c \
		   ft_isrsort_strnumarray.c \
		   ft_arrlen.c \
		   ft_print_strarray.c \
		   ft_print_intarray.c \
		   ft_intarrdup.c \
		   ft_intarrequ.c \
		   ft_2dintarrdup.c \
		   ft_2dintarrequ.c \
		   ft_2dintarr_free.c \
		   ft_swap.c \
		   ft_arr_pop.c \
		   ft_arr_push_str.c \
		   ft_arr_rev.c \
		   ft_arr_rotate.c \
		   ft_arr_rrotate.c \
		   ft_arr_shift.c \
		   ft_arr_unshift_str.c \
		   ft_strarrdup.c \
		   free_arr.c \
		   ft_simple_getopt.c \
		   exe_getopt.c \
		   mlx_initiate.c \
		   mlx_draw_img_pix.c \
		   mlx_draw_line.c \
		   mlx_coord_2_addr.c \
		   mlx_draw_circle.c \
		   ft_free_str_arr.c \
		   ft_arrstr.c \
		   ft_hash_char_cumul.c \
		   ft_hash_char_cumul31.c \
		   ft_hash_free.c \

INC_PATH = ./includes/

INC_NAME = libft.h \
		   ft_printf.h \
		   ft_mlx.h \
		   ft_hash.h \

OBJ_PATH = ./obj/

NAME = libft.a

CC = gcc
CFLAGS = -g -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix $(INC_PATH), $(INC_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) : library has been compiled successfully"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@mkdir -p $(OBJ_PATH) 
	@$(CC) $(CFLAGS) -I$(INC_PATH) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@echo "$(NAME) : object files have been removed successfully"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) : library file has been removed succesully"

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h
