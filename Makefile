# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbaghdas <tbaghdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 18:02:31 by tbaghdas          #+#    #+#              #
#    Updated: 2025/03/01 18:02:32 by tbaghdas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CFILES	=  ft_printf.c ft_print_digit.c ft_print_alpha.c \

OFILES	= $(CFILES:.c=.o)

NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c	$(libftprintf.a) Makefile
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES) 

clean:
	rm -f $(OFILES) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re