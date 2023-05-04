NAME = cub3D

GCC = cc

SRC = main.c gnl/get_next_line.c gnl/get_next_line_utils.c parser/elements_parser.c parser/parsing_helpers.c parser/map_parser.c fonctions/get_tab.c \
	fonctions/get_char.c fonctions/ft_strlen.c fonctions/ft_split.c fonctions/ft_strtrim.c fonctions/ft_strdup.c fonctions/ft_strncmp.c

all : $(NAME)

$(NAME) : $(SRC)
	@gcc $(SRC) -Wall -Werror -Wextra -o $(NAME) -g #-fsanitize=address
	@echo "\033[1;32m game is ready !"



clean :
		@rm -f $(NAME)
		@echo "\033[1;32m File cleaned !"

fclean : 
		@rm -f $(NAME)
		@echo "\033[1;32m File cleaned !"

re : fclean all