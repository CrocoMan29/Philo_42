# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 01:35:03 by yismaail          #+#    #+#              #
#    Updated: 2023/06/05 05:21:06 by yismaail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			=	cc
CFLAGS		=	-Werror -Wextra -Wall -fsanitize=thread 
RM			=	rm -rf
SRCS		=	main.c check_args.c helper.c routine.c simulation.c
				
OBJS		= ${SRCS:.c=.o}

all			:	$(NAME)

$(NAME)		: $(OBJS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
			
clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re