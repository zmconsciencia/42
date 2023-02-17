SOURCES = main.c

SOURCESUTILS = 

SOURCESUTILSF = $(addprefix utils/, $(SOURCESUTILS))

OBJECTS = $(SOURCES:.c=.o)

OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_Linux -O3 -c $< -o $@

NAME = graph

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -f *.o utils/*.o

fclean: clean
	@rm -f push_swap

re: fclean all