/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_crash_processing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:49:09 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:49:16 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_path_texture(t_data *data)
{
	if (data->path_no == NULL || data->path_so == NULL || \
	data->path_we == NULL || data->path_ea == NULL)
	{
		free_data_path(data);
		return (1);
	}
	return (0);
}

void	malloc_crash_after_init_data(t_data *data)
{
	int	flag;

	flag = check_path_texture(data);
	if (flag == 1)
		error(ERR_MALLOC);
}
