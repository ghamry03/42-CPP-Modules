NAME		=	Animal

SRCS		=	main.cpp			\
				Animal.cpp			\
				Cat.cpp				\
				Dog.cpp				\
				WrongAnimal.cpp		\
				WrongCat.cpp		\

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

RM			=	rm -f

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

