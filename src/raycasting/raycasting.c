/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:35:41 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:41:20 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > 1000 || y > 600)
		return ;
	dst = img->adr + (y * (img->x_sz * 4) + x * 4);
	*(unsigned int *)dst = color;
}

int	get_color(t_img *texture, float x_in_wall, float now)
{
	char			*dst;
	unsigned int	color;
	int				x;
	int				y;

	y = (int)((float)now * 64);
	x = (int)((x_in_wall / 15) * 64);
	if (x > 63 || y > 63 || x < 0 || y < 0 || x == 0)
		return (0xffffff);
	dst = texture->adr + (y * (texture->x_sz * 4) + x * 4);
	color = *(unsigned int *)dst;
	return ((int)color);
}

int	get_color_pixel_texture(t_data *data, int j, float now)
{
	int	color;
	int	start;
	int	end;

	start = HEIGHT_2 - ((data->ray[j].wall_height / DISTANSE_OF) / 2);
	end = HEIGHT_2 + ((data->ray[j].wall_height / DISTANSE_OF) / 2);
	end = end - start;
	now = now / (float)end;
	color = 0xffffff;
	if (data->ray[j].wall_direction == 'N')
		color = get_color(&data->imgs.no, data->ray[j].left_sprite_dist, now);
	if (data->ray[j].wall_direction == 'S')
		color = get_color(&data->imgs.so, data->ray[j].left_sprite_dist, now);
	if (data->ray[j].wall_direction == 'E')
		color = get_color(&data->imgs.ea, data->ray[j].left_sprite_dist, now);
	if (data->ray[j].wall_direction == 'W')
		color = get_color(&data->imgs.we, data->ray[j].left_sprite_dist, now);
	return (color);
}

float	init_wall_h(t_data *data, int j)
{
	float	ugol;
	float	wall_height;

	ugol = fabsf(data->player.direction - data->ray[j].direction);
	wall_height = 600 * ((float)DISTANSE_OF / \
	((data->ray[j].len) * cosf(ugol)));
	wall_height *= 20;
	return (wall_height);
}

void	ray_casting(t_data *data)
{
	int		i;
	int		j;
	int		down;
	int		color_down;
	int		now;

	i = 0;
	j = WITH - 1;
	while (i < WITH - 1)
	{
		data->ray[j].wall_height = init_wall_h(data, j);
		down = (int)((float)HEIGHT - data->ray[j].wall_height) / 2;
		data->ray[j].wall_h_tmp = data->ray[j].wall_height;
		now = 0;
		while (data->ray[j].wall_h_tmp >= 0)
		{
			color_down = get_color_pixel_texture(data, j, (float)now);
			my_mlx_pixel_put(&data->imgs.wall, i, down, color_down);
			down++;
			now++;
			data->ray[j].wall_h_tmp -= (float)(DISTANSE_OF);
		}
		i++;
		j--;
	}
}
