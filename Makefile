# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 11:09:13 by mykman            #+#    #+#              #
#    Updated: 2021/10/27 11:30:42 by mykman           ###   ########.fr        #
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
LIBFT			:=	ft_lib/
LIBFT_NAME		:=	libft.a

# FILES
SRCS			:=	ft_operations.c \
					push_swap.c
OBJS			:=	$(addprefix srcs/, ${SRCS:.c=.o})

# RULES
%.o:			%.c
	${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}
	@echo "${PREFIX}Compilation of $<..."

$(NAME):		${OBJS} ${LIBFT_NAME}
	${CC} ${CFLAGS} $^ -o $@
	@echo "${PREFIX}${GREEN}Executable compiled!${RESET}"

all:			${NAME}

$(LIBFT_NAME):
	@make -C ${LIBFT}
	@mv ${LIBFT}/${LIBFT_NAME} ./

clean:
	@make -C ${LIBFT} clean
	@rm -f ${OBJS}
	@echo "${PREFIX}${BLUE}Cleaning object files...${RESET}"

fclean:
	@make -C ${LIBFT} fclean
	@rm -f ${NAME} ${LIBFT_NAME} ${OBJS}
	@echo "${PREFIX}${RED}Full clean.${RESET}"

re:				fclean all