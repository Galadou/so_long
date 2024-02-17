COMP		= clang
CFLAGS		= -Wall -Werror -Wextra -I./MacroLibX/includes -I./libft/includes -g
MLXFLAGS	= -lSDL2
NAME		= so_long

SRC		= main.c\
		game.c\
		map_to_tab.c\
		map_transform.c\
		define_struct.c\
		put_asked_img.c\
		destroy_img.c\
		action_touch.c\
		light_front.c\
		light_hide.c\
		is_obj_here.c\
		is_exit_here.c\
		more_fonction.c\
		Monster.c\
		m_coilhead_moove.c\
		update_coilhead.c\
		kill_player.c

#Les verifications
SRC+=	verif_a_map.c\
		verif_if_dotber.c\
		verif_rectangle.c\
		verif_one_and_zero.c\
		verif_player_can_exit.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make --directory ./libft
	@make --directory ./MacroLibX
	@$(COMP) $(CFLAGS) $(OBJS) libft/libft.a $(MLXFLAGS) MacroLibX/libmlx.so -o $@
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
	fi


%.o : %.c
	$(COMP) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all
