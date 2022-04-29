/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:51:00 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:51:20 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	split_free(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_fol_line(char *str)
{
	if (str == NULL)
		return ;
	free(str);
}

void	free_data_path(t_data *data)
{
	free_fol_line(data->path_no);
	free_fol_line(data->path_so);
	free_fol_line(data->path_we);
	free_fol_line(data->path_ea);
}
