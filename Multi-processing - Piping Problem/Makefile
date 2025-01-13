# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsamarin <nsamarin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 11:21:21 by nsamarin          #+#    #+#              #
#    Updated: 2024/10/25 13:56:42 by nsamarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
cc = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	ft_struct.c \
		ft_envar.c \
		ft_fds.c \
		ft_gnl_utils.c \
		ft_gnl.c \
		ft_parent_child.c \
		ft_pipex.c \
		ft_split.c \
		ft_utils_two.c \
		ft_utils.c 
				
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
