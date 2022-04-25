#include "../../include/cube3d.h"

void	init_rays(t_data *data)
{
	int 	i;
	float	step_angle;
	float 	angle;


	i = 0;
	step_angle = (float)RAD_FOR_66_ANGLE / (float)WITH;
	angle = data->player.direction - (step_angle * ((float)WITH / 2));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	while (i < WITH)
	{
		if (i == 499)
			data->ray[i].flag_first = 1;
		else
			data->ray[i].flag_first = 0;
		if (angle > 2 * M_PI)
			angle = 0.0001;
		data->ray[i].direction = angle;
		angle += step_angle;
		i++;
	}
}