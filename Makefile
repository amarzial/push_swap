SHARED_SRCS = handler.c \
			  mystack.c \
			  mystack_ops.c \
			  utils.c

CHECKER_SRCS = checker.c
PUSH_SWAP_SRCS = push_swap.c

vpath %.c ./srcs

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
CHECKER = checker
PUSH_SWAP = push_swap
LIBFT = ./libft/libft.a

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(CHECKER_SRCS:.c=.o) $(SHARED_SRCS:.c=.o) $(LIBFT)
	$(CC) -o $(CHECKER) $(CHECKER_SRCS:.c=.o) $(SHARED_SRCS:.c=.o) -L $(dir $(LIBFT)) -lft

$(PUSH_SWAP): $(PUSH_SWAP_SRCS:.c=.o) $(SHARED_SRCS:.c=.o) $(LIBFT)
	$(CC) -o $(PUSH_SWAP) $(PUSH_SWAP_SRCS:.c=.o) $(SHARED_SRCS:.c=.o) -L $(dir $(LIBFT)) -lft

$(LIBFT):
	make -C $(dir $(LIBFT))

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $< -I ./includes/ -I $(addsuffix includes/, $(dir $(LIBFT)))

clean:
	rm -f $(SHARED_SRCS:.c=.o)
	rm -f $(PUSH_SWAP_SRCS:.c=.o)
	rm -f $(CHECKER_SRCS:.c=.o)
	make -C $(dir $(LIBFT)) clean

fclean: clean
	rm -f $(CHECKER)
	rm -f $(PUSH_SWAP)
	make -C $(dir $(LIBFT)) fclean

re: fclean all
