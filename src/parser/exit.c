#include "../../include/cube3d.h"

void	exit_after_validate(t_data *data, int flag_exit)
{
	free_data_path(data);
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
	if (flag_exit == 7)
		error(ERR_COLOR_FORMAT);
	if (flag_exit == 8)
		error(ERR_OPEN_IMG);
	if (flag_exit == 9)
		error(ERR_MLX);
}

void	exit_standard(t_data *data)
{
//	(void)data;

//	printf("BLAHHH\n");
	free_data_path(data);
	ft_lstclear(&data->map);
	free(data->ch_map);
	mlx_destroy_image(data->mlx.mlx, data->imgs.sprite_mini.img);
//	free(data->imgs.sprite_mini.img);
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	exit(0);
}