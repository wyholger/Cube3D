HEADER	=	libft.h

NAME	=	libft.a

SRCS	=	ft_atoi.c\
            ft_atoi_base.c\
            ft_bzero.c\
            ft_calloc.c\
            ft_isalnum.c\
            ft_isalpha.c\
            ft_isascii.c\
            ft_isdigit.c\
            ft_isprint.c\
            ft_itoa.c\
            ft_lstadd_back.c\
            ft_lstadd_front.c\
            ft_lstclear.c\
            ft_lstdelone.c\
            ft_lstiter.c\
            ft_lstlast.c\
            ft_lstnew.c\
            ft_lstprint_content.c\
            ft_lstsize.c\
            ft_memccpy.c\
            ft_memchr.c\
            ft_memcmp.c\
            ft_memcpy.c\
            ft_memmove.c\
            ft_memset.c\
            ft_putchar_fd.c\
            ft_putendl_fd.c\
            ft_putnbr_fd.c\
            ft_putstr_fd.c\
            ft_search_word_in_str_on_end.c\
            ft_split.c\
            ft_strchr.c\
            ft_strcmp.c\
            ft_strcmp_end.c\
            ft_strcpy.c\
            ft_strdup.c\
            ft_strjoin.c\
            ft_strlcat.c\
            ft_strlcpy.c\
            ft_strlen.c\
            ft_strmapi.c\
            ft_strncmp.c\
            ft_strnstr.c\
            ft_strrchr.c\
            ft_strtrim.c\
            ft_strtrim_start.c\
            ft_substr.c\
            ft_tolower.c\
            ft_toupper.c\
            get_next_line.c\

OBJS 	= $(SRCS:.c=.o)

AR 		= ar rcs

CC		= gcc

FLAGS 	= -Wall -Wextra -Werror -g

RM		= rm -f



.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) Makefile
		$(AR) $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONI: all clean fclean re bonus
