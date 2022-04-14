#include "../../include/cube3d.h"

char *make_string_spase_to_len(t_data *data, int len)
{
	char	*str;
	int		i;
	str = NULL;
	str = malloc(len + 1);
	if (str == NULL)
	{
		data->flag_malloc_crash = 1;
		return (str);
	}
	i = 0;
	while (i < len)
	{
		str[i] = ' ';
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	make_string_is_longer(t_data *data, t_list *list, int len)
{
	char	*str;
	char	*tmp;

	str = make_string_spase_to_len(data, len);
	if (str == NULL)
		return;
	tmp = ft_strjoin(list->word, str);
	if (tmp == NULL)
	{
		data->flag_malloc_crash = 1;
		return;
	}
	if (list->word != NULL)
		free(list->word);
	list->word = tmp;
}

void	make_map_is_rectangle(t_data *data)
{
	t_list	*tmp;
	int		len;

	tmp = data->map;
	while (tmp)
	{
		len = (int)ft_strlen(tmp->word);
		if (len < data->max_len_map)
			make_string_is_longer(data, tmp, data->max_len_map - len);
		tmp = tmp->next;
	}
}