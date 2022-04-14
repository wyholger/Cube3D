#include "../../include/cube3d.h"

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

void free_data_path(t_data *data)
{
	free_fol_line(data->path_no);
	free_fol_line(data->path_so);
	free_fol_line(data->path_we);
	free_fol_line(data->path_ea);
}