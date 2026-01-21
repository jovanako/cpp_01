# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 08:25:06 by jkovacev          #+#    #+#              #
#    Updated: 2026/01/21 08:26:59 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	Zombie.cpp \
	zombieHorde.cpp

OBJDIR = objects
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

DEPS = Zombie.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(DEPS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re