/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recording_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:44:10 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:45:03 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_direction(t_data *data, t_list *list, int i)
{
	int	j;

	j = 0;
	while (list->word[j])
	{
		if (list->word[j] == 'N')
			data->player.direction = M_PI / 2;
		if (list->word[j] == 'W')
			data->player.direction = M_PI;
		if (list->word[j] == 'E')
			data->player.direction = 0;
		if (list->word[j] == 'S')
			data->player.direction = 3 * M_PI / 2;
		if (list->word[j] == 'S' || list->word[j] == 'E' || \
		list->word[j] == 'W' || list->word[j] == 'N')
		{
			data->player.direction = data->player.direction + 0.000000000001f;
			data->player.x = (float)j;
			data->player.y = (float)i - 1;
			data->player.x_i = j;
			data->player.y_i = i;
		}
		j++;
	}
}

void	recording_map(t_data *data, char *line)
{
	t_list	*tmp;
	int		len;

	if (ft_strlen(line) == 0)
		return ;
	tmp = NULL;
	len = (int)ft_strlen(line);
	data->max_height_map++;
	if (data->max_len_map < len)
		data->max_len_map = len;
	tmp = ft_lstnew(line);
	if (tmp == NULL)
	{
		data->flag_malloc_crash = 1;
		return ;
	}
	ft_lstadd_back(&data->map, tmp);
	check_direction(data, tmp, ft_lstsize(data->map));
}
