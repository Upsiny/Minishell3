# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:13:26 by tpaufert          #+#    #+#              #
#    Updated: 2024/05/24 18:50:35 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS    = ft_isalpha.c \
          ft_isdigit.c \
          ft_isalnum.c \
          ft_isascii.c \
          ft_isprint.c \
          ft_strlen.c \
          ft_memset.c \
          ft_bzero.c \
          ft_memcpy.c \
          ft_memmove.c \
          ft_strlcpy.c \
          ft_strlcat.c \
          ft_toupper.c \
          ft_tolower.c \
          ft_strchr.c \
          ft_strrchr.c \
          ft_strncmp.c \
          ft_memchr.c \
          ft_memcmp.c \
          ft_atoi.c \
          ft_strnstr.c \
          ft_calloc.c \
          ft_strdup.c \
          ft_strtrim.c \
          ft_substr.c \
          ft_strjoin.c \
          ft_split.c \
          ft_itoa.c \
          ft_strmapi.c \
          ft_striteri.c \
          ft_putchar_fd.c \
          ft_putstr_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c \
		  get_next_line.c \
		  get_next_line_utils.c \
          ft_lstnew_bonus.c \
          ft_lstadd_front_bonus.c \
          ft_lstsize_bonus.c \
          ft_lstlast_bonus.c \
          ft_lstadd_back_bonus.c \
          ft_lstdelone_bonus.c \
          ft_lstclear_bonus.c \
          ft_lstiter_bonus.c \
          ft_lstmap_bonus.c \

OBJS    = ${SRCS:.c=.o}

CC  = gcc

RM  = rm -f

CFLAGS  = -Wall -Wextra -Werror

NB_SRCS	=	$(words $(SRCS))

all:    ${NAME}



.c.o:
	@printf "\033[1mcompiling\033[0m: $<                                 \n"
	@printf "\033[33m |\033[0;2m"
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@printf "\033[0;1;33m|\033[0m⌛\r\033[2C\033[0;32m"
	@printf "*" >> .loading_bar
	@cat .loading_bar 2>/dev/null
	@printf "\033[0m\033[A\r"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@sleep 0.05

${NAME}:	${OBJS}
	@rm -rf .loading_bar
	@echo ""
	@printf "\033[33m |\033[32m"
	@printf "\033[${NB_SRCS}C"
	@echo "\033[0m\033[C✅ all compiled"
	@ar rc ${NAME} ${OBJS}
	@echo "\033[32mlibft compiled\033[0m"

clean:
	@echo "\033[31m removing libft object files\033[0m"
	@rm -rf .loading_bar
	@${RM} ${OBJS}

fclean: clean
	@echo "\033[1;31m removing libft.a\033[0m"
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
