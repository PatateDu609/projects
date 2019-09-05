SRCS		= ft_putstr.cpp ft_putnbr.cpp ft_atoi.cpp ft_strlen.cpp ft_isspace.cpp
OBJS		= ${SRCS:.cpp=.o}
CC			= g++
CFLAGS		= -Wall -Werror -Wextra -fPIC -Wno-write-strings
NAME		= $(LD_LIBRARY_PATH)/libbasics.so
RM			= rm -f
INCLUDE		= basics.h

${NAME}:	${OBJS}
		${CC} -shared ${OBJS} -o ${NAME}
		cp ${INCLUDE} $(INCLUDES)/${INCLUDE}

all:		${NAME}

${OBJS}:
		${CC} ${CFLAGS} -c ${SRCS}

clean:
		${RM} ${OBJS} test

fclean:		clean
		${RM} ${NAME} $(INCLUDES)/${INCLUDE}

test:		${NAME}
		${CC} -o test main.cpp -L$(LD_LIBRARY_PATH) -lbasics -I$(INCLUDES) -Wno-write-strings

re:			fclean all

.PHONY:		re fclean all clean