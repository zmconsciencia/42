SOURCES = main.c

SOURCESUTILS = sort.c \
				ft_atoi.c \
				moves.c \
				cost_add.c \
				errors.c \
				cost.c \
				add_node.c \
				ft_split.c \
				ft_convs2.c \
				ft_convs.c \
				ft_printf.c \
				additionals.c

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