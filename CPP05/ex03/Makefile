NAME    = ex03

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Iinclude

SRCS    = main.cpp \
          src/Bureaucrat.cpp src/AForm.cpp \
          src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp \
          src/PresidentialPardonForm.cpp src/Intern.cpp

OBJDIR  = build
OBJS    = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/src

clean:
	-$(RM) -r $(OBJDIR)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re