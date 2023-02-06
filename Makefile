NAME = fractol

CFLAGS = -Wall -Wextra -Werror

SRC = 	parsing.c\
		fractol_sets.c \
		mlx.c\

LIBFT = libft/libft.a

PATH_LIBFT = libft

OBJ = $(SRC:.c=.o)

INCLUDES = fractol.h

all: $(NAME)

${LIBFT}	:
	make -C ${PATH_LIBFT}

%.o : %.c $(INCLUDES) ${LIBFT}
	$(CC) $(CFLAGS) -Imlx -g -c $< -o $@

$(NAME): $(OBJ) ${LIBFT}
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)  $(LIBFT) -g

clean:
	$(RM) $(OBJ)
	make clean -C ${PATH_LIBFT}

fclean: clean
	$(RM) $(NAME)
	make fclean -C ${PATH_LIBFT}

re: fclean all
