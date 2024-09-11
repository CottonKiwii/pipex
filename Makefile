# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 16:29:52 by jwolfram          #+#    #+#              #
#    Updated: 2024/09/11 18:47:47 by jwolfram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := cc

C_FLAGS := -Wall -Wextra -Werror

RM := rm -fr

INCLUDES := -I./includes/ -I./libft/includes

RED := \033[1;31m

GREEN := \033[1;32m

BLUE := \033[1;34m

DEFAULT := \033[0m

SRCS_DIR := src

SRCS_FILES := main \
			  init \

SRCS := ${SRCS_FILES:%=${SRCS_DIR}/%.c}

OBJS_DIR := obj

OBJS := ${SRCS_FILES:%=${OBJS_DIR}/%.o}

OBJS_SORT := ${sort ${dir ${OBJS}}}

LIBFT_DIR := libft

LIBFT_AR := libft/libft.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_AR}
	${CC} ${C_FLAGS} $^ ${INCLUDES} -o $@
	@echo "${GREEN}--------------------------${DEFAULT}"
	@echo "${GREEN}   COMPILATION COMPLETE   ${DEFAULT}"
	@echo "${GREEN}--------------------------${DEFAULT}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_SORT}
	${CC} ${CFLAGS} -g -c $< ${INCLUDES} -o $@

${LIBFT_AR}:
	${MAKE} -C ${LIBFT_DIR}

${OBJS_SORT}:
	mkdir -p $@

clean:
	${MAKE} $@ -C ${LIBFT_DIR}
	${RM} ${OBJS_DIR}
	@echo "${BLUE}--------------------------${DEFAULT}"
	@echo "${BLUE}     CLEANUP COMPLETE     ${DEFAULT}"
	@echo "${BLUE}--------------------------${DEFAULT}"

fclean: clean
	${MAKE} $@ -C ${LIBFT_DIR}
	${RM} ${NAME}

re: fclean all

norm:
	norminette ${SRCS}

print: 
	echo ${OBJS}

.PHONY: all clean fclean re norm print
