/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:58:24 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 22:19:11 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_left_sprite_dist(t_data *data, t_ray *ray)
{
	if (ray->wall_direction == 'N')
		ray->left_sprite_dist = fabsf(ray->delta_x - \
		(float)(ray->x * data->imgs.sprite_mini.x_sz));
	if (ray->wall_direction == 'S')
	{
		ray->left_sprite_dist = fabsf(ray->delta_x - \
		(float)(ray->x * data->imgs.sprite_mini.x_sz));
		ray->left_sprite_dist = data->imgs.sprite_mini.x_sz - \
		ray->left_sprite_dist;
	}
	if (ray->wall_direction == 'E')
		ray->left_sprite_dist = fabsf(ray->delta_y - \
		(float)(ray->y * data->imgs.sprite_mini.y_sz));
	if (ray->wall_direction == 'W')
	{
		ray->left_sprite_dist = fabsf(ray->delta_y - \
		(float)(ray->y * data->imgs.sprite_mini.y_sz));
		ray->left_sprite_dist = data->imgs.sprite_mini.y_sz - \
		ray->left_sprite_dist;
	}
}

void	init_wall_direction_for_vertical(t_ray *ray)
{
	if (ray->step_x == -1)
		ray->wall_direction = 'W';
	else
		ray->wall_direction = 'E';
}

void	init_wall_direction_for_horizontal(t_ray *ray)
{
	if (ray->step_y == -1)
		ray->wall_direction = 'N';
	else
		ray->wall_direction = 'S';
}

void	draw_rays_on_minimap(t_data *data)
{
	int	i;

	i = 0;
	while (i < WITH - 1)
	{
		if (data->ray[i].flag_first == 0)
			draw_line(data, &data->ray[i], 0xF9FE72);
		else
			draw_line(data, &data->ray[i], 0xFF0000);
		i += 2;
	}
}

void	init_final_hypotenuse(t_data *data, t_ray *ray)
{
	ray->len = sqrtf(powf(ray->delta_x - \
	data->player.x, 2) + powf(ray->delta_y - data->player.y, 2));
}
