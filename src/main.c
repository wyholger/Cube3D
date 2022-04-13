#include "../include/cube3d.h"

int main(int argc, char **argv)
{
	t_data data;

	init_null_data(&data);
	error_num_arg(argc);
	read_map(&data, argv);
	exit_standard(&data);
	return 0;
}
