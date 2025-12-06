# Detectar si estamos en Windows (mingw32-make en cmd)
ifeq ($(OS),Windows_NT)
	RM  = del /Q
	EXE = .exe
else
	RM  = rm -f
	EXE =
endif

NAME    = BraiiiiiiinnnzzzZ$(EXE)

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	-$(RM) $(OBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
