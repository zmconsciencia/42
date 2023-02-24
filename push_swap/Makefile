SOURCES = main.c

SOURCESUTILS = sort.c \
				ft_atoi.c \
				moves.c \
				algorithmGeneral.c \
				parse.c \
				cost.c \
				listUtils.c \
				ft_split.c \
				ft_convs2.c \
				ft_convs.c \
				ft_printf.c \
				listUtils-2.c \
				additionals.c

SOURCESUTILSF = $(addprefix utils/, $(SOURCESUTILS))

OBJECTS = $(SOURCES:.c=.o)
OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g -I .

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) -o $(NAME)

clean:
	@rm -f *.o utils/*.o

fclean: clean
	@rm -f push_swap

re: fclean all