# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 02:01:45 by gmersch           #+#    #+#              #
#    Updated: 2024/01/30 19:03:37 by gmersch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP		= gcc
CFLAGS		= -Wall -Werror -Wextra -g
NAME		= libft.a

SRC		= ft_atoi.c\
		ft_isdigit.c\
		ft_memmove.c\
		ft_strlen.c\
		ft_toupper.c\
		ft_bzero.c\
		ft_isprint.c\
		ft_memset.c\
		ft_strncmp.c\
		ft_isalnum.c\
		ft_memchr.c\
		ft_strchr.c\
		ft_strnstr.c\
		ft_isalpha.c\
		ft_memcmp.c\
		ft_strlcat.c\
		ft_strrchr.c\
		ft_isascii.c\
		ft_memcpy.c\
		ft_strlcpy.c\
		ft_tolower.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_strjoin.c\
		ft_strmapi.c\
		ft_split.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_striteri.c

SRC+= ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c
		
SRC+= get_next_line.c\
		get_next_line_utils.c

SRC+= ft_printf.c\
		hexa.c\
		ft_more_fonction.c\
		ft_more_fonction_2.c


OBJS = $(SRC:.c=.o)

ifdef value
	SRC+=$(BONUS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(COMP) $(CFLAGS) -c -Iincludes $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

re: fclean $(NAME)

.PHONY: clean fclean re all bonus
