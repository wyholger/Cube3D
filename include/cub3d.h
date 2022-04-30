/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:15:33 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/30 18:26:31 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
//# include <mlx.h>
# include "../minilibx/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ERR_NUM_ARG "\033[0;31mError. Number \
arg error. You need ./cube3D <path_to_map>\033[0;0m"
# define ERR_FILE_FORMAT "\033[0;31mError. File format \
should be <name>.cub\033[0;0m"
# define ERR_FILE_OPEN "\033[0;31mError. Open file error.\033[0;0m"
# define ERR_FILE_IS_DIR "\033[0;31mError. Argument is directory.\033[0;0m"
# define ERR_MALLOC "\033[0;31mError. Malloc error.\033[0;0m"
# define ERR_INVALID_PROPERT "\033[0;31mError. Not valid properties map. \
\nNeed lines:\nNO ...\nSO ...\nWE ...\nEA ...\
\n(and colors floor and ceiling)\nF ...\nC ...\033[0;0m"
# define ERR_INVALID_CHAR "\033[0;31mError. Map contains an invalid character.\
\nValid characters: '1' '0' 'N' 'S' 'W' 'E'\033[0;0m"
# define ERR_MANY_CHARACTER "\033[0;31mError. Map contains more than one \
character. ('N' 'S' 'W' 'E')\033[0;0m"
# define ERR_NO_CHARACTER "\033[0;31mError. Map does not contain any \
character. ('N' 'S' 'W' 'E')\033[0;0m"
# define ERR_TOO_SMALL_MAP "\033[0;31mError. To small map\033[0;0m"
# define ERR_OPEN_BORDER "\033[0;31mError. Open border map.\033[0;0m"
# define ERR_COLOR_FORMAT "\033[0;31mError. No valid color format.\nNeed \
int (color > 0 and color < 256)\033[0;0m"
# define ERR_OPEN_IMG "\033[0;31mError. Open img error.\033[0;0m"
# define ERR_MLX "\033[0;31mError. Mlx error.\033[0;0m"

# define PATH_IMG_M_MAP "sprite/board_mini_map_60.png"
# define PATH_IMG_M_MAP_FLOR "sprite/board_mini_map_20.png"
# define PATH_IMG_FLOR "sprite/mnblack.xpm"
# define PATH_IMG_SKY "sprite/mnblack.xpm"
# define PATH_IMG_WALL "sprite/wall.xpm"

# define WITH 1000
# define WITH_2 500
# define HEIGHT 600
# define HEIGHT_2 300
# define DISTANSE_OF 0.83865
# define RAD_FOR_66_ANGLE 1.15192
# define PI_2 6.28318530718

typedef struct s_var_draw_line
{
	int		deltax;
	int		deltay;
	int		error;
	int		error_2;
	int		sign_x;
	int		sign_y;
}			t_var_draw_line;

typedef struct s_ray
{
	float			wall_height;
	float			wall_h_tmp;
	float			direction;
	int				step_x;
	int				step_y;
	int				x;
	int				y;
	float			left_sprite_dist;
	float			sin_dir;
	float			cos_dir;
	float			delta_x;
	float			delta_y;
	float			len;
	float			hypotenuse_vertical;
	float			hypotenuse_horizontal;
	int				x_y_x1_y1[4];
	char			wall_direction;
	int				flag_first;
	t_var_draw_line	vars;
}			t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef struct s_img
{
	void	*img;
	char	*adr;
	int		size_line;
	int		x_sz;
	int		y_sz;
}			t_img;

typedef struct s_all_img
{
	t_img	sprite_mini;
	t_img	sprite_mini_flor;
	t_img	flor;
	t_img	sky;
	t_img	wall;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
}			t_all_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	prev_x;
	float	prev_y;
	float	offset_x;
	float	offset_y;
	int		x_i;
	int		y_i;
	float	direction;
}			t_player;

typedef struct s_data
{
	t_list		*map;
	char		**ch_map;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			r_f;
	int			g_f;
	int			b_f;
	int			r_c;
	int			g_c;
	int			b_c;
	int			color_flor;
	int			color_sky;
	int			bits_per_pixel;
	int			flag_malloc_crash;
	int			flag_count_pers;
	int			flag_no_valid_char;
	int			flag_first_draw_minimap;
	int			max_len_map;
	int			max_height_map;
	t_mlx		mlx;
	t_all_img	imgs;
	t_player	player;
	t_ray		ray[WITH];
}			t_data;

/* ===START_PARSER=== */

/* _ERROR_ */

void	error_num_arg(int argc);
void	error(char *err);
void	exit_after_validate(t_data *data, int flag_exit);
void	check_to_open_img(t_data *data, void *img);

/* _FILE_READ_WORK_ */

void	check_valid_file_format(char **argv);
int		open_map(char **argv);
void	read_map(t_data *data, char **argv);
void	check_direction(t_data *data, t_list *list, int i);
void	recording_map(t_data *data, char *line);
void	color_pars(t_data *data, char *str, int f_c_flag);
int		check_on_full_properties(t_data *data);

/* _MAKE_MAP_IS_RECTANGLE_ */

void	make_map_is_rectangle(t_data *data);
void	make_string_is_longer(t_data *data, t_list *list, int len);
char	*make_string_spase_to_len(t_data *data, int len);

/* __VALIDATE__ */

void	validate_map(t_data *data);
void	validate_border(t_data *data);
void	first_validate_border(t_data *data, t_list *tmp_0);
void	midl_validate_border(t_data *data, t_list *tmp_0, t_list *tmp_1);
void	end_validate_border(t_data *data, t_list *tmp_1);
void	zero_check(t_data *data, int i, t_list *tmp_0, t_list *tmp_1);

/* _VALIDATE_COLOR_ */

int		check_valid_color(char **for_split);
int		check_color_is_int(char **for_split);
int		check_str_is_int(char *for_split);

/* ===END_PARSER=== */

void	imgs_texture_and_sky_flor_init(t_data *data, t_img *flor, t_img *sky);
void	init_color(t_data *data);
void	init_color_sky(t_data *data);
void	init_color_flor(t_data *data);

/* ===MINIMAP=== */

void	draw_player(t_data *data);
int		step_init_x(t_ray *ray);
int		step_init_y(t_ray *ray);
void	init_offset(t_data *data, t_ray *ray);
int		init_ray_vars(t_data *data, t_ray *ray);
void	draw_line(t_data *data, t_ray *ray, int color);
void	init_vars_for_draw_line(t_data *data, t_ray *ray);
void	init_rays(t_data *data);
void	init_left_sprite_dist(t_data *data, t_ray *ray);
void	draw_rays_on_minimap(t_data *data);
void	init_wall_direction_for_vertical(t_ray *ray);
void	init_wall_direction_for_horizontal(t_ray *ray);
void	init_final_hypotenuse(t_data *data, t_ray *ray);
void	init_minimap_sprite(t_data *data, t_img *img, t_img *img_flor);
void	init_img_for_wall(t_data *data);

/* ===END_MINIMAP=== */

/* ===RAY_CASTING=== */

void	ray_casting(t_data *data);
void	ray_computing_cycle(t_data *data, t_ray *ray);
void	clean_wall(t_img *wall);
void	init_img_for_flor_sky(t_data *data, t_img *flor, t_img *sky);
void	init_img_for_texture_wall_no_so(t_data *data);
void	init_img_for_texture_wall_we_ea(t_data *data);

/* ===END_RAY_CASTING=== */

/* ===MLX=== */

void	mlx_initialise(t_data *data);
void	hook_s(t_data *data);
void	hook_a(t_data *data);
void	hook_d(t_data *data);
void	hook_left(t_data *data);
void	hook_right(t_data *data);
void	hook_w(t_data *data);
void	return_prev_player_x_y(t_data *data);
int		check_person_it_wall(t_data *data);
int		check_person_it_wall_2(t_data *data);
int		check_person_it_wall_for_point(t_data *data, int x, int y);
int		shutdown(t_data *data);

/* ===END_MLX=== */

/* ===MINIMAP=== */

void	minimap(t_data *data);
void	img_minimap_init(t_data *data, t_img *img, t_img *img_flor);

/* ===END_MINIMAP=== */

/* ___UTIL___ */

void	init_null_data(t_data *data);
void	split_free(char **str);
void	free_fol_line(char *str);
void	free_data_path(t_data *data);
void	malloc_crash_after_init_data(t_data *data);

/* ___EXIT___ */

void	exit_standard(t_data *data);

#endif
