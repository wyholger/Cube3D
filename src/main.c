/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:50:30 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:51:08 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_null_data(&data);
	error_num_arg(argc);
	read_map(&data, argv);
	mlx_initialise(&data);
	minimap(&data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
