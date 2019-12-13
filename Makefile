# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 11:40:22 by fhenrion          #+#    #+#              #
#    Updated: 2019/12/10 15:54:28 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HDR_NAME = ft_printf.h

SRC_NAME = ft_printf option_functions parsing
SRC = $(addsuffix .c,$(SRC_NAME))
SRC_O = $(addsuffix .o,$(SRC_NAME))
PRINT_NAME = print_functions1 print_functions2
PRINT = $(addprefix ./print/,$(PRINT_NAME))
PRINT_SRC = $(addsuffix .c,$(PRINT))
PRINT_O = $(addsuffix .o,$(PRINT))
CONV_NAME = conv_functions1 conv_functions2
CONV = $(addprefix ./conv/,$(CONV_NAME))
CONV_SRC = $(addsuffix .c,$(CONV))
CONV_O = $(addsuffix .o,$(CONV))
UTILS_NAME = ft_atoi ft_itoa ft_utoa ft_itohex ft_putaddr utils
UTILS = $(addprefix ./utils/,$(UTILS_NAME))
UTILS_SRC = $(addsuffix .c,$(UTILS))
UTILS_O = $(addsuffix .o,$(UTILS))

CC = gcc
CFLAGS = -Werror -Wall -Wextra

.PHONY: clean fclean all re bonus

all: $(NAME)

$(NAME): $(SRC_O) $(PRINT_O) $(CONV_O) $(UTILS_O)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[0;32mLibrary Compilation OK\033[0m"

%.o : %.c ${HDR_NAME}
	$(CC) -c $(CFLAGS) -I $(HDR_NAME) $< -o $@

clean:
	@/bin/rm -f $(SRC_O) $(PRINT_O) $(CONV_O) $(UTILS_O)
	@echo "\033[0;32mObjects files cleaning OK\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;32mLibrary cleaning OK\033[0m"

re: fclean $(NAME)
