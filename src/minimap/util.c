/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:54:31 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:54:45 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_to_open_img(t_data *data, void *img)
{
	if (!img)
		exit_after_validate(data, 8);
}

void	clean_wall(t_img *wall)
{
	char	*dst;
	int		x;
	int		y;

	y = 0;
	while (y++ < wall->y_sz - 1)
	{
		x = 0;
		while (x++ < wall->x_sz - 1)
		{
			dst = wall->adr + (y * (wall->x_sz * 4) + x * 4);
			*(unsigned int *)dst = 0xFF999999;
		}
	}
}
