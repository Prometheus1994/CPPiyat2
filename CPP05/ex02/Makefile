NAME = form
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ -std=c++98 -Wall -Werror -Wextra $(OBJS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
	c++ -std=c++98 -Wall -Werror -Wextra -c $< -o $@

clean:
	rm -f $(OBJS)
	rm *_shrubbery

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	rm *_shrubbery

re: fclean all

.PHONY: clean fclean