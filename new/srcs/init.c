#include "fdf.h"

void	init_point(t_point *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = 0xFFFFFF;
}

void	init_img(t_env *e)
{
	free(e->img);
	e->img = mlx_new_image(e->mlx, e->win_width, e->win_height);
	e->data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size, &e->endian);
}

int		init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win_width = WIDTH;
	e->win_height = HEIGHT;
	e->o.bres = 0;
	e->scale = ((e->win_width / e->o.width) + (e->win_height / e->o.height)) / 4;
	e->origin.x = (e->win_width / 2) - ((e->o.width * e->scale) / 2);
	e->origin.y = (e->win_height / 2) - ((e->o.height * e->scale) / 2);
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "win");
	e->o.pitch = 1;
	e->axe = 0;
	e->color = 0xFFFFFF;
	return (0);
}
