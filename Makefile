# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 12:19:53 by jvalkama          #+#    #+#              #
#    Updated: 2025/05/08 14:25:26 by jvalkama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_printf.c ft_puthex.c ft_putunsigned.c

OBJS			= $(SRCS:%.c=%.o)

HEADER			= ft_printf_header.h

LIBFT_H			= $(LIBFT_PATH)/libft.h

LIBFT_PATH		= libft

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -I $(LIBFT_PATH)

RM				= rm -f

NAME			= libftprintf.a

all:			sub-make copy-libft $(NAME)

copy-libft:		
				@echo "Moving and renaming libft.a to parent dir"
				mv libft/libft.a libftprintf.a

$(NAME):		$(OBJS)
					@echo "Creating library $(NAME)"
					ar -rcs $(NAME) $(OBJS)

%.o:			%.c $(HEADER) $(LIBFT_H)
					@echo "Compiling $<"
					$(CC) $(CFLAGS) -c $< -o $@

sub-make:
					make -C $(LIBFT_PATH)

clean:
					@echo "Cleaning object files"
					@$(RM) $(OBJS)

fclean:			clean
					@echo "Cleaning library"
					@$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re sub-make copy_libft
