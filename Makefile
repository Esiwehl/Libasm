
NAME = libasm.a
TEST = libasm_test

HEADERS = libasm.h

SRCS = src/ft_strlen.s src/ft_write.s src/ft_read.s \
       src/ft_strcpy.s src/ft_strcmp.s src/ft_strdup.s

BONUS = src/ft_list_push_front_bonus.s \
        src/ft_list_size_bonus.s

OBJS = $(SRCS:.s=.o)
BONUS_OBJS = $(BONUS:.s=.o)

NASM = nasm -f elf64
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.s
	$(NASM) $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	$(AR) $(NAME) $(OBJS)

bonus: .bonus.stamp

.bonus.stamp: $(NAME) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	touch $@

test: $(TEST)

$(TEST): main.c $(NAME) bonus
	$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) .bonus.stamp

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all bonus test clean fclean re
