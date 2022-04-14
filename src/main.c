#include "../include/cube3d.h"

void	malx_test()
{
	void *mlx = mlx_init();
	mlx_new_window(mlx, 300, 300, "Coub3d");
	mlx_loop(mlx);
}

int main(int argc, char **argv)
{
	t_data data;

	init_null_data(&data);
	error_num_arg(argc);
	read_map(&data, argv);
	malx_test();
	exit_standard(&data);
	return 0;
}
