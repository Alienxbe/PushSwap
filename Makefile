# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marykman <marykman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 11:09:13 by mykman            #+#    #+#              #
#    Updated: 2024/08/30 23:41:52 by marykman         ###   ########.fr        #
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
NAME_CHECKER		:=	checker

# Headers files
FILES				:=	moves.h \
						solve.h \
						utils.h
HEADERS				:=	$(addprefix includes/, ${FILES});

# C files
SRCS_MOVES			:=	ft_get_move_value.c \
						ft_move.c \
						ft_push.c \
						ft_reverse_moves.c \
						ft_rotate.c \
						ft_rrotate.c \
						ft_swap.c \
						rotate_top.c
SRCS_UTILS			:=	fill_stack.c \
						is_sorted.c \
						ft_abs.c
SRCS_SOLVER			:=	main.c \
						ft_cost.c \
						ft_minstack.c \
						ft_solve.c \
						get_smallest_cost.c \
						ft_solve_small.c
SRCS_CHECKER		:=	main.c

OBJS_COMMON			:=	$(addprefix objs/common/moves/, ${SRCS_MOVES:.c=.o})
OBJS_COMMON			+=	$(addprefix objs/common/utils/, ${SRCS_UTILS:.c=.o})
OBJS_SOLVER			:=	$(addprefix objs/solver/, ${SRCS_SOLVER:.c=.o})
OBJS_CHECKER		:=	$(addprefix objs/checker/, ${SRCS_CHECKER:.c=.o})

# -----------------------------------Rules-------------------------------------

objs/%.o:	srcs/%.c
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@
	@echo "${PREFIX}Compilation of $<..."

$(NAME):	${FT} ${OBJS_COMMON} ${OBJS_SOLVER} ${HEADERS}
	${CC} ${CFLAGS} ${OBJS_COMMON} ${OBJS_SOLVER} ${LIBRARIES} -o $@
	@echo "${PREFIX}$@ Compiled !"

$(NAME_CHECKER):	${FT} ${OBJS_COMMON} ${OBJS_CHECKER} ${HEADERS}
	${CC} ${CFLAGS} ${OBJS_COMMON} ${OBJS_CHECKER} ${LIBRARIES} -o $@
	@echo "${PREFIX}$@ Compiled !"

$(FT):
	${MAKE_FT}

all:	${NAME}

bonus:	${NAME_CHECKER}

clean:
	${RM} ${OBJS_COMMON} ${OBJS_SOLVER} ${OBJS_CHECKER}
	${MAKE_FT} clean

fclean:
	${RM} ${OBJS_COMMON} ${OBJS_SOLVER} ${OBJS_CHECKER} ${NAME} ${NAME_CHECKER}
	${MAKE_FT} fclean

re:		fclean all

# -----------------------------------.PHONY------------------------------------

.PHONY:	all clean fclean re
