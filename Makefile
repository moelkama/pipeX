OBJS = src/pipex.o src/ft_split.o src/findpath.o

BONUS_OBJS = bonus/src/pipex_bonus.o bonus/src/ft_split_bonus.o bonus/src/findpath_bonus.o\
			 bonus/src/pipex_utilse_bonus.o bonus/src/get_next_line_bonus.o\
			 bonus/src/get_next_line_utils_bonus.o

NAME = pipex
FLAGS = -Wall -Wextra -Werror

moelkama = $(OBJS)

all:
	@ $(MAKE) $(NAME) moelkama="$(OBJS)"

bonus:
	@ $(MAKE) $(NAME) moelkama="$(BONUS_OBJS)"

$(NAME):$(moelkama)
	CC $(FLAGS) $(moelkama) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re