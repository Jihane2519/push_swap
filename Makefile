NAME = push_swap
BONUS = checker_bonus

CC = cc
CFLAGS= -Wall -Wextra -Werror

SRC= \
     parsing/parse.c \
     parsing/ft_split.c \
     parsing/parse_utils.c \
     parsing/fstrjoin.c \
     parsing/error.c \
     operation/push.c \
     operation/reverse_rotate.c \
     operation/rotate.c \
     operation/swap.c \
     algo/is_sorted.c \
     algo/sort_five.c \
     algo/sort_three.c \
     algo/sort_chunks.c\
     algo/stack_size.c \
     algo/help_chunks.c \

SRC_PS = main.c

SRC_BONUS = bonus/checker.c  \
	    bonus/checker_apply.c \
	    gnl/get_next_line.c \
	    gnl/get_next_line_utils.c

OBJ         = $(SRC:.c=.o)
OBJ_PS      = $(SRC_PS:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

all:$(NAME)

$(NAME):$(OBJ) $(OBJ_PS)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_PS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) -o $(BONUS)

clean:
	rm -f $(OBJ) $(OBJ_PS) $(OBJ_BONUS)

fclean:clean
	rm -f $(NAME) $(BONUS)

re:fclean all

.PHONY:all bonus clean fclean re

