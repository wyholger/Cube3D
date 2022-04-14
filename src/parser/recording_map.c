#include "../../include/cube3d.h"

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
}