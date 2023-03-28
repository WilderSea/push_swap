# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 10:17:37 by msintas-          #+#    #+#              #
#    Updated: 2023/01/22 19:43:11 by msintas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	push_swap.c push_swap_validate.c push_swap_utils.c basic_moves.c \
			push_swap_tools.c push_moves.c push_swap_sorting.c push_swap_free.c

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

LIBFT_PATH	=	./Libft

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT_PATH) --silent
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/libft.a -o $(NAME)

clean:
			make -C $(LIBFT_PATH) clean
			$(RM) $(OBJS)

fclean:		
			make -C $(LIBFT_PATH) fclean
			$(RM) $(OBJS) $(NAME)

re:			fclean all


.PHONY:		all clean fclean re