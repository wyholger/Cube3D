#ifndef CUBE3D_CUBE3D_H
# define CUBE3D_CUBE3D_H
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

# define ERR_NUM_ARG "\033[0;31mError. Number arg error. You need ./cube3D <path_to_map>\033[0;0m"
# define ERR_FILE_FORMAT "\033[0;31mError. File format should be <name>.cub\033[0;0m"
# define ERR_FILE_OPEN "\033[0;31mError. Open file error.\033[0;0m"
# define ERR_FILE_IS_DIR "\033[0;31mError. Argument is directory.\033[0;0m"
# define ERR_MALLOC "\033[0;31mError. Malloc error.\033[0;0m"
# define ERR_INVALID_PROPERT "\033[0;31mError. Not valid properties map. \nNeed lines:\nNO ...\nSO ...\nWE ...\nEA ...\n(and colors floor and ceiling)\nF ...\nC ...\033[0;0m"
# define ERR_INVALID_CHAR "\033[0;31mError. Map contains an invalid character.\nValid characters: '1' '0' 'N' 'S' 'W' 'E'\033[0;0m"
# define ERR_MANY_CHARACTER "\033[0;31mError. Map contains more than one character. ('N' 'S' 'W' 'E')\033[0;0m"
# define ERR_NO_CHARACTER "\033[0;31mError. Map does not contain any character. ('N' 'S' 'W' 'E')\033[0;0m"
# define ERR_TOO_SMALL_MAP "\033[0;31mError. To small map\033[0;0m"
# define ERR_OPEN_BORDER "\033[0;31mError. Open border map.\033[0;0m"
# define ERR_COLOR_FORMAT "\033[0;31mError. No valid color format.\nNeed int (color > 0 and color < 256)\033[0;0m"
# define ERR_OPEN_IMG "\033[0;31mError. Open img error.\033[0;0m"
# define ERR_MLX "\033[0;31mError. Mlx error.\033[0;0m"

# define PATH_IMG_M_MAP "sprite/board_mini_map_60.png"
# define PATH_IMG_M_MAP_FLOR "sprite/board_mini_map_20.png"
//# define PATH_IMG_M_MAP "/Users/wyholger/Desktop/projects/Cube3D/sprite/board_mini_map_60.png"
//# define PATH_IMG_M_MAP_FLOR "/Users/wyholger/Desktop/projects/Cube3D/sprite/board_mini_map_20.png"

typedef struct s_ray
{
	float 	direction;
	int 	stepX;
	int 	stepY;
	int 	x_now;
	int 	y_now;
	float	sin_dir;
	float	cos_dir;
	float 	offset_x;
	float	offset_y;
}			t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef struct s_img
{
	void	*img;
	int 	x_sz;
	int 	y_sz;
}			t_img;

typedef struct s_all_img
{
	t_img	sprite_mini;
	t_img	sprite_mini_flor;
}			t_all_img;

typedef struct s_player
{
	float	x;
	float 	y;
	float 	offset_x;
	float 	offset_y;
	int 	x_i;
	int 	y_i;
	float 	direction;
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
	int 		g_f;
	int			b_f;
	int			r_c;
	int 		g_c;
	int			b_c;
	int			flag_malloc_crash;
	int			flag_count_pers;
	int			flag_no_valid_char;
	int 		flag_first_draw_minimap;
	int 		max_len_map;
	int 		max_height_map;
	t_mlx		mlx;
	t_all_img	imgs;
	t_player	player;
	t_ray		ray;
}			t_data;



/* ===START_PARSER=== */

/* _ERROR_ */

void	error_num_arg(int argc);
void	error(char *err);
void	exit_after_validate(t_data *data, int flag_exit);

/* _FILE_READ_WORK_ */

void	check_valid_file_format(char **argv);
int		open_map(char **argv);
void	read_map(t_data *data, char **argv);
void 	check_direction(t_data *data, t_list *list, int i);
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

/* ===RAY_CASTING=== */

void	draw_player(t_data *data);
void	draw_ray(t_data *data);

/* ===END_RAY_CASTING=== */

/* ===MLX=== */

void	mlx_initialise(t_data *data);

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
