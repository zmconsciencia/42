SOURCES = main.c

SOURCESUTILS =	

SOURCESUTILSF = $(addprefix sources/, $(SOURCESUTILS))

OBJECTS = $(SOURCES:.c=.o)

OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

OBJECTSGNL = $(SOURCEGNLF:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -Iincs

NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -Iincs #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSGNL)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) -o $(NAME)

clean:
	@rm -f *.o sources/*.o

fclean: clean
	@rm -f pipex

re: fclean all

.PHONY: all bonus re clean fclean