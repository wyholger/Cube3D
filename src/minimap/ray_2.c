#include "../../include/cube3d.h"

void	init_left_sprite_dist(t_data *data, t_ray *ray)
{
	if (ray->wall_direction == 'N')
		ray->left_sprite_dist = fabsf(ray->delta_x - (float)(ray->x * data->imgs.sprite_mini.x_sz));
	if (ray->wall_direction == 'S')
	{
		ray->left_sprite_dist = fabsf(ray->delta_x - (float)(ray->x * data->imgs.sprite_mini.x_sz));
		ray->left_sprite_dist = data->imgs.sprite_mini.x_sz - ray->left_sprite_dist;
	}
	if (ray->wall_direction == 'E')
		ray->left_sprite_dist = fabsf(ray->delta_y - (float)(ray->y * data->imgs.sprite_mini.y_sz));
	if (ray->wall_direction == 'W')
	{
		ray->left_sprite_dist = fabsf(ray->delta_y - (float)(ray->y * data->imgs.sprite_mini.y_sz));
		ray->left_sprite_dist = data->imgs.sprite_mini.y_sz - ray->left_sprite_dist;
	}
//	if (ray->flag_first == 1 && ray->wall_direction == 'W')
//		printf("delta_x = %f; x = %d; ray = %f\n", ray->delta_x, ray->x ,ray->left_sprite_dist);
}

