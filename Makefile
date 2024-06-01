# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 14:35:37 by hguillau          #+#    #+#              #
#    Updated: 2024/06/01 10:13:07 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=	src/main.c							\
				src/signaux/signaux.c				\
				src/errors/error.c					\
				src/errors/printf_error.c			\
				src/builtins/cd.c					\
				src/builtins/pwd.c					\
				src/builtins/echo.c					\
				src/builtins/exit.c					\
				src/builtins/env.c					\
				src/builtins/unset.c				\
				src/builtins/export_init.c			\
				src/builtins/export.c				\
				src/builtins/export_utils.c			\
				src/execution/utils_exec.c			\
				src/execution/redir_exec_builtins.c	\
				src/execution/utils.c				\
				src/execution/set_for_exec.c		\
				src/execution/exec.c				\
				src/lexer_parser/init.c				\
				src/lexer_parser/utils.c			\
				src/lexer_parser/lexer.c			\
				src/lexer_parser/redir.c			\
				src/lexer_parser/lexer_pipe.c		\
				src/lexer_parser/parsing.c			\
				src/lexer_parser/free_lexer.c		\
				src/lexer_parser/heredoc.c			\
				src/utils/free.c					\
				src/utils/ft_count_list.c			\
				src/utils/ft_strndup.c				\
				src/utils/tab_len.c					\
				src/utils/ft_cpytab.c				\
				src/utils/cmd_utils.c				\
				src/utils/get_in_env.c				\
				src/lexer_parser/lexer_str.c		\
				src/lexer_parser/replace_prompt.c	\
				src/lexer_parser/dollar.c			\
#				src/lexer_parser/lexer_alpha.c		\
#				src/lexer_parser/quotes.c			\
#				src/expender/expender.c				\#

OBJS    	=	${SRCS:.c=.o}

NAME    	=	minishell

LIBS		=	./src/libft/

#ifeq ($(USER), tpaufert)
#RL			=	-L/Users/$(USER)/.brew/Cellar/readline/8.2.1/lib -lreadline
#else
#RL			=	-L/opt/homebrew/opt/readline/lib -lreadline
#endif

CC      	=	gcc

RM      	=	rm -f

CFLAGS  	=	-Wall -Wextra -Werror -g -fsanitize=address

NB_SRCS	=	$(words $(SRCS))



all:		${NAME}

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
	@make all -C ${LIBS}
	@${CC} ${CFLAGS} ${OBJS} -L ${LIBS} -lft -lreadline -o ${NAME}
	@echo "\033[32mminishell compiled\033[0m"

clean:
	@echo "\033[31m removing minishell object files\033[0m"
	@rm -rf .loading_bar
	@make clean -C ${LIBS}
	@${RM} ${OBJS}

fclean:	clean
	@echo "\033[1;31m removing executable\033[0m"
	@make fclean -C ${LIBS}
	@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
