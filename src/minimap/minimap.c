/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:27:30 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 22:28:39 by wyholger         ###   ########.fr       */
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
		data->player.y *= (float)img->x_sz - 1;
		data->flag_first_draw_minimap = 1;
		init_color_sky(data);
		init_color_flor(data);
	}
}

void	imgs_texture_and_sky_flor_init(t_data *data, t_img *flor, t_img *sky)
{
	int endian;

	flor->img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_IMG_FLOR, &flor->x_sz, &flor->y_sz);
	sky->img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_IMG_SKY, &sky->x_sz, &sky->y_sz);
	check_to_open_img(data,flor->img);
	check_to_open_img(data,sky->img);
	data->imgs.no.img = mlx_xpm_file_to_image(data->mlx.mlx, data->path_no, &data->imgs.no.x_sz, &data->imgs.no.y_sz);
	check_to_open_img(data,data->imgs.no.img);
	data->imgs.no.size_line = data->imgs.no.x_sz * 4;
	data->imgs.no.adr = mlx_get_data_addr(data->imgs.no.img, &data->bits_per_pixel,&data->imgs.no.size_line, &endian);
	data->imgs.so.img = mlx_xpm_file_to_image(data->mlx.mlx, data->path_so, &data->imgs.so.x_sz, &data->imgs.so.y_sz);
	check_to_open_img(data,data->imgs.so.img);
	data->imgs.so.size_line = data->imgs.so.x_sz * 4;
	data->imgs.so.adr = mlx_get_data_addr(data->imgs.so.img, &data->bits_per_pixel,&data->imgs.so.size_line, &endian);
	data->imgs.we.img = mlx_xpm_file_to_image(data->mlx.mlx, data->path_we, &data->imgs.we.x_sz, &data->imgs.we.y_sz);
	check_to_open_img(data,data->imgs.we.img);
	data->imgs.we.size_line = data->imgs.we.x_sz * 4;
	data->imgs.we.adr = mlx_get_data_addr(data->imgs.we.img, &data->bits_per_pixel,&data->imgs.we.size_line, &endian);
	data->imgs.ea.img = mlx_xpm_file_to_image(data->mlx.mlx, data->path_ea, &data->imgs.ea.x_sz, &data->imgs.ea.y_sz);
	check_to_open_img(data,data->imgs.ea.img);
	data->imgs.ea.size_line = data->imgs.ea.x_sz * 4;
	data->imgs.ea.adr = mlx_get_data_addr(data->imgs.ea.img, &data->bits_per_pixel,&data->imgs.ea.size_line, &endian);
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
	printf("dir = %f\n", data->player.direction);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->imgs.sky.img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->imgs.flor.img, 0, 300);
	init_rays(data);
	while (i < WITH)
	{
		ray_computing_cycle(data, &data->ray[i]);
		i++;
	}
	printf("step_x = %d; step_y = %d\n", data->ray[499].step_x, data->ray[499].step_y);
	clean_wall(&data->imgs.wall);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->imgs.wall.img, 0, 0);
	draw_rays_on_minimap(data);
	minimap_draw(data, &data->imgs.sprite_mini, &data->imgs.sprite_mini_flor);
	draw_player(data);
}
