/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:27:30 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:46:52 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	img_minimap_init(t_data *data, t_img *img, t_img *img_flor)
{
	if (data->flag_first_draw_minimap == 0)
	{
		init_minimap_sprite(data, img, img_flor);
		init_img_for_wall(data);
		clean_wall(&data->imgs.wall);
		data->player.x *= (float)img->x_sz;
		data->player.y *= (float)img->x_sz;
		data->player.x += 7.5f;
		data->player.y += 7.5f;
		data->flag_first_draw_minimap = 1;
		init_color_sky(data);
		init_color_flor(data);
	}
}

void	imgs_texture_and_sky_flor_init(t_data *data, t_img *flor, t_img *sky)
{
	init_img_for_flor_sky(data, flor, sky);
	init_img_for_texture_wall_no_so(data);
	init_img_for_texture_wall_we_ea(data);
}

void	minimap_draw(t_data *data, t_img *img, t_img *img_flor)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = data->map;
	i = 0;
	while (tmp)
	{
		j = 0;
		while (tmp->word[j])
		{
			if (tmp->word[j] == '1')
				mlx_put_image_to_window(data->mlx.mlx, \
				data->mlx.mlx_win, img->img, (j * img->y_sz), (i * img->x_sz));
			if (tmp->word[j] == '0' || tmp->word[j] == 'S' || \
			tmp->word[j] == 'W' || tmp->word[j] == 'E' || tmp->word[j] == 'N')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
				img_flor->img, (j * img->y_sz), (i * img->x_sz));
			j++;
		}
		i++;
		tmp = tmp->next;
	}
}

void	draw_player(t_data *data)
{
	mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, \
	(int)data->player.x, (int)data->player.y, 0xfcba03);
}

void	minimap(t_data *data)
{
	int	i;

	i = 0;
	img_minimap_init(data, &data->imgs.sprite_mini, \
	&data->imgs.sprite_mini_flor);
	mlx_put_image_to_window(data->mlx.mlx, \
	data->mlx.mlx_win, data->imgs.sky.img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
	data->imgs.flor.img, 0, 300);
	init_rays(data);
	while (i < WITH)
	{
		ray_computing_cycle(data, &data->ray[i]);
		i++;
	}
	clean_wall(&data->imgs.wall);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
	data->imgs.wall.img, 0, 0);
	draw_rays_on_minimap(data);
	minimap_draw(data, &data->imgs.sprite_mini, &data->imgs.sprite_mini_flor);
	draw_player(data);
}
