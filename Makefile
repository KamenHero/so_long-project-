NAME = so_long
NAME_BONUS = so_long_bonus
cc = cc
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra -I ./libft

SRCS = 	so_long.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		readmap.c\
		utils.c\
		utils2.c\
		checking.c\
		showing.c\
		moving.c\
		movingdirec.c\

SRCS_BONUS = ./bonus/so_long_bonus.c\
			gnl/get_next_line.c\
			gnl/get_next_line_utils.c\
			readmap.c\
			utils.c\
			utils2.c\
			./bonus/checkingbonus.c\
			./bonus/showing_bonus.c\
			./bonus/movingbonus.c\
			./bonus/movingdirecbonus.c\
			./bonus/movingnormal.c\
			./bonus/animations.c\

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(OBJ) ./libft/libft.a $(MLXFLAGS)  -o $(NAME)

bonus: $(OBJ_BONUS)
	make -C ./libft
	make bonus -C ./libft
	gcc $(OBJ_BONUS) ./libft/libft.a $(MLXFLAGS) -o $(NAME_BONUS)

clean:
	make clean -C ./libft
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re
