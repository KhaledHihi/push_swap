NAME = checker_bonus

SRC = checker_bonus.c split.c create_node.c add_node_back.c ft_atoi.c print_node.c operations.c  \
		ft_check.c list_size.c oper2.c oper3.c  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c  \


OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
		 $(CC)  $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $^

clean :
		@$(RM) $(OBJ)

fclean : clean
		@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
.SECONDARY : $(OBJ)
