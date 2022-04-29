#include "../../include/cube3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > 1000 || y > 600)
		return;
	dst = img->adr + (y * (img->x_sz * 4) + x * 4);
	*(unsigned int *)dst = color;
}

int get_color(t_img *texture, float x_in_wall, float now, int up_down)
{
	char			*dst;
	unsigned int 	color;
	int 			x;
	int 			y;
	(void)up_down;


	y = (int)((float)now * 64);
//	printf("y = %d; up_down = %d; one_step_in_y = %f\n", y, up_down, one_step_in_y);
	x = (int)((x_in_wall/15) * 64);
	if (x > 63 || y > 63 || x < 0 || y < 0 || x == 0)
		return (0xffffff);
	dst = texture->adr + (y * (texture->x_sz * 4) + x * 4);
	color = *(unsigned int *)dst;
	return ((int)color);
}

int	get_color_pixel_texture(t_data *data, int y, int j, float now)
{
	int color;
//	float one_step_in_y;
	int start;
	int end;

	start = 300 - ((data->ray[j].wall_height /DISTANSE_OF) / 2);
	end = 300 + ((data->ray[j].wall_height /DISTANSE_OF) / 2);
	end = end - start;
	now = now / (float)end;
	color = 0xffffff;
	if(data->ray[j].wall_direction == 'N')
		color = get_color(&data->imgs.no, data->ray[j].left_sprite_dist, now, y);
	if(data->ray[j].wall_direction == 'S')
		color = get_color(&data->imgs.so, data->ray[j].left_sprite_dist, now, y);
	if(data->ray[j].wall_direction == 'E')
		color = get_color(&data->imgs.ea, data->ray[j].left_sprite_dist, now, y);
	if(data->ray[j].wall_direction == 'W')
		color = get_color(&data->imgs.we, data->ray[j].left_sprite_dist, now, y);
	return (color);
}

float	init_wall_h(t_data *data, int j)
{
	float 	ugol;
	float	wall_height;

	ugol = fabsf(data->player.direction - data->ray[j].direction);
	wall_height = 600 * ((float)DISTANSE_OF / ((data->ray[j].len) * cosf(ugol)));
	wall_height *= 20;
	return (wall_height);
}

void	ray_casting(t_data *data)
{
	int		i;
//	float	wall_height;
	float 	wall_h;
	int 	j;
	int 	down;
	int 	color_down;
	int 	now;

	i = 0;
	j = WITH - 1;
	while (i < WITH - 1)
	{
		data->ray[j].wall_height = init_wall_h(data, j);
		down = (int)((float)HEIGHT - data->ray[j].wall_height) / 2;
		wall_h = data->ray[j].wall_height;
		now = 0;
		while (wall_h >= 0)
		{
			color_down = get_color_pixel_texture(data,down, j, (float)now);
			my_mlx_pixel_put(&data->imgs.wall, i, down, color_down);
			down++;
			now++;
			wall_h -= (float)(DISTANSE_OF);
		}
		i++;
		j--;
	}
}