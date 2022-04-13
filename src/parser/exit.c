#include "../../include/cube3d.h"

void	exit_after_validate(t_data *data, int flag_exit)
{
	free_data_path(data);
	ft_lstclear(&data->map_string);
	ft_lstclear(&data->map);
	if (flag_exit == 1)
		error(ERR_INVALID_PROPERT);
	if (flag_exit == 2)
		error(ERR_INVALID_CHAR);
	if (flag_exit == 3)
		error(ERR_MANY_CHARACTER);
	if (flag_exit == 4)
		error(ERR_NO_CHARACTER);
	if (flag_exit == 5)
		error(ERR_TOO_SMALL_MAP);
	if (flag_exit == 6)
		error(ERR_OPEN_BORDER);
}

void	exit_standard(t_data *data)
{
	free_data_path(data);
	ft_lstclear(&data->map_string);
}