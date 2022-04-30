/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:53:20 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:27:17 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_hook(int key_hook, t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	data->player.prev_x = data->player.x;
	data->player.prev_y = data->player.y;
	if (key_hook == W)
		hook_w(data);
	if (key_hook == S)
		hook_s(data);
	if (key_hook == A)
		hook_a(data);
	if (key_hook == D)
		hook_d(data);
	if (key_hook == ESC)
		exit_standard(data);
	if (key_hook == LEFT)
		hook_left(data);
	if (key_hook == RIGHT)
		hook_right(data);
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
	mlx_hook(data->mlx.mlx_win, 17, 1L << 19, shutdown, data);
	mlx_hook(data->mlx.mlx_win, 2, 1 << 3, key_hook, data);
}
