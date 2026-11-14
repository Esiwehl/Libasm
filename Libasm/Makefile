NAME =	libasm.a
SRCS =	ft_strlen.s	\
		ft_write.s	\
		ft_read.s   \

OBJS =	$(SRCS:.s=.o)

NASM =	nasm -f elf64 
AR	 = 	ar rcs

all: $(NAME)

%.o		: %.s
# 	@echo Creating $(NAME) object: $@ "\x1b[1A\x1b[M"
	$(NASM) $< -o $@

$(NAME)	: $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean	:
	@rm -Rf $(OBJS)

fclean	: clean
	@rm -Rf $(NAME)

re		: fclean all

.PHONY	: clean fclean execute
