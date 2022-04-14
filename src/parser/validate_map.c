#include "../../include/cube3d.h"

void	validate_char(t_data *data, t_list *tmp)
{
	int	i;

	i = 0;
	while (tmp->word[i])
	{
		if (tmp->word[i] != '1' && tmp->word[i] != '0' &&\
		tmp->word[i] != 'N' && tmp->word[i] != 'S' &&\
		tmp->word[i] != 'W' && tmp->word[i] != 'E' &&\
		tmp->word[i] != ' ')
		{
			data->flag_no_valid_char = 1;
			return ;
		}
		if (tmp->word[i] == 'N' || tmp->word[i] == 'S' ||\
		tmp->word[i] == 'W' || tmp->word[i] == 'E')
			data->flag_count_pers++;
		i++;
	}
}

void	check_flags(t_data *data, int flag_end)
{
	if (data->flag_no_valid_char != 0)
		exit_after_validate(data, 2);
	if (flag_end == 0)
	{
		if (data->flag_count_pers > 1)
			exit_after_validate(data, 3);
	}
	else
	{
		if (data->flag_count_pers <= 0)
			exit_after_validate(data, 4);
	}
}

void	validate_map(t_data *data)
{
	t_list	*tmp;

	if (check_on_full_properties(data))
		exit_after_validate(data, 1);
	tmp = data->map;
	while (tmp)
	{
		validate_char(data, tmp);
		check_flags(data, 0);
		tmp = tmp->next;
	}
	check_flags(data, 1);
	validate_border(data);
}