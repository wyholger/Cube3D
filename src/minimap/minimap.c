#include "../../include/cube3d.h"

void	img_minimap_init(t_data *data, t_img *img)
{
	printf("BLAH\n");
	img->img = mlx_png_file_to_image(data->mlx.mlx, PATH_IMG_M_MAP, &img->x_sz, &img->y_sz);
	if (!img->img)
		exit_after_validate(data, 8);
}

void	minimap(t_data *data)
{
	img_minimap_init(data, &data->imgs.sprite_mini);
}
