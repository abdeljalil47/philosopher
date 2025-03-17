SRC = mendatory/error_exit.c mendatory/ft_parc_input.c mendatory/libr.c mendatory/philo.c mendatory/safe_allocate.c  mendatory/util.c
OBJ = $(SRC:.c=.o)
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = mendatory/philo.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ):%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re