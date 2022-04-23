#include "../../include/cube3d.h"

void	ray_casting(t_data *data)
{
	int	i;
	int j;
	int line_height;
	int up;
	int down;
//	float coof;

	i = 0;
	while (i < WITH)
	{
		line_height = (int)((float)HEIGHT / (float)data->ray[i].len);
		up = HEIGHT / 2;
		down = HEIGHT / 2;
		j = 0;
		while (j < line_height / 2)
		{
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, up, 0x11cc03);
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, down, 0x11cc03);
			j++;
			up--;
			down++;
		}
		i++;
	}
}