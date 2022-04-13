#include "../../include/cube3d.h"

void	color_pars(t_data *data, char *str, int f_c_flag)
{
	char **for_split;

	for_split = ft_split(str, ',');
	if (f_c_flag == 1)
	{
		data->r_f = ft_atoi(for_split[0]);
		data->g_f = ft_atoi(for_split[1]);
		data->b_f = ft_atoi(for_split[2]);
	}
	if (f_c_flag == 2)
	{
		data->r_c = ft_atoi(for_split[0]);
		data->g_c = ft_atoi(for_split[1]);
		data->b_c = ft_atoi(for_split[2]);
	}
	split_free(for_split);
}