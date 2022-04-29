/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:55:02 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:55:18 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_rays(t_data *data)
{
	int		i;
	float	step_angle;
	float	angle;

	i = 0;
	step_angle = (float)RAD_FOR_66_ANGLE / (float)WITH;
	angle = data->player.direction - (step_angle * ((float)WITH_2));
	if (angle < 0)
		angle = PI_2 + angle;
	while (i < WITH)
	{
		if (i != 499)
			data->ray[i].flag_first = 0;
		else
			data->ray[i].flag_first = 1;
		if (angle > PI_2)
			angle = 0.0001;
		data->ray[i].direction = angle;
		angle += step_angle;
		i++;
	}
}
