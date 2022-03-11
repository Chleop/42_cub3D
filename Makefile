# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:51:08 by avan-bre          #+#    #+#              #
#    Updated: 2022/03/11 15:09:57 by cproesch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################                                                            
#                                 COMPILATION                                  #                                                            
################################################################################ 

NAME	=	cub3D
LIBFT	=	libft/libft.a
RM		=	@rm -rf
CC		=	cc
IFLAGS	=	-I. -Ilibft
CFLAGS	=	-Wall -Werror -Wextra $(IFLAGS)
LFLAGS	=	-Llibft -lft


################################################################################                                                            
#                                 FILES                                        #                                                            
################################################################################  

SRCS	=	main.c parser.c utils.c 
OBJS	=	$(SRCS:.c=.o)

################################################################################                                                            
#                                 RULES                                        #                                                            
################################################################################  

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
		@echo "Compiling sources.."
		$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $@
		@echo "Ready!"

$(LIBFT):
		@echo "Compiling libft.."
		@make -s -C libft
		@echo "Libft ready!"

clean:
		$(RM) $(OBJS)
		@make $@ -s -C libft
		@echo "Removed objects"

fclean:         clean
		$(RM) $(NAME) ${B_NAME}
		@make $@ -s -C libft
		@echo "Removed executable files"

re:			fclean all

.PHONY:		re, all, clean, fclean
