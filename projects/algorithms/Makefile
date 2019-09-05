SRCS		= sort.cpp swap.cpp rev.cpp foreach.cpp any_of.cpp count_if.cpp find.cpp replace.cpp remove.cpp #unique.cpp shuffle.cpp
INCLUDE		= algorithms.h
LIBS		= -lalgorithms -lbasics
OBJS		= ${SRCS:.cpp=.o}
CC			= g++
CFLAGS		= -Wall -Werror -Wextra -fPIC
NAME		= /home/teyber/Libs/libalgorithms.so
RM			= rm -f
INC_PATH	:= $(shell echo ${NAME} | sed -E "s/Libs/Includes/" | sed -E "s/(lib|.so)//g")

${NAME}:	${OBJS}
		${CC} -shared ${OBJS} -o ${NAME}
		cp ${INCLUDE} $(INCLUDES)/${INCLUDE}

all:		${NAME}

${OBJS}:
		${CC} ${CFLAGS} -I$(INCLUDES) -c ${SRCS}

clean:
		${RM} ${OBJS} test

fclean:		clean
		${RM} -r ${NAME} $(INCLUDES)/${INCLUDE} ${INC_PATH}

test:
		${CC} -o test main.cpp -L$(LD_LIBRARY_PATH) ${LIBS} -I$(INCLUDES) -Wno-write-strings

install:
		mkdir ${INC_PATH}
		cp ./${SRCS} ${INC_PATH}
		cp ${INCLUDE} ${INCLUDES}/${INCLUDE}

re:			fclean all

.PHONY:		re fclean all clean