# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 11:16:15 by jkovacev          #+#    #+#              #
#    Updated: 2026/01/21 11:19:45 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = human

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	Weapon.hpp \
	Weapon.cpp \
	HumanA.hpp \
	HumanA.cpp \
	HumanB.hpp \
	HumanB.cpp

OBJDIR = objects
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

DEPS = Weapon.hpp \
	HumanA.hpp \
	HumanB.hpp

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