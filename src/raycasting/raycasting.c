#include "../../include/cube3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * (img->x_sz * 4) + x * 4);
	*(unsigned int *)dst = color;
}

int get_color(t_img *texture, float x_in_wall, float one_step_in_y, int up_down)
{
	char			*dst;
	unsigned int 	color;
	int 			x;
	int 			y;
	(void)up_down;


	y = (int)(64 * one_step_in_y);
//	printf("y = %d; up_down = %d; one_step_in_y = %f\n", y, up_down, one_step_in_y);
	x = (int)((x_in_wall/15) * 64);
	if (x > 63 || y > 63 || x < 0 || y < 0)
		return (0xffffff);
	dst = texture->adr + (y * (texture->x_sz * 4) + x * 4);
	color = *(unsigned int *)dst;
	return ((int)color);
}

int	get_color_pixel_texture(t_data *data, int y, int j, float wall_height)
{
	int color;
	float one_step_in_y;


	one_step_in_y = HEIGHT - y / (wall_height / DISTANSE_OF);
	if(data->ray[j].wall_direction == 'N')
		color = get_color(&data->imgs.no, data->ray[j].left_sprite_dist, one_step_in_y, y);
	if(data->ray[j].wall_direction == 'S')
		color = get_color(&data->imgs.so, data->ray[j].left_sprite_dist, one_step_in_y, y);
	if(data->ray[j].wall_direction == 'E')
		color = get_color(&data->imgs.ea, data->ray[j].left_sprite_dist, one_step_in_y, y);
	if(data->ray[j].wall_direction == 'W')
		color = get_color(&data->imgs.we, data->ray[j].left_sprite_dist, one_step_in_y, y);
	return (color);
}

void	ray_casting(t_data *data)
{
	int	i;
	float	wall_height;
	float 	wall_h;
	int j;
//	int up;
	int down;
	int color_down;
	int color_up;
	float ugol;

	i = 0;
	j = WITH - 1;
	while (i < WITH - 1)
	{
		ugol = fabsf(data->player.direction - data->ray[j].direction);
		wall_height = DISTANSE_OF * 600 / (data->ray[j].len * cosf(ugol));
//		up = HEIGHT_2;
		wall_height *= 4;
		down = (int)((float)HEIGHT - wall_height) / 2;
		wall_h = wall_height;
		printf("WALL SIZE x = %d; y = %d; Wall = %f\n", data->imgs.wall.x_sz, data->imgs.wall.y_sz, wall_height / DISTANSE_OF);
//		color = 0x200772;
//		if(data->ray[j].wall_direction == 'N')
//			color = 0x5CCCCC;
//		if(data->ray[j].wall_direction == 'S')
//			color = 0xFFD773;
//		if(data->ray[j].wall_direction == 'E')
//			color = 0xD25FD2;
//		if(data->ray[j].wall_direction == 'W')
//			color = 0xE5FB71;
		while (wall_height >= 0)
		{
//			color_up = get_color_pixel_texture(data, up, j, wall_h);
			color_down = get_color_pixel_texture(data,down, j, wall_h);
//			my_mlx_pixel_put(&data->imgs.wall, i, up, color_up);
			my_mlx_pixel_put(&data->imgs.wall, i, down, color_down);
//			if (up == 0)
//				break;
//			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, up, color);
//			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, i, down, color);
//			up--;
			down++;
			wall_height -= (float)(DISTANSE_OF);
		}
		i++;
		j--;
	}
}