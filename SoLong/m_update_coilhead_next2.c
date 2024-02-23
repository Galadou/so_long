#include "header.h"

void	update_next_5(t_coord *co)
{
	if (co->coilhead.go_down == 1)
		head_moove_down(co);
	if (co->coilhead.go_up == 1)
		head_moove_up(co);
	if (co->coilhead.has_moove == 1 && co->coilhead.see_coilhead == 1)
		co->coilhead.has_moove = 0;
	if (co->coilhead.see_coilhead == 0)
	{
		update_coilhead_up(co);
		update_coilhead_left(co);
		update_coilhead_right(co);
		update_coilhead_down(co);
	}
}
