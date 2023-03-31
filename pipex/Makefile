SOURCES = main.c

SOURCESUTILS =	parse.c

SOURCESUTILSF = $(addprefix sources/, $(SOURCESUTILS))

OBJECTS = $(SOURCES:.c=.o)

OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Iincs -O3 -c $< -o $@

NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -Iincs #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) -o $(NAME)

clean:
	@rm -f *.o sources/*.o

fclean: clean
	@rm -f pipex

re: fclean all

.PHONY: all bonus re clean fclean