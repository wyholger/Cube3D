#include "../../include/cube3d.h"

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
	int flag;

	flag = check_path_texture(data);
	if (flag == 1)
		error(ERR_MALLOC);			//доработать логику
}