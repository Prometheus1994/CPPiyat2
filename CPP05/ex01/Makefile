NAME = form
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ -std=c++98 -Wall -Werror -Wextra $(OBJS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp Form.hpp
	c++ -std=c++98 -Wall -Werror -Wextra -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean