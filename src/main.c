#include "../include/cube3d.h"

//void	malx_test(t_data *data)
//{
//
//	void	*img_0;
//	void	*img_1;
//	void	*img_2;
//	void	*mlx = mlx_init();
//	int 	x;
//	int		y;
//	int 	x_1;
//	int 	y_1;
//	int 	x_2;
//	int 	y_2;
//	void	*mlx_win = mlx_new_window(mlx, 1000, 1000, "Coub3d");
//	if (!mlx_win)
//	{
//		exit_standard(data);
//	}
//	img_0 = mlx_png_file_to_image(mlx, "sprite/board_mini_map_100.png", &x, &y);
//	img_1 = mlx_png_file_to_image(mlx, "sprite/board_mini_map_20.png", &x_1, &y_1);
//	img_2 = mlx_png_file_to_image(mlx, "sprite/board_mini_map_60.png", &x_2, &y_2);
////	img_0 = mlx_xpm_file_to_image(mlx, "sprite/board_mini_map.xpm", &x, &y);
////	img_1 = mlx_xpm_file_to_image(mlx, "sprite/board_mini_map_80.xpm", &x_1, &y_1);
////	if (!img_0)
////	{
////		mlx_destroy_window(mlx, mlx_win);
////		printf("BLAH\n");
////		exit_standard(data);
////	}
//	mlx_put_image_to_window(mlx, mlx_win, img_0, x, y);
//	mlx_put_image_to_window(mlx, mlx_win, img_1, x_1 + 10, y_1 + 10);
//	mlx_put_image_to_window(mlx, mlx_win, img_2, x_1 + 20, y_1 + 20);
//	mlx_loop(mlx);
//}

int main(int argc, char **argv)
{
	t_data data;

	init_null_data(&data);
	error_num_arg(argc);
	read_map(&data, argv);
//	malx_test(&data);
	mlx_initialise(&data);
	minimap(&data);
	mlx_loop(data.mlx.mlx);
	exit_standard(&data);
	return 0;
}
