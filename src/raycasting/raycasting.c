#include "../../include/cube3d.h"

void	ray_casting(t_data *data)
{
	int	i;
	float	wall_height;
	int j;
	int up;
	int down;
	int color;
	float ugol;

	i = 0;
	j = WITH - 1;
	while (i < WITH)
	{
		ugol = fabsf(data->player.direction - data->ray[j].direction);
		wall_height = DISTANSE_OF * 600 / (data->ray[j].len * cosf(ugol));
		up = HEIGHT_2;
		down = HEIGHT_2;
		wall_height  *= 4;
		color = 0x200772;
		if(data->ray[j].wall_direction == 'N')
			color = 0x5CCCCC;
		if(data->ray[j].wall_direction == 'S')
			color = 0xFFD773;
		if(data->ray[j].wall_direction == 'E')
			color = 0xD25FD2;
		if(data->ray[j].wall_direction == 'W')
			color = 0xE5FB71;
		while (wall_height >= 0)
		{
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, up, color);
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, down, color);
			up--;
			down++;
			wall_height -= (float)(DISTANSE_OF);
		}
		i++;
		j--;
	}
}