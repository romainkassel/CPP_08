NAME = EasyFind

SRCS = ./srcs/


INCLUDES = -Iincludes

CPPFILES = 	$(SRCS)main.cpp \
			tests/testVector.cpp tests/testDeque.cpp tests/testList.cpp
OFILES = $(CPPFILES:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OFILES)
	$(CXX) -g -o $(NAME) $(OFILES)

$(SRCS)%.o: $(SRCS)%.cpp
	$(CXX) $(CXXFLAGS) -g -c -o $@ $< $(INCLUDES)

tests/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) -g -c -o $@ $< $(INCLUDES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re