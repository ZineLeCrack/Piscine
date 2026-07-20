NAME = ft_hexdump

CC = cc -Wall -Wextra -Werror -g3

SRCS = ft_utils.c ft_hexa.c ft_hexdump.c main.c
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
