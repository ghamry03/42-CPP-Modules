NAME		=	Array

SRCS		=	main.cpp			\

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -Wconversion -std=c++98 -g3

RM			=	rm -f

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

