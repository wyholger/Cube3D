#include "../../include/cube3d.h"

void	init_color(t_data *data)
{
	data->color_flor = ((data->r_f * 256 * 256) + (data->g_f * 256) + data->b_f);
//	data->color_flor = data->color_flor + 0xFF000000;
	data->color_sky = ((data->r_c * 256 * 256) + (data->g_c * 256) + data->b_c);
}

void	init_color_sky(t_data *data)
{
	char *sorse;
	char *dst;
	int endi;
	int bits = 32;
	int size_line = data->imgs.sky.x_sz * 4;
//	int color = 0xbfff;
	int y = 0;
	int x = 0;

//	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->imgs.sky.img, 0, 0);
	sorse = mlx_get_data_addr(data->imgs.sky.img, &bits, &size_line, &endi);
	while (y++ < data->imgs.sky.y_sz - 1)
	{
		x = 0;
		while(x++ < data->imgs.sky.x_sz - 1)
		{
			dst = sorse + (y * (data->imgs.sky.x_sz * 4) + x * (4));
			*(unsigned int *)dst = data->color_sky;
		}
	}
}

void	init_color_flor(t_data *data)
{
	char *sorse;
	char *dst;
	int endi;
	int bits;
	int size_line;
//	int color = 0xfffa73;
	int y;
	int x = 0;

	y = 0;
	bits = 32;
	size_line = data->imgs.flor.x_sz * 4;
	sorse = mlx_get_data_addr(data->imgs.flor.img, &bits, &size_line, &endi);
	while (y++ < data->imgs.flor.y_sz - 1)
	{
		x = 0;
		while(x++ < data->imgs.flor.x_sz - 1)
		{
			dst = sorse + (y * (data->imgs.flor.x_sz * 4) + x * (4));
			*(unsigned int *)dst = data->color_flor;
		}
	}
}
