NAME =	libasm.a
SRCS =	ft_strlen.asm	\
		ft_write		\

OBJS =	$(SRCS:.asm=.o)

NASM =	nasm -f elf64 
ar	 = 	ar rcs

all: $(NAME)

%.o		: %.asm
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
