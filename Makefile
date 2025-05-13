# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 12:19:53 by jvalkama          #+#    #+#              #
#    Updated: 2025/05/13 15:29:53 by jvalkama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			= ft_printf.c ft_puthex.c ft_putunsigned.c
OBJS			= $(SRCS:%.c=%.o)

HEADER			= ft_printf.h

LIBFT_A			= $(LIBFT_PATH)/libft.a
LIBFT_PATH		= libft

COMPILER		= cc
CFLAGS			= -Wall -Wextra -Werror
INCLUDE			= -I $(LIBFT_PATH)

RM				= rm -f

all:			$(NAME)

$(LIBFT_A):
				make -C $(LIBFT_PATH)

$(NAME):		$(OBJS) $(LIBFT_A)
					cp $(LIBFT_A) $(NAME)
					ar -rcs $(NAME) $(OBJS)

%.o:			%.c $(HEADER)
					@echo "Compiling $<"
					$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
					@echo "Cleaning object files in parent and libft"
					@$(RM) $(OBJS)
					make clean -C $(LIBFT_PATH)

fclean:			clean
					@echo "Cleaning library in parent and libft"
					@$(RM) $(NAME)
					make fclean -C $(LIBFT_PATH)

re:				fclean all

.PHONY: all clean fclean re
