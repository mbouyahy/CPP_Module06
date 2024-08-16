SRCS =	main.cpp ScalarConverter.cpp utiles.cpp Converter.cpp PrintData.cpp

OBJS =	${SRCS:.cpp=.o}

NAME =	convert

RM =	rm -f

CC =	c++

FLAGS =	-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS} ScalarConverter.hpp
		 ${CC} -o ${NAME} ${OBJS} ${FLAGS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re