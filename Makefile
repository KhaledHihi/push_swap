NAME = push_swap
SRC = main.c split.c create_node.c add_node_back.c ft_atoi.c print_node.c operations.c  \
		ft_check.c list_size.c oper2.c sort_five_three.c sort_list.c push_swap.c\

OBJ = $(SRC:.c=.o)

CC = cc
# FLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		 $(CC)  $(OBJ) -o push_swap

%.o : %.c
	$(CC)  -c -o $@ $^

clean :
		@$(RM) $(OBJ)

fclean : clean
		@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
.SECONDARY : $(OBJ)
