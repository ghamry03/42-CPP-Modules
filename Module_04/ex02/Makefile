NAME		=	Animal

SRCS		=	main.cpp			\
				Animal.cpp			\
				AAnimal.cpp			\
				Cat.cpp				\
				Dog.cpp				\
				Brain.cpp			\

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

