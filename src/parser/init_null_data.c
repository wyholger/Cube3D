#include "../../include/cube3d.h"

void	init_null_data(t_data *data)
{
	data->path_no = NULL;
	data->path_so = NULL;
	data->path_we = NULL;
	data->path_ea = NULL;
	data->map = NULL;
	data->r_c = -1;
	data->g_c = -1;
	data->b_c = -1;
	data->r_f = -1;
	data->g_f = -1;
	data->b_f = -1;
	data->bits_per_pixel = 32;
	data->flag_malloc_crash = 0;
	data->flag_count_pers = 0;
	data->flag_no_valid_char = 0;
	data->flag_first_draw_minimap = 0;
	data->max_len_map = 0;
	data->max_height_map = 0;
	data->mlx.mlx = NULL;
	data->mlx.mlx_win = NULL;
	data->imgs.sprite_mini.img = NULL;
}