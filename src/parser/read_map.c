/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:45:31 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:47:20 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_on_full_properties(t_data *data)
{
	if (data->path_no == NULL || data->path_so == NULL || \
	data->path_we == NULL || data->path_ea == NULL || \
	data->r_f == -1 || data->g_f == -1 || data->b_f == -1 || \
	data->r_c == -1 || data->g_c == -1 || data->b_c == -1)
		return (1);
	return (0);
}

void	recording_map_properties(t_data *data, char *line)
{
	char	**for_split;

	if (ft_strlen(line) == 0)
		return ;
	for_split = ft_split(line, ' ');
	if (ft_strcmp(for_split[0], "NO") == 0)
		data->path_no = ft_strdup(for_split[1]);
	else if (ft_strcmp(for_split[0], "SO") == 0)
		data->path_so = ft_strdup(for_split[1]);
	else if (ft_strcmp(for_split[0], "WE") == 0)
		data->path_we = ft_strdup(for_split[1]);
	else if (ft_strcmp(for_split[0], "EA") == 0)
		data->path_ea = ft_strdup(for_split[1]);
	else if (ft_strcmp(for_split[0], "F") == 0)
		color_pars(data, for_split[1], 1);
	else if (ft_strcmp(for_split[0], "C") == 0)
		color_pars(data, for_split[1], 2);
	split_free(for_split);
}

void	recording_data_from_map(t_data *data, char *line)
{
	if (check_on_full_properties(data))
		recording_map_properties(data, line);
	else
		recording_map(data, line);
}

void	make_char_map(t_data *data)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = data->map;
	data->ch_map = malloc((ft_lstsize(data->map) + 1) * sizeof (char *));
	if (data->ch_map == NULL)
	{
		data->flag_malloc_crash = 1;
		return ;
	}
	while (tmp)
	{
		data->ch_map[i] = tmp->word;
		tmp = tmp->next;
		i++;
	}
	data->ch_map[i] = NULL;
}

void	read_map(t_data *data, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open_map(argv);
	while (get_next_line(fd, &line))
	{
		recording_data_from_map(data, line);
		free(line);
	}
	close(fd);
	recording_data_from_map(data, line);
	free(line);
	make_map_is_rectangle(data);
	validate_map(data);
	make_char_map(data);
	init_color(data);
	malloc_crash_after_init_data(data);
}
