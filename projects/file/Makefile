SRCS		= file.cpp access.cpp operators.cpp operations.cpp
INCLUDE		= file.h
LIBS		= -lfile
OBJS		= ${SRCS:.cpp=.o}
CC			= g++
CFLAGS		= -Wall -Werror -Wextra -fPIC -Wno-write-strings
NAME		= /home/teyber/Libs/libfile.so
RM			= rm -f
INC_PATH	:= $(shell echo ${NAME} | sed -E "s/Libs/Includes/" | sed -E "s/(lib|.so)//g")

${NAME}:	${OBJS}
		${CC} -shared ${OBJS} -o ${NAME}

all:		${NAME}

${OBJS}:
		${CC} ${CFLAGS} -c ${SRCS}

clean:
		${RM} ${OBJS} test

fclean:		clean
		${RM} -r ${NAME} $(INCLUDES)/${INCLUDE} ${INC_PATH}

test:		${NAME}
		${CC} -o test main.cpp -L$(LD_LIBRARY_PATH) ${LIBS} -I$(INCLUDES) -Wno-write-strings -fsanitize=address -fsanitize=leak

install:
		mkdir ${INC_PATH}
		cp ./${SRCS} ${INC_PATH}
		cp ${INCLUDE} ${INCLUDES}/${INCLUDE}

re:			fclean all

.PHONY:		re fclean all clean