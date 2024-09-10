# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:07:53 by hyeoan            #+#    #+#              #
#    Updated: 2023/01/09 16:15:36 by hyeoan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
NAME 		= libftprintf.a
AR          = ar rcs
RM          = rm -f
SOURCES		= ft_printf.c\
			  parse.c\
			  util.c\
			  print_char_percent.c\
			  print_string.c\
			  ft_itoa.c\
			  diuxp_util.c\
			  print_diux.c\
			  print_pointer.c

B_SOURCES	= ./bonus/ft_printf_bonus.c\
			  ./bonus/parse_bonus.c\
			  ./bonus/util_bonus.c\
			  ./bonus/print_char_percent_bonus.c\
			  ./bonus/print_string_bonus.c\
			  ./bonus/ft_itoa_bonus.c\
			  ./bonus/diuxp_util_bonus.c\
			  ./bonus/print_diux_bonus.c\
			  ./bonus/print_pointer_bonus.c
			  
OBJS	= $(SOURCES:.c=.o)
B_OBJS	= $(B_SOURCES:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(B_OBJS)
else
	OBJECTS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
bonus:
	make WITH_BONUS=1 all
clean:      
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus