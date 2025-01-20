NAME = push_swap
SRC = main.c helper_files/split.c helper_files/create_node.c helper_files/add_node_back.c helper_files/ft_atoi.c helper_files/print_node.c algo/operations.c  \
		helper_files/ft_check.c helper_files/list_size.c algo/oper2.c algo/sort_five_three.c algo/sort_list.c algo/push_swap.c\

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
