SOURCES = main.c

SOURCESUTILS =	mlx_utils.c \
				map.c \
				map_check.c \
				additionals.c \
				path.c \
				load.c \
				canva.c \
				collision_handle.c \
				initialize.c \
				map_checker.c \
				collision_add.c \
				ft_free.c

SOURCEGNL =	get_next_line.c \
			get_next_line_utils.c

SOURCESUTILSF = $(addprefix utils/, $(SOURCESUTILS))

SOURCEGNLF = $(addprefix gnl/, $(SOURCEGNL))

OBJECTS = $(SOURCES:.c=.o)

OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

OBJECTSGNL = $(SOURCEGNLF:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx_Linux -Iincs -O3 -c $< -o $@

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -Iincs -Imlx_Linux #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSGNL)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSGNL) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -f *.o utils/*.o gnl/*.o

fclean: clean
	@rm -f so_long

re: fclean all