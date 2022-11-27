# **************************************************************************** #
#	  #
#	 :::	  ::::::::	#
#	Makefile	   :+:	  :+:	:+:	#
#	 +:+ +:+	 +:+	  #
#	By: lucdos-s <lukas.facchi@gmail.com>	  +#+  +:+	   +#+	 #
#	 +#+#+#+#+#+   +#+	#
#	Created: 2022/11/04 11:13:39 by lucdos-s	  #+#	#+#	  #
#	Updated: 2022/11/04 11:13:39 by lucdos-s	 ###   ########.fr	#
#	  #
# **************************************************************************** #


.PHONY	= all clean fclean re

NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FT		= libft.a

SRCS	= main.c pipex.c error.c
OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} 42_libft/${FT} -o $@

${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${FT}

${OBJSDIR}/%.o: src/%.c src/pipex.h
	${CC} ${CFLAGS} -c $< -o $@

${FT}: | libft
	@${MAKE} -C 42_libft

libft:
	git clone https://github.com/lfacchi/42_libft.git

clean:
	${MAKE} clean -C 42_libft
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf 42_libft
	rm -f ${NAME}

re: fclean all