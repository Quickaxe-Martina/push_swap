# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmartina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 16:01:11 by qmartina          #+#    #+#              #
#    Updated: 2019/10/17 16:01:15 by qmartina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_CHECKER = 	checker

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)libft.h

SRC_DIR		=	src/
INC_DIR		=	inc
OBJ_DIR		=	objs/

SRC_BASE = \
    list_push_swap.c\
    error_ps.c\
    cheak.c\
    add_index.c\
    operations.c\
    operations1.c\
    operations2.c\
    sort.c\
    sort1.c\
    sort2.c\
    t1000.c\

SRC_PUSH_SWAP = push_swap.c

SRC_CHECKER = checker.c


SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE), $(SRC_CHECKER))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
OBJSPS      =   $(addprefix $(OBJ_DIR), $(SRC_PUSH_SWAP:.c=.o))
OBJSCH      =   $(addprefix $(OBJ_DIR), $(SRC_CHECKER:.c=.o))
NB			=	$(words $(SRC_BASE), $(SRC_CHECKER))
INDEX		=	0
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all :
	@make -C $(LIBFT_DIR)
	@make -j $(NAME)
	@make -j $(NAME_CHECKER)

$(NAME): $(LIBFT_LIB) $(OBJ_DIR) $(OBJS) $(OBJSPS)
	@$(CC) $(OBJS) $(OBJSPS) -o $(NAME) -I  $(INC_DIR) -I $(LIBFT_DIR) $(LIBS) $(LIBFT_LIB) $(FLAGS) $(D_FLAGS)
	@strip -x $@
	@echo "✅ $(GREEN)MAKE $(NAME)$(RESET)"

$(NAME_CHECKER): $(LIBFT_LIB) $(OBJ_DIR) $(OBJS) $(OBJSCH)
	@$(CC)  $(OBJS) $(OBJSCH) -o $(NAME_CHECKER) -I $(INC_DIR) -I $(LIBFT_DIR) $(LIBS) $(LIBFT_LIB) $(FLAGS) $(D_FLAGS)
	@strip -x $@
	@echo "✅ $(GREEN)MAKE $(NAME_CHECKER)$(RESET)"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c $(OBJ_DIR) inc/push_swap.h
	@$(CC) $(FLAGS) $(D_FLAGS) -MMD -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@echo "❌ $(RED)clean $(NAME) $(NAME_CHECKER)$(RESET)"

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME) $(NAME_CHECKER)
	@echo "❌ $(RED)fclean $(NAME) $(NAME_CHECKER) $(RESET)"

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib all

-include $(OBJS:.o=.d)