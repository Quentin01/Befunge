##
## Makefile for befunge in /home/buathi_q/Github
## 
## Made by BUATHIER Quentin
## Login   <buathi_q@epitech.net>
## 
## Started on  Mon Jan 27 13:23:16 2014 BUATHIER Quentin
## Last update Mon Jan 27 13:24:42 2014 BUATHIER Quentin
##

CC = gcc
CFLAGS = -Wall -Werror

NAME = befunge

SRCS = $(wildcard src/*.c)
OBJS = $(addprefix obj/,$(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<  -I ./include/

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
