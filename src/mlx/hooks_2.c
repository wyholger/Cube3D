/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:27:57 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:28:47 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_person_it_wall_for_point(t_data *data, int x, int y)
{
	if (data->ch_map[y][x] == '1')
		return (1);
	return (0);
}

int	check_person_it_wall_2(t_data *data)
{
	int		flag;
	float	x;
	float	y;

	flag = 0;
	x = data->player.x + 0.7f;
	y = data->player.y + 0.7f;
	flag += check_person_it_wall_for_point(data, (int)(x / 15), (int)(y / 15));
	x = data->player.x - 0.7f;
	y = data->player.y - 0.7f;
	flag += check_person_it_wall_for_point(data, (int)(x / 15), (int)(y / 15));
	x = data->player.x - 0.7f;
	y = data->player.y + 0.7f;
	flag += check_person_it_wall_for_point(data, (int)(x / 15), (int)(y / 15));
	x = data->player.x + 0.7f;
	y = data->player.y - 0.7f;
	flag += check_person_it_wall_for_point(data, (int)(x / 15), (int)(y / 15));
	return (flag);
}

int	check_person_it_wall(t_data *data)
{
	int		flag;
	float	x;
	float	y;

	flag = 0;
	x = data->player.x + 1;
	y = data->player.y;
	flag += check_person_it_wall_for_point(data, (int)(x / 15), (int)(y / 15));
	x = data->player.x;
	y = data->player.y + 1;
	flag += check_person_it_wall_for_point(data, (int)(x / 15), (int)(y / 15));
	x = data->player.x;
	y = data->player.y - 1;
	flag += check_person_it_wall_for_point(data, (int)(x / 15), (int)(y / 15));
	x = data->player.x - 1;
	y = data->player.y;
	flag += check_person_it_wall_for_point(data, (int)(x / 15), (int)(y / 15));
	flag += check_person_it_wall_2(data);
	return (flag);
}

void	return_prev_player_x_y(t_data *data)
{
	data->player.y = data->player.prev_y;
	data->player.x = data->player.prev_x;
}

void	hook_w(t_data *data)
{
	data->player.y -= 1 * sinf(data->player.direction);
	data->player.x += 1 * cosf(data->player.direction);
	if (check_person_it_wall(data) > 0)
		return_prev_player_x_y(data);
}
