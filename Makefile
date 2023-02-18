NAME = fractol

NAME_BONUS = fractol_bonus

CFLAGS = -Wall -Wextra

SRC =	Mandatory/main.c\
		Mandatory/parsing.c\
		Mandatory/libft.c\
		Mandatory/fractol_sets.c \
		Mandatory/mlx.c\

OBJ = $(SRC:.c=.o)

SRC_BONUS =	Bonus/main.c\
		Bonus/parsing.c\
		Bonus/libft.c\
		Bonus/fractol_sets.c \
		Bonus/mlx.c\

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = Mandatory/fractol.h

INCLUDES_BONUS = Bonus/fractol.h

all: $(NAME)

bonus :$(NAME_BONUS)

Mandatory/%.o: Mandatory/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

Bonus/%.o: Bonus/%.c $(INCLUDES_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -ofast -o $(NAME) -g

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -ofast -o $(NAME_BONUS) -g

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all
