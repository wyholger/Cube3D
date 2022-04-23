#include "../../include/cube3d.h"

void	init_vars_for_draw_line(t_data *data, t_ray *ray)
{
	ray->x_y_x1_y1[0] = (int)data->player.x;
	ray->x_y_x1_y1[1] = (int)data->player.y;
	ray->x_y_x1_y1[2] = (int)data->ray.delta_x;
	ray->x_y_x1_y1[3] = (int)data->ray.delta_y;
	if (ray->x_y_x1_y1[0] < ray->x_y_x1_y1[2])
		ray->vars.signX = 1;
	else
		ray->vars.signX = -1;
	if (ray->x_y_x1_y1[1] < ray->x_y_x1_y1[3])
		ray->vars.signY = 1;
	else
		ray->vars.signY = -1;
}

void	draw_line(t_data *data, t_ray *ray)
{
	init_vars_for_draw_line(data, ray);
	ray->vars.deltax = abs(ray->x_y_x1_y1[2] - ray->x_y_x1_y1[0]);
	ray->vars.deltay = abs(ray->x_y_x1_y1[3] - ray->x_y_x1_y1[1]);
	ray->vars.error = ray->vars.deltax - ray->vars.deltay;
	mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, ray->x_y_x1_y1[2], ray->x_y_x1_y1[3], 0x9932cc);
	while(ray->x_y_x1_y1[0] != ray->x_y_x1_y1[2] || ray->x_y_x1_y1[1] != ray->x_y_x1_y1[3])
	{
		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, ray->x_y_x1_y1[0], ray->x_y_x1_y1[1], 0x11cc03);
		ray->vars.error_2 = ray->vars.error * 2;
		if(ray->vars.error_2 > -ray->vars.deltay)
		{
			ray->vars.error -= ray->vars.deltay;
			ray->x_y_x1_y1[0] += ray->vars.signX;
		}
		if(ray->vars.error_2 < ray->vars.deltax)
		{
			ray->vars.error += ray->vars.deltax;
			ray->x_y_x1_y1[1] += ray->vars.signY;
		}
	}
}