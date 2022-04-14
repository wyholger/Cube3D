#include "../../include/cube3d.h"

int	check_str_is_int(char *for_split)
{
	int i;

	i = 0;
	while (for_split[i])
	{
		if (!ft_isdigit(for_split[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_color_is_int(char **for_split)
{
	if (check_str_is_int(for_split[0]) == 1 || \
	check_str_is_int(for_split[1]) == 1|| \
	check_str_is_int(for_split[2]) == 1)
		return (1);
	return (0);
}

int	check_valid_color(char **for_split)
{
	int	tmp;
	int	tmp2;
	int	tmp3;
	int	flag_bad;

	flag_bad = 0;
	if (ft_strlen(for_split[0]) > 3 || \
	ft_strlen(for_split[1]) > 3 || \
	ft_strlen(for_split[2]) > 3)
		flag_bad = 1;
	tmp = ft_atoi(for_split[0]);
	tmp2 = ft_atoi(for_split[1]);
	tmp3 = ft_atoi(for_split[2]);
	if (tmp < 0 || tmp > 255 || tmp2 < 0 || tmp2 > 255 \
	|| tmp3 < 0 || tmp3 > 255)
		flag_bad = 1;
	if (check_color_is_int(for_split) == 1)
		flag_bad = 1;
	return (flag_bad);
}

void	color_pars(t_data *data, char *str, int f_c_flag)
{
	char **for_split;
	int flag_bad;

	flag_bad = 0;
	for_split = ft_split(str, ',');
	flag_bad = check_valid_color(for_split);
	if (flag_bad == 1)
	{
		split_free(for_split);
		exit_after_validate(data, 7);
	}
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