NAME = Iter
SRC =  main.cpp 
INCLUDES = iter.hpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -std=c++98  -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean

