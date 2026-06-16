NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ -std=c++98 -Wall -Werror -Wextra $(OBJS) -o $(NAME)

%.o: %.cpp PmergeMe.hpp
	c++ -std=c++98 -Wall -Werror -Wextra -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean