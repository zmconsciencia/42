SOURCES = main.c

SOURCESPARSE = parse.c \
				init.c \
				time.c

SOURCESDINNER = free.c \
				threads.c \
				unalive.c

SOURCESUTILS =	ft_atoi.c \
				ft_strlen.c \
				ft_calloc.c

SOURCESUTILSF = $(addprefix SRCS/UTILS/, $(SOURCESUTILS))

SOURCESPARSEF = $(addprefix SRCS/PARSE/, $(SOURCESPARSE))

SOURCESDINNERF = $(addprefix SRCS/DINNER/, $(SOURCESDINNER))

OBJECTS = $(SOURCES:.c=.o)

OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

OBJECTSPARSE = $(SOURCESPARSEF:.c=.o)

OBJECTSDINNER = $(SOURCESDINNERF:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -pthread -IINCS -c $< -o $@

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -pthread -IINCS #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSPARSE) $(OBJECTSDINNER)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSPARSE) $(OBJECTSDINNER) -o $(NAME)

clean:
	@rm -f SRCS/*/*.o *.o

fclean: clean
	@rm -f philo

re: fclean all

.PHONY: all bonus re clean fclean