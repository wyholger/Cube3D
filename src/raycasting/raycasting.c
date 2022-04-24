#include "../../include/cube3d.h"

void	ray_casting(t_data *data)
{
	int	i;
	float	wall_height;
	int j;
////	int line_height;
	int up;
	int down;
////	float coof;
//
	i = 0;
	j = WITH;
	while (i < WITH)
	{
		wall_height = DISTANSE_OF * 600 / data->ray[j].len;
		up = HEIGHT_2;
		down = HEIGHT_2;
//		j = 0;
		while (wall_height >= 0)
		{
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, up, 0x92256E);
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, down, 0x92256E);
			up--;
			down++;
			wall_height -= (float)DISTANSE_OF;
		}
//		if (i % 50 == 0)
//			printf("wall_height %f, len = %f\n", wall_height, data->ray[i].len);
//		while (j < line_height / 2)
//		{
//			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, up, 0x11cc03);
//			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, down, 0x11cc03);
//			j++;
//			up--;
//			down++;
//		}
		i++;
		j--;
	}
}