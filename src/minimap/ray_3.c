/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:58:05 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 21:58:06 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_ray_vars(t_data *data, t_ray *ray)
{
	ray->sin_dir = sinf(ray->direction);
	ray->cos_dir = cosf(ray->direction);
	ray->step_x = step_init_x(ray);
	ray->step_y = step_init_y(ray);
	init_offset(data, ray);
	return (0);
}
