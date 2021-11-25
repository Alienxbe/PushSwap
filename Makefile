# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 11:09:13 by mykman            #+#    #+#              #
#    Updated: 2021/11/18 20:27:11 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC				=	@gcc
CFLAGS			=	-Wall -Wextra -Werror

RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
RESET			:=	\033[38;5;7m
PREFIX			=	[${YELLOW}${NAME}${RESET}]\t

# VARIABLES
NAME			:=	push_swap
LIBFT			:=	Libft/
LIBFT_NAME		:=	libft.a

# FILES
SRCS			:=	errors.c \
					push_swap.c \
					setup.c \
					solve.c
SRCS_OP			:=	operations.c \
					push.c \
					rotate.c \
					rrotate.c \
					swap.c
OBJS			:=	$(addprefix srcs/, ${SRCS:.c=.o})
OBJS			+=	$(addprefix srcs/operations/, ${SRCS_OP:.c=.o})

# RULES
%.o:			%.c
	${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}
	@echo "${PREFIX}Compilation of $<..."

$(NAME):		${OBJS} ${LIBFT_NAME}
	${CC} ${CFLAGS} $^ -o $@
	@echo "${PREFIX}${GREEN}Executable compiled!${RESET}"

all:			${NAME}

$(LIBFT_NAME):	update
	@make -C ${LIBFT} NAME=../${LIBFT_NAME}

install:
	@git clone https://github.com/Alienxbe/Libft.git

update:
	@git -C ${LIBFT} pull

clean:
	@make -C ${LIBFT} NAME=../${LIBFT_NAME} clean
	@rm -f ${OBJS}
	@echo "${PREFIX}${BLUE}Cleaning object files...${RESET}"

fclean:
	@make -C ${LIBFT} NAME=../${LIBFT_NAME} fclean
	@rm -f ${NAME} ${LIBFT_NAME} ${OBJS}
	@echo "${PREFIX}${RED}Full clean.${RESET}"

re:				fclean all

.PHONY:			all install clean fclean re