NAME    = phonebook
CXX     = c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror

SRCS    = main.cpp Contact.cpp PhoneBook.cpp
OBJDIR  = build
OBJS    = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	-$(RM) $(OBJS)
	-$(RM) -r $(OBJDIR)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
