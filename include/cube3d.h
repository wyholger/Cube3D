#ifndef CUBE3D_CUBE3D_H
# define CUBE3D_CUBE3D_H
# include "../libft/libft.h"
# include <stdio.h>
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


typedef struct s_data
{
	t_list	*map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		r_f;
	int 	g_f;
	int		b_f;
	int		r_c;
	int 	g_c;
	int		b_c;
	int		flag_malloc_crash;
	int		flag_count_pers;
	int		flag_no_valid_char;
	int 	max_len_map;
	int 	max_height_map;

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

int		check_valid_color(t_data *data, char **for_split);
int		check_color_is_int(t_data *data, char **for_split);
int		check_str_is_int(t_data *data, char *for_split);

/* ===END_PARSER=== */

/* ___UTIL___ */

void	init_null_data(t_data *data);
void	split_free(char **str);
void	free_fol_line(char *str);
void	free_data_path(t_data *data);
void	malloc_crash_after_init_data(t_data *data);

/* ___EXIT___ */

void	exit_standard(t_data *data);

#endif
