/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:29:03 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:44:57 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_minimap_sprite(t_data *data, t_img *img, t_img *img_flor)
{
	img->img = mlx_png_file_to_image(data->mlx.mlx, \
	PATH_IMG_M_MAP, &img->x_sz, &img->y_sz);
	if (!img->img)
		exit_after_validate(data, 8);
	img_flor->img = mlx_png_file_to_image(data->mlx.mlx, \
	PATH_IMG_M_MAP_FLOR, &img->x_sz, &img->y_sz);
	if (!img_flor->img)
		exit_after_validate(data, 8);
}

void	init_img_for_wall(t_data *data)
{
	int	endian;

	data->imgs.wall.img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_IMG_WALL, \
	&data->imgs.wall.x_sz, &data->imgs.wall.y_sz);
	if (!data->imgs.wall.img)
		exit_after_validate(data, 8);
	data->imgs.wall.size_line = data->imgs.wall.x_sz * 4;
	data->imgs.wall.adr = mlx_get_data_addr(data->imgs.wall.img, \
	&data->bits_per_pixel, &data->imgs.wall.size_line, &endian);
}

void	init_img_for_flor_sky(t_data *data, t_img *flor, t_img *sky)
{
	flor->img = mlx_xpm_file_to_image(data->mlx.mlx, \
	PATH_IMG_FLOR, &flor->x_sz, &flor->y_sz);
	sky->img = mlx_xpm_file_to_image(data->mlx.mlx, \
	PATH_IMG_SKY, &sky->x_sz, &sky->y_sz);
	check_to_open_img(data, flor->img);
	check_to_open_img(data, sky->img);
}

void	init_img_for_texture_wall_no_so(t_data *data)
{
	int	endian;

	data->imgs.no.img = mlx_xpm_file_to_image(data->mlx.mlx, \
	data->path_no, &data->imgs.no.x_sz, &data->imgs.no.y_sz);
	check_to_open_img(data, data->imgs.no.img);
	data->imgs.no.size_line = data->imgs.no.x_sz * 4;
	data->imgs.no.adr = mlx_get_data_addr(data->imgs.no.img, \
	&data->bits_per_pixel, &data->imgs.no.size_line, &endian);
	data->imgs.so.img = mlx_xpm_file_to_image(data->mlx.mlx, \
	data->path_so, &data->imgs.so.x_sz, &data->imgs.so.y_sz);
	check_to_open_img(data, data->imgs.so.img);
	data->imgs.so.size_line = data->imgs.so.x_sz * 4;
	data->imgs.so.adr = mlx_get_data_addr(data->imgs.so.img, \
	&data->bits_per_pixel, &data->imgs.so.size_line, &endian);
}

void	init_img_for_texture_wall_we_ea(t_data *data)
{
	int	endian;

	data->imgs.we.img = mlx_xpm_file_to_image(data->mlx.mlx, \
	data->path_we, &data->imgs.we.x_sz, &data->imgs.we.y_sz);
	check_to_open_img(data, data->imgs.we.img);
	data->imgs.we.size_line = data->imgs.we.x_sz * 4;
	data->imgs.we.adr = mlx_get_data_addr(data->imgs.we.img, \
	&data->bits_per_pixel, &data->imgs.we.size_line, &endian);
	data->imgs.ea.img = mlx_xpm_file_to_image(data->mlx.mlx, \
	data->path_ea, &data->imgs.ea.x_sz, &data->imgs.ea.y_sz);
	check_to_open_img(data, data->imgs.ea.img);
	data->imgs.ea.size_line = data->imgs.ea.x_sz * 4;
	data->imgs.ea.adr = mlx_get_data_addr(data->imgs.ea.img, \
	&data->bits_per_pixel, &data->imgs.ea.size_line, &endian);
}
