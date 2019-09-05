SRCS		= list.cpp access.cpp operators.cpp operations.cpp
INCLUDE		= list.h
LIBS		= -llist -larray
OBJS		= ${SRCS:.cpp=.o}
CC			= g++
CFLAGS		= -Wall -Werror -Wextra -Wno-write-strings
NAME		= /home/teyber/Libs/liblist.so
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
		${CC} -o test main.cpp -L$(LD_LIBRARY_PATH) ${LIBS} -I$(INCLUDES) -I$(INC_PATH) -Wno-write-strings -fsanitize=leak -fsanitize=address -fno-omit-frame-pointer

install:
		mkdir ${INC_PATH}
		cp ./${SRCS} ${INC_PATH}
		cp ${INCLUDE} ${INCLUDES}/${INCLUDE}

re:			fclean all

.PHONY:		re fclean all clean