# ------------------------------ Sources ------------------------------
###### Files #####
CLIENT = sandbox_client
SERVER = sandbox_server
LIBFT = cd libft && make
LIB = libft/libft.a

###### OBJ ########
SRC_client = $(CLIENT)
SRC_server = $(SERVER)

###### NAME #######
client_name = client
server_name = server
NAME = server client

###### RULES ######
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

# ------------------------------ Rules ------------------------------

all: comp_start $(NAME)

comp_start:
	@$(COMP_START)
	@make -C libft
	
$(client_name) :
	$(CC) $(CFLAGS) sandbox_client.c libft/libft.a -o $(client_name)
	@$(CLI_READY)

$(server_name) : 
	$(CC) $(CFLAGS) sandbox_server.c libft/libft.a -o $(server_name)
	@$(SERV_READY)

clean:
	make clean -C ./libft

fclean: clean
	$(RM)	$(LIB)
	$(RM)	$(NAME)
	@$(FCLEANED)

re:	fclean	all

.PHONY: all fclean clean re
