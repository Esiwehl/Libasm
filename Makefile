NAME	= libasm_test
CC		= cc
CFLAGS	= -Wall -Werror -Wextra

SRC		= main.c
OBJ		= $(SRCS:.c=.o)

LIB_PATH = Libasm
LIB_NAME = libasm.a

all			: $(NAME)

$(NAME)		: $(LIB_NAME) $(SRC)
	@$(CC) $(CFLAGS) $(SRC) $(LIB_PATH)/$(LIB_NAME) -o $(NAME)

$(LIB_NAME)	:
	@make -C $(LIB_PATH)

clean		:
	@make -C $(LIB_PATH) clean
	@rm -Rf $(NAME)

fclean		: clean
	@make -C $(LIB_PATH) fclean

re			: fclean all

.PHONY		: all clean fclean re