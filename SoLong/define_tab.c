#include "header.h"

static int	define_tab3(t_coord *c, char **argv)
{
	c->tab.tab_dupp_coilhead_moove = tab_creator(argv[1], c->l, c->c);
	if (!c->tab.tab_dupp_coilhead_moove)
	{
		ft_printf("Error\nMalloc Fail at 'define_struct' \
		for tab_dupp_coilhead_moove");
		return (0);
	}
	c->tab.tab_tiles = tab_creator(argv[1], c->l, c->c);
	if (!c->tab.tab_tiles)
	{
		ft_printf("Error\nMalloc Fail at 'tab_creator' for tab_tiles");
		return (0);
	}
	c->tab.tab_dup_monsterspawn = tab_creator(argv[1], c->l, c->c);
	if (!c->tab.tab_dup_monsterspawn)
	{
		ft_printf("Error\nMalloc Fail at 'tab_creator' for \
		tab_dup_monsterspawn");
		return (0);
	}
	return (1);
}

static int	define_tab2(t_coord *c, char **argv)
{
	c->tab.tab_dupp_coilhead_moove_left = tab_creator(argv[1], c->l, c->c);
	if (!c->tab.tab_dupp_coilhead_moove_left)
	{
		ft_printf("Error\nMalloc Fail at 'define_struct' for \
		tab_dupp_coilhead_moove_left");
		return (0);
	}
	c->tab.tab_dupp_coilhead_moove_down = tab_creator(argv[1], c->l, c->c);
	if (!c->tab.tab_dupp_coilhead_moove_down)
	{
		ft_printf("Error\nMalloc Fail at 'define_struct' for \
		tab.tab_dupp_coilhead_moove_dow");
		return (0);
	}
	if (define_tab3(c, argv) == 0)
		return (0);
	return (1);
}


int	define_tab(t_coord *c, char **argv)
{
	c->tab.tab_0_1 = tab_creator(argv[1], c->l, c->c);
	if (!c->tab.tab_0_1)
	{
		ft_printf("Error\nMalloc Fail at 'define_struct' \
		for tab_0_1");
		return (0);
	}
	c->tab.tab_dupp_coilhead_moove_up = tab_creator(argv[1], c->l, c->c);
	if (!c->tab.tab_dupp_coilhead_moove_up)
	{
		ft_printf("Error\nMalloc Fail at 'define_struct' for \
		tab_dupp_coilhead_moove_up");
		return (0);
	}
	c->tab.tab_dupp_coilhead_moove_right = tab_creator(argv[1], c->l, c->c);
	if (!c->tab.tab_dupp_coilhead_moove_right)
	{
		ft_printf("Error\nMalloc Fail at 'define_struct' for \
		tab_dupp_coilhead_moove_righ");
		return (0);
	}
	if (define_tab2(c, argv) == 0)
		return (0);
	return (1);
}
