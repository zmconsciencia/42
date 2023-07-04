SOURCES = SRCS/main.c

SOURCESUTILS =	ft_atoi.c \
				ft_itoa.c \
				ft_strlen.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_strdup.c

SOURCESUTILSF = $(addprefix SRCS/UTILS/, $(SOURCESUTILS))

OBJECTS = $(SOURCES:.c=.o)

OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -IINCS -c $< -o $@

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -IINCS #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) -o $(NAME)

clean:
	@rm -f SRCS/*.o SRCS/UTILS/*.o

fclean: clean
	@rm -f philo

re: fclean all

.PHONY: all bonus re clean fclean