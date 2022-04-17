#include "../../include/cube3d.h"

void	mlx_initialise(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		exit_after_validate(data, 9);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, 1000, 600, "Coub3d");
	if (data->mlx.mlx_win == NULL)
		exit_after_validate(data, 9);
	mlx_loop(data->mlx.mlx);
}