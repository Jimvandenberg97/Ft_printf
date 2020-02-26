# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jivan-de <jivan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 11:23:43 by jivan-de       #+#    #+#                 #
#    Updated: 2020/01/07 15:20:10 by jivan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COM_COLOR   = \033[1;31m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m
OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
COM_STRING   = "Compiling"

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra -Ilibft
SOURCES =	main.c 

OBJECTS = $(SOURCES:.c=.o)
LIBFT = libft.a

LIBS	= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX		= libmlx.dylib

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJECTS)
	@printf "%b" "$(COM_COLOR)Building library: $(NO_COLOR)"
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\n$(NO_COLOR)"

$(LIBFT):
	@printf "%b" "$(COM_COLOR)Yeeting out LibFT...\n$(NO_COLOR)"
	@$(MAKE) -C libft
	@printf "%b" "$(COM_COLOR)Movind LibFT to root...\n$(NO_COLOR)"
	@cp libft/libft.a .
	@mv libft.a $(NAME)

$(MLX): @$(MAKE) -C mlx
		@cp mlx/mlx.dylib
		@mv mlx.dylib $(NAME)

%.o: %.c
	@$(CC) -c $(FLAGS) $< -o $@; \
        RESULT=$$?; \
        if [ $$RESULT -ne 0 ]; then \
            printf "%b %b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" \
				"$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		else  \
            printf "%b %b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" \
				"$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
        fi; \
        exit $$RESULT

clean:
	@$(MAKE) -C mlx libft fclean
	@printf "%b" "$(COM_COLOR)Cleaning up object files: $(NO_COLOR)"
	@$(RM) $(OBJECTS) a.out
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\n$(NO_COLOR)"

fclean: clean
	@printf "%b" "$(COM_COLOR)Cleaning up $(NAME): $(NO_COLOR)"
	@$(RM) $(NAME) $(MLX)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
