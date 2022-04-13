#include "../../include/cube3d.h"

void check_valid_file_format(char **argv)
{
	if (ft_strlen(argv[1]) == 0)
		error(ERR_FILE_FORMAT);
	if (ft_strcmp_end(argv[1], ".cub") != 0)
		error(ERR_FILE_FORMAT);
}

void check_valid_file_not_directory(char **argv)
{
	int	fd;

	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		error(ERR_FILE_IS_DIR);
}

int	open_map(char **argv)
{
	int fd = -1;

	check_valid_file_format(argv);
	check_valid_file_not_directory(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(ERR_FILE_OPEN);
	else
		return fd;
	return fd;
}