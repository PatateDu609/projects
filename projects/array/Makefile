SRCS		= array.cpp access.cpp operators.cpp operations.cpp
INCLUDE		= array.h
LIBS		= -larray -lalgorithms
OBJS		= ${SRCS:.cpp=.o}
CC			= g++
CFLAGS		= -Wall -Werror -Wextra -fPIC -Wno-write-strings
NAME		= /home/teyber/Libs/libarray.so
RM			= rm -f
INC_PATH	:= $(shell echo ${NAME} | sed -E "s/Libs/Includes/" | sed -E "s/(lib|.so)//g")

${NAME}:	${OBJS}
		${CC} -shared ${OBJS} -o ${NAME}

all:		${NAME}

${OBJS}:
		${CC} ${CFLAGS} -I$(INCLUDES) -c ${SRCS}

clean:
		${RM} ${OBJS} test

fclean:		clean
		${RM} -r ${NAME} $(INCLUDES)/${INCLUDE} ${INC_PATH}

test:		main.cpp
		${CC} -o test main.cpp -L$(LD_LIBRARY_PATH) ${LIBS} -I$(INCLUDES) -Wno-write-strings

re:			fclean all

install:
		mkdir ${INC_PATH}
		cp ./${SRCS} ${INC_PATH}
		cp ${INCLUDE} ${INCLUDES}/${INCLUDE}

.PHONY:		re fclean all clean