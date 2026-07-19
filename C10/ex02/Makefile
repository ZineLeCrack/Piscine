NAME = ft_tail

CC = cc -Wall -Wextra -Werror -g3

SRCS = ft_putstr_fd.c ft_strlen.c ft_strtoul.c ft_utils.c ft_tail.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
