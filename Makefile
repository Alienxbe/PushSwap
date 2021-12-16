# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 11:09:13 by mykman            #+#    #+#              #
#    Updated: 2021/12/16 15:26:14 by mykman           ###   ########.fr        #
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
CHECKER_NAME	:=	checker
LIBFT			:=	Libft/
LIBFT_NAME		:=	libft.a

# FILES
MANDATORY_MAIN	:=	push_swap.c
CHECKER_MAIN	:=	checker.c
SRCS_OP			:=	operations.c \
					push.c \
					rotate.c \
					rrotate.c \
					swap.c
SRCS_SOLVE		:=	solve.c
SRCS_UTILS		:=	errors.c \
					print.c \
					setup.c
OBJS			:=	$(addprefix srcs/operations/, ${SRCS_OP:.c=.o})
OBJS			+=	$(addprefix srcs/solve/, ${SRCS_SOLVE:.c=.o})
OBJS			+=	$(addprefix srcs/utils/, ${SRCS_UTILS:.c=.o})
OBJS_MANDATORY	:=	$(addprefix srcs/, ${MANDATORY_MAIN:.c=.o}) ${OBJS}
OBJS_CHECKER	:=	$(addprefix srcs/, ${CHECKER_MAIN:.c=.o}) ${OBJS}

# RULES
%.o:			%.c
	${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}
	@echo "${PREFIX}Compilation of $<..."

$(NAME):		${OBJS_MANDATORY} ${LIBFT_NAME}
	${CC} ${CFLAGS} $^ -o $@
	@echo "${PREFIX}${GREEN}Executable compiled!${RESET}"

$(CHECKER_NAME):	${OBJS_CHECKER} ${LIBFT_NAME}
	${CC} ${CFLAGS} $^ -o ${CHECKER_NAME}
	@echo "${PREFIX}${GREEN}Checker compiled!${RESET}"

$(LIBFT_NAME):	update
	@make -s -C ${LIBFT} NAME=../${LIBFT_NAME}

all:			${NAME}

install:
	@echo "${PREFIX}${GREEN}Installing ${LIBFT}!${RESET}"
	@git clone https://github.com/Alienxbe/Libft.git

update:
	@if [ ! -d ${LIBFT} ]; then make install; fi
	@git -C ${LIBFT} pull

clean:
	@make -s -C ${LIBFT} NAME=../${LIBFT_NAME} clean
	@rm -f ${OBJS_CHECKER} ${OBJS_MANDATORY}
	@echo "${PREFIX}${BLUE}Cleaning object files...${RESET}"

fclean:
	@make -s -C ${LIBFT} NAME=../${LIBFT_NAME} fclean
	@rm -f ${NAME} ${CHECKER_NAME} ${LIBFT_NAME} ${OBJS_CHECKER} ${OBJS_MANDATORY}
	@echo "${PREFIX}${RED}Full clean.${RESET}"

re:				fclean all

.PHONY:			all install clean fclean re update