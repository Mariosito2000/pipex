# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 10:17:43 by marias-e          #+#    #+#              #
#    Updated: 2023/02/20 13:00:36 by marias-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf_sl/ft_printf.c \
ft_printf_sl/ft_strlen.c \
ft_printf_sl/ft_write_c.c \
ft_printf_sl/ft_write_di.c \
ft_printf_sl/ft_write_p.c \
ft_printf_sl/ft_write_s.c \
ft_printf_sl/ft_write_u.c \
ft_printf_sl/ft_write_upx.c \
ft_printf_sl/ft_write_x.c \
get_next_line_sl/get_next_line.c \
get_next_line_sl/get_next_line_utils.c \
miniLibft_sl/ft_atoi.c \
miniLibft_sl/ft_bzero.c \
miniLibft_sl/ft_calloc.c \
miniLibft_sl/ft_isalnum.c \
miniLibft_sl/ft_isalpha.c \
miniLibft_sl/ft_isascii.c \
miniLibft_sl/ft_isdigit.c \
miniLibft_sl/ft_isprint.c \
miniLibft_sl/ft_itoa.c \
miniLibft_sl/ft_lstadd_back_bonus.c \
miniLibft_sl/ft_lstadd_front_bonus.c \
miniLibft_sl/ft_lstclear_bonus.c \
miniLibft_sl/ft_lstdelone_bonus.c \
miniLibft_sl/ft_lstiter_bonus.c \
miniLibft_sl/ft_lstlast_bonus.c \
miniLibft_sl/ft_lstmap_bonus.c \
miniLibft_sl/ft_lstnew_bonus.c \
miniLibft_sl/ft_lstsize_bonus.c \
miniLibft_sl/ft_memchr.c \
miniLibft_sl/ft_memcmp.c \
miniLibft_sl/ft_memcpy.c \
miniLibft_sl/ft_memmove.c \
miniLibft_sl/ft_memset.c \
miniLibft_sl/ft_putchar_fd.c \
miniLibft_sl/ft_putendl_fd.c \
miniLibft_sl/ft_putnbr_fd.c \
miniLibft_sl/ft_putstr_fd.c \
miniLibft_sl/ft_split.c \
miniLibft_sl/ft_strchr.c \
miniLibft_sl/ft_strdup.c \
miniLibft_sl/ft_striteri.c \
miniLibft_sl/ft_strjoin.c \
miniLibft_sl/ft_strlcat.c \
miniLibft_sl/ft_strlcpy.c \
miniLibft_sl/ft_strlen.c \
miniLibft_sl/ft_strmapi.c \
miniLibft_sl/ft_strncmp.c \
miniLibft_sl/ft_strnstr.c \
miniLibft_sl/ft_strrchr.c \
miniLibft_sl/ft_strtrim.c \
miniLibft_sl/ft_substr.c \
miniLibft_sl/ft_tolower.c \
miniLibft_sl/ft_toupper.c \
miniLibft_sl/ft_free_split.c

OBJS 	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

O_DIR	=	Objs

CC	=	gcc -Wall -Wextra -Werror

NAME 	=	libft.a

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(O_DIR)/${<:.c=.o} -I

${NAME}:	${OBJS}
	@	ar rc ${NAME} ${OBJS}
	@	echo "\n\033[92m[Libft COMPILED SUCCESSFULY]\033\n[0m"

all:		${NAME}

clean:
	@	rm -rf ${O_DIR}

fclean:		clean
	@	rm -f ${NAME}
	@	echo "\n\033[31m[Libft DELETED]\033\n"

re:		fclean all

.PHONY:	all clean fclean re
