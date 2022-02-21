NAME = libft.a
SRC := $(wildcard *.c)
C_EXECUTABLE :=$(SRC:.c=)
PTF = ft_printf/ft_printf ft_printf/transformers1 ft_printf/transformers2
CC =gcc
RM =rm -f
CFLAGS = -Wall -Wextra -Werror -I.

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

LIBFT_COMPILED	=	echo "\n📚 Libft compiled! \n$(NO_COLOR)";

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME):  $(C_EXECUTABLE:=.o) $(PTF:=.o) $(BONUS:=.o)
			ar rc $(NAME) $^
			@$(LIBFT_COMPILED)

clean:
	$(RM)	$(C_EXECUTABLE:=.o) $(BONUS:=.o) $(PTF:=.o)
	@$(CLEANED)
fclean: clean
	$(RM)	$(NAME)
	@$(FCLEANED)
re:	fclean all

.PHONY: all fclean clean re
