NAME	=	pipex

SRCS	=	srcs/pipex.c \
			srcs/utils.c \
			srcs/processes.c \
			srcs/parsing.c

LIBFT	=	libft/libft.a

OBJ		=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra 

all		:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) -L -lft $(LIBFT) -o $(NAME)

%.o	 : %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -s -C libft/

clean:
		make clean -s -C libft
		rm -rf $(OBJ) $(BOBJ)

fclean: clean
		rm -rf $(NAME) $(NAME) $(CHECKER)
		make fclean -s -C libft

re:	fclean all

.PHONY: all clean fclean re