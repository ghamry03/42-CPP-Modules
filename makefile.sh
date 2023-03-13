#!/bin/bash

# check number of arguments
if [ $# -ne 1 ]; then
    echo "Wrong number of arguments, try ./script programName"
    exit 1
fi

programName=$1

# check if Makefile already exists
if [ -f "$PWD/Makefile" ]; then
    echo "Makeile already exists"
    exit 1
fi

echo 'NAME		=	'"$programName"'

SRCS		=	main.cpp			\

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -Wconversion -std=c++98

RM			=	rm -f

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
' >> Makefile
