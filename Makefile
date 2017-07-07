NAME = rtv

FLAGS = -Wall -Wextra -Werror -g -O3

MLX = -lmlx -framework OpenGL -framework AppKit

LIB = libft/libft.a

SRCS =	main.c				\
		hooks.c				\
		init.c				\
		read_scene.c

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

$(NAME): $(BINS)
	make -C libft
	gcc -o $(NAME) $(BINS) $(FLAGS) $(MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BINS)

fclean: libfclean clean
	/bin/rm -f $(NAME)

re: fclean all
