/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:49:06 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:50:16 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_color(t_data *data)
{
	data->color_flor = ((data->r_f * 256 * 256) \
	+ (data->g_f * 256) + data->b_f);
	data->color_sky = ((data->r_c * 256 * 256) + \
	(data->g_c * 256) + data->b_c);
}

void	init_color_sky(t_data *data)
{
	char	*sorse;
	char	*dst;
	int		endi;
	int		y;
	int		x;

	y = 0;
	data->imgs.sky.size_line = data->imgs.sky.x_sz * 4;
	sorse = mlx_get_data_addr(data->imgs.sky.img, \
	&data->bits_per_pixel, &data->imgs.sky.size_line, &endi);
	while (y++ < data->imgs.sky.y_sz - 1)
	{
		x = 0;
		while (x++ < data->imgs.sky.x_sz - 1)
		{
			dst = sorse + (y * (data->imgs.sky.x_sz * 4) + x * (4));
			*(unsigned int *)dst = data->color_sky;
		}
	}
}

void	init_color_flor(t_data *data)
{
	char	*sorse;
	char	*dst;
	int		endi;
	int		y;
	int		x;

	y = 0;
	data->imgs.flor.size_line = data->imgs.flor.x_sz * 4;
	sorse = mlx_get_data_addr(data->imgs.flor.img, \
	&data->bits_per_pixel, &data->imgs.flor.size_line, &endi);
	while (y++ < data->imgs.flor.y_sz - 1)
	{
		x = 0;
		while (x++ < data->imgs.flor.x_sz - 1)
		{
			dst = sorse + (y * (data->imgs.flor.x_sz * 4) + x * (4));
			*(unsigned int *)dst = data->color_flor;
		}
	}
}
