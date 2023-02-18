NAME = fractol

CFLAGS = -Wall -Wextra -Werror

SRC =	main.c\
		parsing.c\
		libft.c\
		fractol_sets.c \
		mlx.c\

OBJ = $(SRC:.c=.o)

INCLUDES = fractol.h

all: $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -Imlx -g -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -ofast -o $(NAME) -g

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

bonus: all
  