#include "../../include/cube3d.h"

void	img_minimap_init(t_data *data, t_img *img)
{
	img->img = mlx_png_file_to_image(data->mlx.mlx, PATH_IMG_M_MAP, &img->x_sz, &img->y_sz);
	if (!img->img)
		exit_after_validate(data, 8);
	data->player.x *=  (float)img->x_sz;
	data->player.y *=  (float)img->x_sz;
}

void	minimap_draw(t_data *data, t_img *img)
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
			j++;
		}
		i++;
		tmp = tmp->next;
	}
}

void	minimap(t_data *data)
{
	img_minimap_init(data, &data->imgs.sprite_mini);
	minimap_draw(data, &data->imgs.sprite_mini);
}
