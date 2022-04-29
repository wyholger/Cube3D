/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:43:22 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:43:44 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	first_validate_border(t_data *data, t_list *tmp_0)
{
	int	i;

	i = 0;
	while (tmp_0->word[i])
	{
		if (tmp_0->word[i] == '0')
			exit_after_validate(data, 6);
		i++;
	}
}

void	zero_check(t_data *data, int i, t_list *tmp_0, t_list *tmp_1)
{
	t_list	*tmp_2;

	tmp_2 = tmp_1->next;
	if (i == 0 || i == data->max_len_map - 1 || \
	tmp_1->word[i - 1] == ' ' || tmp_1->word[i + 1] == ' ' || \
	tmp_0->word[i] == ' ' || tmp_0->word[i - 1] == ' ' || \
	tmp_0->word[i + 1] == ' ' || tmp_2->word[i] == ' ' || \
	tmp_2->word[i - 1] == ' ' || tmp_2->word[i + 1] == ' ')
	{
		exit_after_validate(data, 6);
	}
}

void	midl_validate_border(t_data *data, t_list *tmp_0, t_list *tmp_1)
{
	int	i;

	i = 0;
	while (tmp_1->word[i])
	{
		if (tmp_1->word[i] == '0')
			zero_check(data, i, tmp_0, tmp_1);
		i++;
	}
}

void	end_validate_border(t_data *data, t_list *tmp_1)
{
	int	i;

	i = 0;
	while (tmp_1->word[i])
	{
		if (tmp_1->word[i] == '0')
			exit_after_validate(data, 6);
		i++;
	}
}

void	validate_border(t_data *data)
{
	t_list	*tmp_0;
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (ft_lstsize(data->map) < 3)
		exit_after_validate(data, 5);
	tmp_0 = data->map;
	tmp_1 = data->map->next;
	tmp_2 = data->map->next->next;
	first_validate_border(data, tmp_0);
	while (tmp_2)
	{
		midl_validate_border(data, tmp_0, tmp_1);
		tmp_0 = tmp_1;
		tmp_1 = tmp_2;
		tmp_2 = tmp_2->next;
	}
	end_validate_border(data, tmp_1);
}
