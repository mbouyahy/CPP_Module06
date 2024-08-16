SRCS =	main.cpp Base.cpp

OBJS =	${SRCS:.cpp=.o}

NAME =	Base

RM =	rm -f

CC =	c++

FLAGS =	-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS} Base.hpp A.hpp B.hpp C.hpp
		 ${CC} -o ${NAME} ${OBJS} ${FLAGS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re