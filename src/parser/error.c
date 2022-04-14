#include "../../include/cube3d.h"

void	error_num_arg(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd(ERR_NUM_ARG, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
}

void	error(char *err)
{
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}