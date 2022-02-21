# ------------------------------ Sources ------------------------------
###### Files #####
CLIENT = client
SERVER = server
LIBFT = cd libft && make
LIB = libft/libft.a

###### OBJ ########
SRC_client = $(CLIENT)
SRC_server = $(SERVER)

###### NAME #######
client_name = sandbox_client.c
server_name = sandbox_server.c
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
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT) : sandbox_client.o
	$(CC) $(CFLAGS) sandbox_client.o libft/libft.a -o $(CLIENT)
	@$(CLI_READY)

$(SERVER) : sandbox_server.o
	$(CC) $(CFLAGS) sandbox_server.o libft/libft.a -o $(SERVER)
	@$(SERV_READY)

clean:
	$(RM)	sandbox_client.o sandbox_server.o
	@make clean -C ./libft

fclean: clean
	$(RM)	$(LIB)
	$(RM)	$(NAME)
	@$(FCLEANED)

re:	fclean	all

.PHONY: all fclean clean re
