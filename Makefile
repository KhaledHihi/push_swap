NAME = push_swap
BNS_NAME = checker

SRC = main.c helper_files/split.c helper_files/create_node.c helper_files/add_node_back.c helper_files/ft_atoi.c helper_files/print_node.c algo/operations.c  \
		helper_files/ft_check.c helper_files/list_size.c algo/oper2.c algo/oper3.c algo/sort_five_three.c algo/sort_list.c algo/push_swap.c

BNS = bonus_files/checker_bonus.c bonus_files/split.c bonus_files/create_node.c bonus_files/add_node_back.c bonus_files/ft_atoi.c bonus_files/print_node.c bonus_files/operations.c  \
		bonus_files/ft_check.c bonus_files/list_size.c bonus_files/oper2.c bonus_files/oper3.c bonus_files/get_next_line.c bonus_files/get_next_line_utils.c bonus_files/parsing.c

OBJ = $(SRC:.c=.o)
BNS_OBJ = $(BNS:.c=.o)

FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(BNS_NAME): $(BNS_OBJ)
	$(CC) $(BNS_OBJ) -o $(BNS_NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

bonus: $(BNS_NAME)

clean:
	@$(RM) $(OBJ) $(BNS_OBJ)

fclean: clean
	@$(RM) $(NAME) $(BNS_NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY : $(OBJ) $(BNS_OBJ)
