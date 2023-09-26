# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 15:23:02 by aherbet           #+#    #+#              #
#    Updated: 2023/07/06 06:08:12 by antoineherb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		coffee

SRCS =		main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS =		$(SRCS:.cpp=.o)

CFLAGS =	-Wall -Wextra -Werror -std=c++98

CC =		c++ $(CFLAGS)

RM =		rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $@
	@echo "[REPORT] $(NAME) assembled !"

%.o: %.cpp
	@$(CC) -c $< -o $@
	@echo "[REPORT] Object compiled !"

clean:
	@$(RM) $(OBJS)
	@echo "[REPORT] Objects cleaned !"

fclean: clean
	@$(RM) $(NAME)
	@echo "[REPORT] $(NAME) cleaned !"

re: fclean all

.PHONY: all clean fclean re