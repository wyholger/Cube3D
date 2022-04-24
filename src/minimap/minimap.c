#include "../../include/cube3d.h"

void	img_minimap_init(t_data *data, t_img *img, t_img *img_flor)
{
	img->img = mlx_png_file_to_image(data->mlx.mlx, PATH_IMG_M_MAP, &img->x_sz, &img->y_sz);
	if (!img->img)
		exit_after_validate(data, 8);
	img_flor->img = mlx_png_file_to_image(data->mlx.mlx, PATH_IMG_M_MAP_FLOR, &img->x_sz, &img->y_sz);
	if (!img_flor->img)
		exit_after_validate(data, 8);
	if (data->flag_first_draw_minimap == 0)
	{
		data->player.x *= (float)img->x_sz;
		data->player.y *= (float)img->x_sz - 1;
		data->flag_first_draw_minimap = 1;
	}
}

void	minimap_draw(t_data *data, t_img *img, t_img *img_flor)
{
	t_list	*tmp;
	int i;
	int j;

	tmp = data->map;
	i = 0;
	while (tmp)
	{
		j = 0;
		while (tmp->word[j])
		{
			if (tmp->word[j] == '1')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, img->img, (j * img->y_sz), (i * img->x_sz));
			if (tmp->word[j] == '0' || tmp->word[j] == 'S' || tmp->word[j] == 'W' || tmp->word[j] == 'E' || tmp->word[j] == 'N')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, img_flor->img, (j * img->y_sz), (i * img->x_sz));
			j++;
		}
		i++;
		tmp = tmp->next;
	}
}

void	draw_player(t_data *data)
{
	t_player tmp;

	tmp = data->player;
	mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win,(int)data->player.x, (int)data->player.y, 0xfcba03);
}

void	minimap(t_data *data)
{
	int i;

	i = 0;
	img_minimap_init(data, &data->imgs.sprite_mini, &data->imgs.sprite_mini_flor);
	minimap_draw(data, &data->imgs.sprite_mini, &data->imgs.sprite_mini_flor);
	draw_player(data);
	init_rays(data);
	while (i < WITH)
	{
		ray_computing_cycle(data, &data->ray[i]);
		i++;
	}
	ray_casting(data);
}
