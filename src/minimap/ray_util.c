/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:57:01 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:57:55 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	step_init_y(t_ray *ray)
{
	if (ray->direction > M_PI && ray->direction < M_PI * 2)
		return (1);
	return (-1);
}

int	step_init_x(t_ray *ray)
{
	if (ray->direction > 0 && ray->direction < M_PI / 2)
		return (1);
	if (ray->direction > ((3 * M_PI) / 2) && ray->direction < M_PI * 2)
		return (1);
	return (-1);
}

float	get_hypotenuse_to_vertical(t_data *data, float cos_dir, t_ray *ray)
{
	float	hypotenuse;

	if (ray->step_x == 1)
		hypotenuse = (data->player.offset_x / cos_dir);
	else
		hypotenuse = (data->player.offset_x / (cos_dir * -1));
	return (hypotenuse);
}

float	get_hypotenuse_to_horizontal(t_data *data, float sin_dir, t_ray *ray)
{
	float	hypotenuse;

	if (ray->step_y == 1)
		hypotenuse = (data->player.offset_y / sin_dir);
	else
		hypotenuse = (data->player.offset_y / (sin_dir * -1));
	return (hypotenuse);
}

void	init_offset(t_data *data, t_ray *ray)
{
	data->player.offset_x = fmodf(data->player.x, \
	(int)data->imgs.sprite_mini.x_sz);
	if (ray->step_x == 1)
		data->player.offset_x = data->imgs.sprite_mini.x_sz - \
		data->player.offset_x;
	data->player.offset_y = fmodf(data->player.y, \
	(int)data->imgs.sprite_mini.x_sz);
	if (ray->step_y == 1)
		data->player.offset_y = data->imgs.sprite_mini.x_sz - \
		data->player.offset_y;
}
