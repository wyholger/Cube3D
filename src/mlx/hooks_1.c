/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:27:44 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:27:45 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook_s(t_data *data)
{
	data->player.y += 1 * sinf(data->player.direction);
	data->player.x -= 1 * cosf(data->player.direction);
	if (check_person_it_wall(data) > 0)
		return_prev_player_x_y(data);
}

void	hook_a(t_data *data)
{
	data->player.x -= 1 * sinf(data->player.direction);
	data->player.y -= 1 * cosf(data->player.direction);
	if (check_person_it_wall(data) > 0)
		return_prev_player_x_y(data);
}

void	hook_d(t_data *data)
{
	data->player.x += 1 * sinf(data->player.direction);
	data->player.y += 1 * cosf(data->player.direction);
	if (check_person_it_wall(data) > 0)
		return_prev_player_x_y(data);
}

void	hook_left(t_data *data)
{
	data->player.direction += 0.15f;
	if (data->player.direction > PI_2)
		data->player.direction = 0.01;
}

void	hook_right(t_data *data)
{
	data->player.direction -= 0.15f;
	if (data->player.direction < 0)
		data->player.direction = PI_2 - 0.01;
}
