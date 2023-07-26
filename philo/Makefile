SOURCES = main.c

SOURCESPARSE = parse.c \
				init.c

SOURCESUTILS =	ft_atoi.c \
				ft_itoa.c \
				ft_strlen.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_strdup.c \
				ft_calloc.c

SOURCESUTILSF = $(addprefix SRCS/UTILS/, $(SOURCESUTILS))

SOURCESPARSEF = $(addprefix SRCS/PARSE/, $(SOURCESPARSE))

OBJECTS = $(SOURCES:.c=.o)

OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

OBJECTSPARSE = $(SOURCESPARSEF:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -pthread -IINCS -c $< -o $@

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -pthread -IINCS #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSPARSE)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSPARSE) -o $(NAME)

clean:
	@rm -f SRCS/*/*.o *.o

fclean: clean
	@rm -f philo

re: fclean all

.PHONY: all bonus re clean fclean