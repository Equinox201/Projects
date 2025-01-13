
NAME = push_swap
cc = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_linkedlist.c \
		ft_input_validation.c \
		ft_find_order.c \
		ft_assign_pivot.c \
		ft_sort_three.c \
		ft_sort_rest.c \
		ft_push_back.c \
		ft_swap.c \
		ft_rotation.c \
		ft_reverse_rotation.c \
		ft_push.c \
		ft_push_swap.c \
				
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
