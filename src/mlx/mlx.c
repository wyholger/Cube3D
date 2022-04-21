#include "../../include/cube3d.h"

int	key_hook(int key_hook, t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	if (key_hook == W)
		data->player.y -= 1;
	if (key_hook == S)
		data->player.y += 1;
	if (key_hook == A)
		data->player.x -= 1;
	if (key_hook == D)
		data->player.x += 1;
	if (key_hook == ESC)
		exit_standard(data);
	minimap(data);
	return (0);
}

void	mlx_initialise(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		exit_after_validate(data, 9);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, 1000, 600, "Coub3d");
	if (data->mlx.mlx_win == NULL)
		exit_after_validate(data, 9);
	mlx_hook(data->mlx.mlx_win, 2, 1<<3, key_hook, data);
	//mlx_loop_hook(data->mlx.mlx, minimap, data); 
	//mlx_key_hook(data->mlx.mlx_win, key_hook, data);
}