
NAME = philo
cc = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=thread

SRCS =	ft_operations.c \
		ft_monitor.c \
		ft_parse.c \
		ft_philo.c \
		ft_time.c \
		ft_utils.c \
				
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
