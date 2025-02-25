NAME = Zombie
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
INCLUDES = Zombie.hpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean
