NAME = Serialization
SRC = Serializer.cpp main.cpp 
INCLUDES = Serializer.hpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = #-Wall -Wextra -Werror -std=c++98 #-fsanitize=address

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

