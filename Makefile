# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marykman <marykman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 11:09:13 by mykman            #+#    #+#              #
#    Updated: 2023/11/10 21:35:23 by marykman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
LIGHT_BLUE		:=	\033[38;5;14m
RESET			:=	\033[38;5;7m
PREFIX			=	[${YELLOW}${NAME}${RESET}]\t

# ---------------------------------Compilation---------------------------------

CC					:=	@gcc
CFLAGS				:=	-Wall -Wextra -Werror
RM					:=	@rm -f

# ---------------------------------Librairies----------------------------------

FT_FOLDER			:=	libft

FT					:=	${FT_FOLDER}/libft.a

MAKE_FT				:=	@make -s -C ${FT_FOLDER}

INCLUDES			:=	-I ${FT_FOLDER}/includes \
						-I ./includes
LIBRARIES			:=	-L./${FT_FOLDER} -lft

# --------------------------------Source files---------------------------------

NAME				:=	push_swap

# Headers files
FILES				:=	push_swap.h
HEADERS				:=	$(addprefix includes/, ${FILES});

# C files
SRCS				:=	main.c
SRCS_MOVES			:=	ft_get_move_value.c \
						ft_move.c \
						ft_push.c \
						ft_reverse_moves.c \
						ft_rotate.c \
						ft_rrotate.c \
						ft_swap.c \
						rotate_top.c
SRCS_SOLVE			:=	ft_cost.c \
						ft_minstack.c \
						ft_solve.c \
						get_smallest_cost.c
SRCS_UTILS			:=	fill_stack.c \
						is_sorted.c \
						print_stack.c
OBJS				:=	$(addprefix objs/, ${SRCS:.c=.o})
OBJS				+=	$(addprefix objs/moves/, ${SRCS_MOVES:.c=.o})
OBJS				+=	$(addprefix objs/solve/, ${SRCS_SOLVE:.c=.o})
OBJS				+=	$(addprefix objs/utils/, ${SRCS_UTILS:.c=.o})

# -----------------------------------Rules-------------------------------------

objs/%.o:	srcs/%.c
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@
	@echo "${PREFIX}Compilation of $<..."

$(NAME):	${FT} ${OBJS} ${HEADERS}
	${CC} ${CFLAGS} ${OBJS} ${LIBRARIES} -o $@
	@echo "${PREFIX}$@ Compiled !"

$(FT):
	${MAKE_FT}

all:	${NAME}

clean:
	${RM} ${OBJS}
	${MAKE_FT} clean

fclean:
	${RM} ${OBJS} ${NAME}
	${MAKE_FT} fclean

re:		fclean all

# -----------------------------------.PHONY------------------------------------

.PHONY:	all clean fclean re
