# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 10:52:21 by vgoret            #+#    #+#              #
#    Updated: 2023/06/13 14:10:46 by vgoret           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ! ARGUMENTS ! #

NAME    =	pipex
CCFLAGS =	-g -Wall -Werror -Wextra
CC      =	gcc

################################################################################
# * SRC * #

SRC = ./src/pipex.c \
	./src/printer.c \
	./src/processes.c \
	./src/exec_cmd.c \

OBJ = ${SRC:.c=.o}

################################################################################
# ? RULES ? #

NONE='\033[0m'
CLIGNO = '\033[5m'
GREEN='\033[32m'
RED='\033[31m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BOLD='\033[1m'
BLUE='\033[0;34m'

all: ${NAME} title

${NAME} : ${OBJ}
	@echo ${BOLD} ${GRAY} "○	Making LIBFT..." ${NONE}
	@make -C src/libft
	@echo ${BOLD} ${BLUE} "\033[1m○	Compiling files..." ${NONE}
	$(CC) ${OBJ} ${CCFLAGS} ./src/libft/libft.a -o $@
	@echo ${BOLD} ${GREEN} "‣	Compiled !\n" ${NONE}
	@touch file1
	@touch file2

%.o: %.c
	@$(CC) ${CCFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean: clean	
	@echo ${RED} ${BOLD} "‣	Deleting..." ${NONE}
	@rm -f src/libft/libft.a
	@rm -f src/libft/*.o
	@rm -f ${PROG}
	@rm -f ${OBJ}
	@${foreach value, $(OBJ), echo ${value};}
	@rm -f ${NAME}
	@rm -f ./a.out
	rm file1
	rm file2
	@echo ${RED} ${BOLD} "\n‣ Folder Cleaned Sucessfully" ${NONE}

re : fclean all

.PHONY : all clean fclean all re

################################################################################
# TODO  UTILS   TODO #

fclean_util : 
	@echo "\\033[1;31m DELETED\\033[0;39m"
	@tput sgr0;
	@${foreach value, $(OBJ), echo "\\033[1;31m >> \\033[0;39m" ${value};}
	@${foreach value, $(NAME), echo "\\033[1;31m >> \\033[0;39m" ${value};} 
	@echo "⣿⣷⡶⠚⠉⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠠⣴⣿⣿⣿⣿⣶⣤⣤⣤\n⠿⠥⢶⡏⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⢀⣴⣷⣌⢿⣿⣿⣿⣿⣿⣿⣿\n⣍⡛⢷⣠⣿⣿⣿⣿⣿⣟⠻⣯⠽⣿⣿⠟⠁⣠⠿⠿⣿⣿⣎⠻⣿⣿⣿⡿⠟⣿\n⣿⣿⣦⠙⣿⣿⣿⣿⣿⣿⣷⣏⡧⠙⠁⣀⢾⣧    ⠈⣿⡟  ⠙⣫⣵⣶⠇⣋\n⣿⣿⣿⢀⣿⣿⣿⣿⣿⣿⣿⠟⠃⢀⣀⢻⣎⢻⣷⣤⣴⠟  ⣠⣾⣿⢟⣵⡆⢿\n⣿⣯⣄⢘⢻⣿⣿⣿⣿⡟⠁⢀⣤⡙⢿⣴⣿⣷⡉⠉⢀  ⣴⣿⡿⣡⣿⣿⡿⢆\n⠿⣿⣧⣤⡘⢿⣿⣿⠏  ⡔⠉⠉⢻⣦⠻⣿⣿⣶⣾⡟⣼⣿⣿⣱⣿⡿⢫⣾⣿\n⣷⣮⣝⣛⣃⡉⣿⡏  ⣾⣧⡀    ⣿⡇⢘⣿⠋    ⠻⣿⣿⣿⢟⣵⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣌⢧⣴⣘⢿⣿⣶⣾⡿⠁⢠⠿⠁⠜    ⣿⣿⣿⣿⡿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣦⡙⣿⣷⣉⡛⠋    ⣰⣾⣦⣤⣤⣤⣿⢿⠟⢋⣴⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣌⢿⣿⣿⣿⣿⢰⡿⣻⣿⣿⣿⣿⣿⢃⣰⣫⣾⣿⣿⣿\n⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠿⠿⠿⠛⢰⣾⡿⢟⣭⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"

title :
	@echo ${BOLD}${GREEN}" __     __   ___\n|__) | |__) |__  \_/\n|    | |    |___ / \ \n"
                     

