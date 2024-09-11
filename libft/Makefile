# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 18:21:08 by jwolfram          #+#    #+#              #
#    Updated: 2024/06/03 22:36:33 by CottonKiwii      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

### COMPILATION ###

CC := cc

CFLAGS := -Wall -Werror -Wextra

AR := ar -rcs

RM := rm -fr

### LIBFT SOURCES ###

SRCS_DIR := src

SRCS_FILES := libft/ft_isalpha \
			  libft/ft_isdigit \
			  libft/ft_isalnum \
			  libft/ft_isascii \
			  libft/ft_isprint \
			  libft/ft_strlen \
			  libft/ft_memset \
			  libft/ft_bzero \
			  libft/ft_memcpy \
			  libft/ft_memmove \
			  libft/ft_strlcpy \
			  libft/ft_strlcat \
			  libft/ft_toupper \
			  libft/ft_tolower \
			  libft/ft_strchr \
			  libft/ft_strrchr \
			  libft/ft_strncmp \
			  libft/ft_memchr \
			  libft/ft_memcmp \
			  libft/ft_strnstr \
			  libft/ft_atoi \
			  libft/ft_calloc \
			  libft/ft_strdup \
			  libft/ft_substr \
			  libft/ft_strjoin \
			  libft/ft_strtrim \
			  libft/ft_split \
			  libft/ft_itoa \
			  libft/ft_putchar_fd \
			  libft/ft_putstr_fd \
			  libft/ft_putendl_fd \
			  libft/ft_putnbr_fd \
			  libft/ft_strmapi \
			  libft/ft_striteri \
			  libft/ft_lstnew_bonus \
			  libft/ft_lstadd_front_bonus \
			  libft/ft_lstsize_bonus \
			  libft/ft_lstlast_bonus \
			  libft/ft_lstadd_back_bonus \
			  libft/ft_lstdelone_bonus \
			  libft/ft_lstclear_bonus \
			  libft/ft_lstiter_bonus \
			  libft/ft_lstmap_bonus \
			  ft_printf/ft_printf \
			  ft_printf/ft_print_char \
			  ft_printf/ft_print_str \
			  ft_printf/ft_print_nbr \
			  ft_printf/ft_print_ptr \
			  ft_printf/ft_print_unsigned \
			  ft_printf/ft_print_hex \
			  get_next_line/get_next_line \

SRCS := ${SRCS_FILES:%=${SRCS_DIR}/%.c}

OBJS_DIR := obj

OBJS := ${SRCS_FILES:%=${OBJS_DIR}/%.o}

OBJS_SORT := ${sort ${dir ${OBJS}}}

INCLUDES := -I./includes

### LIBRARY COMMANDS ###

all: ${NAME}

${NAME}: ${OBJS} 
	${AR} ${NAME} ${OBJS} 

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_SORT}
	${CC} ${CFLAGS} $< ${INCLUDES} -c -o $@

${OBJS_SORT}:
	mkdir -p $@

### CLEANUP COMMANDS ###

clean:
	${RM} ${OBJS_DIR}

fclean: clean 
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
