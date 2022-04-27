#include "../../include/cube3d.h"

void	init_left_sprite_dist(t_data *data, t_ray *ray)
{
	if (ray->wall_direction == 'N')
	{
		ray->left_sprite_dist = fabsf(ray->delta_x - (float)(ray->x * data->imgs.sprite_mini.x_sz));
		if (ray->left_sprite_dist > 15)
		{
			ray->x++;
			ray->left_sprite_dist -= (float)data->imgs.sprite_mini.x_sz;
		}
	}
	if (ray->wall_direction == 'S')
	{
		ray->left_sprite_dist = fabsf(ray->delta_x - (float)((ray->x - (ray->stepY - ray->stepX)) * data->imgs.sprite_mini.x_sz));
//		ray->left_sprite_dist = data->imgs.sprite_mini.x_sz - ray->left_sprite_dist;

//		if (ray->left_sprite_dist > 15)
//		{
//			ray->x--;
////			ray->left_sprite_dist -= (float)data->imgs.sprite_mini.x_sz;
//		}
	}
//	if (ray->wall_direction == 'N')
//		ray->left_sprite_dist = fabsf(ray->delta_x - (float)(ray->x * data->imgs.sprite_mini.x_sz));
	if (ray->flag_first == 1 && ray->wall_direction == 'S')
	{

		printf("delta_x = %f; x = %d; ray = %f\n", ray->delta_x, ray->x ,ray->left_sprite_dist);
	}
}

