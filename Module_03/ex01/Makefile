NAME		=	ScavTrap

SRCS		=	main.cpp			\
				ClapTrap.cpp		\
				ScavTrap.cpp		\

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++

CXXFLAGS	=	-Wall -Werror=sign-conversion -Wextra -Wconversion -std=c++98

RM			=	rm -f

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

