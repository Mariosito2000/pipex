# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 16:14:13 by marias-e          #+#    #+#              #
#    Updated: 2023/02/20 16:16:38 by marias-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)

BONUS_SRCS	=	$(wildcard *.c)

OBJS 	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

BONUS_OBJS	=	$(addprefix $(BO_DIR)/, $(BONUS_SRCS:.c=.o))

O_DIR	=	OBJS

BO_DIR	=	BONUS_OBJS

CC	=	gcc -Wall -Wextra -Werror

NAME 	=	pipex

NAME_BONUS	=	pipex_bonus

L_DIR	=	Libft/

LIBFT	=	$(addprefix $(L_DIR), libft.a)

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(O_DIR)/${<:.c=.o} -I

$(BO_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(BO_DIR)/${<:.c=.o} -I

all:		$(LIBFT) ${NAME}

bonus:		$(LIBFT) $(NAME_BONUS)

$(LIBFT):
	@make -C $(L_DIR)

${NAME}:	${OBJS}
	@	$(CC) $(OBJS) -o ${NAME} $(LIBFT)
	@	echo "\n\033[92m["pipex" COMPILED SUCCESSFULY]\033\n"

${NAME_BONUS}: 	${BONUS_OBJS}
	@	$(CC) $(BONUS_OBJS) -o ${NAME_BONUS} $(LIBFT)
	@	echo "\n\033[92m["pipex_bonus" COMPILED SUCCESSFULY]\033\n"


clean:
	@	rm -rf ${O_DIR} rm -rf ${BO_DIR} && cd $(L_DIR) && $(MAKE) clean
	@	echo "\n\033[31m[Objs DELETED]\033\n"

fclean:		clean
	@	rm -rf ${O_DIR} rm -rf ${BO_DIR} rm push_swap rm checker && cd $(L_DIR) && $(MAKE) fclean
	@	echo "\n\033[31m[FCLEAN DONE]\033\n"

re:		fclean all

.PHONY:	all clean fclean re bonus
