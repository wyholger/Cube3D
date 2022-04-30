/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:47:25 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:48:23 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_vars_for_draw_line(t_data *data, t_ray *ray)
{
	ray->x_y_x1_y1[0] = (int)data->player.x;
	ray->x_y_x1_y1[1] = (int)data->player.y;
	ray->x_y_x1_y1[2] = (int)ray->delta_x;
	ray->x_y_x1_y1[3] = (int)ray->delta_y;
	if (ray->x_y_x1_y1[0] < ray->x_y_x1_y1[2])
		ray->vars.sign_x = 1;
	else
		ray->vars.sign_x = -1;
	if (ray->x_y_x1_y1[1] < ray->x_y_x1_y1[3])
		ray->vars.sign_y = 1;
	else
		ray->vars.sign_y = -1;
}

void	draw_line(t_data *data, t_ray *ray, int color)
{
	init_vars_for_draw_line(data, ray);
	ray->vars.deltax = abs(ray->x_y_x1_y1[2] - ray->x_y_x1_y1[0]);
	ray->vars.deltay = abs(ray->x_y_x1_y1[3] - ray->x_y_x1_y1[1]);
	ray->vars.error = ray->vars.deltax - ray->vars.deltay;
	mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, \
	ray->x_y_x1_y1[2], ray->x_y_x1_y1[3], color);
	while (ray->x_y_x1_y1[0] != ray->x_y_x1_y1[2] || \
	ray->x_y_x1_y1[1] != ray->x_y_x1_y1[3])
	{
		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, \
		ray->x_y_x1_y1[0], ray->x_y_x1_y1[1], color);
		ray->vars.error_2 = ray->vars.error * 2;
		if (ray->vars.error_2 > -ray->vars.deltay)
		{
			ray->vars.error -= ray->vars.deltay;
			ray->x_y_x1_y1[0] += ray->vars.sign_x;
		}
		if (ray->vars.error_2 < ray->vars.deltax)
		{
			ray->vars.error += ray->vars.deltax;
			ray->x_y_x1_y1[1] += ray->vars.sign_y;
		}
	}
}
