SOURCES = main.c

SOURCESUTILS = ft_split.c ft_atoi.c add_node.c errors.c moves.c sort.c cost.c cost_add.c

SOURCESUTILSF = $(addprefix utils/, $(SOURCESUTILS))

OBJECTS = $(SOURCES:.c=.o)
OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) $(OBJECTSSORT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) $(OBJECTSSORT) -o $(NAME)

clean:
	@rm -f *.o utils/*.o

fclean: clean
	@rm -f push_swap

re: fclean all