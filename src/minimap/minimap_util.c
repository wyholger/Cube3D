#include "../../include/cub3d.h"

void	init_minimap_sprite(t_data *data, t_img *img, t_img *img_flor)
{
	img->img = mlx_png_file_to_image(data->mlx.mlx, PATH_IMG_M_MAP, &img->x_sz, &img->y_sz);
	if (!img->img)
		exit_after_validate(data, 8);
	img_flor->img = mlx_png_file_to_image(data->mlx.mlx, PATH_IMG_M_MAP_FLOR, &img->x_sz, &img->y_sz);
	if (!img_flor->img)
		exit_after_validate(data, 8);
}

void	init_img_for_wall(t_data *data)
{
	int	endian;

	data->imgs.wall.img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_IMG_WALL, &data->imgs.wall.x_sz, &data->imgs.wall.y_sz);
	if (!data->imgs.wall.img)
		exit_after_validate(data, 8);
	data->imgs.wall.size_line = data->imgs.wall.x_sz * 4;
	data->imgs.wall.adr = mlx_get_data_addr(data->imgs.wall.img, &data->bits_per_pixel, &data->imgs.wall.size_line, &endian);
}

//void	flor_s