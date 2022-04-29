/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:53:20 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:53:21 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_hook(int key_hook, t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	if (key_hook == W)
	{
		data->player.y -= 1 * sinf(data->player.direction);
		data->player.x += 1 * cosf(data->player.direction);
	}
	if (key_hook == S)
	{
		data->player.y += 1 * sinf(data->player.direction);
		data->player.x -= 1 * cosf(data->player.direction);
	}
	if (key_hook == A)
	{
		data->player.x -= 1 * sinf(data->player.direction);
		data->player.y -= 1 * cosf(data->player.direction);
	}
	if (key_hook == D)
	{
		data->player.x += 1 * sinf(data->player.direction);
		data->player.y += 1 * cosf(data->player.direction);
	}
	if (key_hook == D || key_hook == A || key_hook == S || key_hook == W)
	{
		data->player.y_i = (int)(data->player.y / (float)data->imgs.sprite_mini.x_sz);
		data->player.x_i = (int)(data->player.x / (float)data->imgs.sprite_mini.x_sz);
	}
	if (key_hook == ESC)
		exit_standard(data);
	if (key_hook == LEFT)
	{
		data->player.direction += 0.15f;
		if (data->player.direction > PI_2)
		{
			data->player.direction = 0.01;
		}
	}
	if (key_hook == RIGHT)
	{
		data->player.direction -= 0.15f;
		if (data->player.direction < 0)
		{
			data->player.direction = PI_2 - 0.01;
		}
	}
	minimap(data);
	return (0);
}

void	mlx_initialise(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		exit_after_validate(data, 9);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, WITH, HEIGHT, "Coub3d");
	if (data->mlx.mlx_win == NULL)
		exit_after_validate(data, 9);
	imgs_texture_and_sky_flor_init(data, &data->imgs.flor, &data->imgs.sky);
	mlx_hook(data->mlx.mlx_win, 2, 1<<3, key_hook, data);
	//mlx_loop_hook(data->mlx.mlx, minimap, data); 
	//mlx_key_hook(data->mlx.mlx_win, key_hook, data);
}