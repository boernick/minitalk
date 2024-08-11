CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_NAME = client
SERVER_NAME = server
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I $(PRINTF_DIR) -I $(LIBFT_DIR)

all: $(PRINTF) $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJS) $(PRINTF) $(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJS) $(PRINTF) $(LIBFT) -o $(SERVER_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
