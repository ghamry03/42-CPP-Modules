NAME		=	Interface

SRCS		=	main.cpp			\
           		AMateria.cpp        \
           		Ice.cpp             \
           		Cure.cpp            \
           		Character.cpp       \
           		MateriaSource.cpp	\


OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -Wconversion -std=c++98 -g

RM			=	rm -f

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

