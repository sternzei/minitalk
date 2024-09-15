# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 18:50:06 by ezeper            #+#    #+#              #
#    Updated: 2024/07/30 13:45:28 by ezeper           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_CLIENT = client.c
SRCS_SERVER = server.c 
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): client server

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o client

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o server

clean:
	$(RM) -f $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -f client server
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
