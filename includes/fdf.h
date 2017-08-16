#ifndef FDF_H
# define FDF_H

# define RED	= '0xFF0000'
# define GREEN	= '0x00FF00'
# define BLUE	= '0x0000FF'

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"

typedef struct s_params	t_params;
struct					s_params
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			color;
};

int						my_func(int keycode, t_params *param);
void					rectangle(t_params *param);
void					triangle_left(t_params *param);
void					triangle_right(t_params *param);
void					rectangle(t_params *param);

#endif
