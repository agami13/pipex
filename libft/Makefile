SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c ft_strchr.c ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
					ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c \
					ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c  \
					ft_split.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_strjoin.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					get_next_line.c get_next_line_utils.c \
					ft_putchar.c ft_putstr.c ft_putnbr.c ft_putptr.c \
					ft_printhex.c ft_printf.c ft_print_unsigned.c \
		
BONUS_SRC			= ft_lstnew_bonus.c \
					  ft_lstadd_front_bonus.c \
					  ft_lstsize_bonus.c \
					  ft_lstlast_bonus.c \
					  ft_lstadd_back_bonus.c \
					  ft_lstdelone_bonus.c \
					  ft_lstclear_bonus.c \
					  ft_lstiter_bonus.c \
					  ft_lstmap_bonus.c
				  
OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
AR				= ar
ARF				= -rc

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS) 

%.o : %.c
				$(CC) -c $(CFLAGS) $<
				$(AR) $(ARF) $(NAME) $@

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
