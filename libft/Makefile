NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_SRCS = ft_isalnum.c \
				ft_lstiter.c \
				ft_isalpha.c \
				ft_putendl_fd.c \
				ft_atoi.c \
				ft_strdup.c \
				ft_lstnew.c \
				ft_strnstr.c \
				ft_lstadd_front.c \
				ft_isascii.c \
				ft_memcpy.c \
				ft_striteri.c \
				ft_memchr.c \
				ft_putnbr_fd.c \
				ft_lstclear.c \
				ft_memcmp.c \
				ft_strncmp.c \
				ft_putstr_fd.c \
				ft_toupper.c \
				ft_strlcpy.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_lstdelone.c \
				ft_lstadd_back.c \
				ft_isdigit.c \
				ft_tolower.c \
				ft_memset.c \
				ft_strrchr.c \
				ft_strlen.c \
				ft_lstmap.c \
				ft_bzero.c \
				ft_strchr.c \
				ft_isprint.c \
				ft_substr.c \
				ft_calloc.c \
				ft_memmove.c \
				ft_itoa.c \
				ft_split.c \
				ft_lstlast.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_lstsize.c \
				ft_strtrim.c \

GNL_SRCS = get_next_line_bonus.c \
				get_next_line_utils_bonus.c

PRINTF_SRCS = ft_convs2.c \
				ft_convs.c \
				ft_printf.c 

LIBFT_OBJS = $(addprefix srcs/libft/, $(LIBFT_SRCS:=.o))
PRINTF_OBJS = $(addprefix srcs/printf/, $(PRINTF_SRCS:=.o))
GNL_OBJS = $(addprefix srcs/gnl/, $(GNL_SRCS:=.o))
OBJS = ${LIBFT_OBJS} ${GNL_OBJS} ${PRINTF_OBJS}

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJ) $(B_OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re

.SILENT: ${OBJS}