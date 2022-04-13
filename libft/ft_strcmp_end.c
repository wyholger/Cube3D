#include "libft.h"

int strcmp_end_logic(char *arg_1, char *arg_2, int len_1, int len_2)
{
	int i;
	int j;
	int flag;

	i = len_1 - len_2;
	j = 0;
	flag = 0;
	while (arg_1[i] && arg_2[j])
	{
		if (arg_1[i] == arg_2[j])
		{
			i++;
			j++;
		}
		else
			return (-1);
	}
	if (j == len_2 && i == len_1 && flag == 0)
		return (flag);
	else
		return (-1);
}

int	ft_strcmp_end(char *arg_1, char *arg_2)
{
	int len_1;
	int len_2;
	int flag;

	if (arg_1 == NULL || arg_2 == NULL)
		return -1;
	len_1 = ft_strlen(arg_1);
	len_2 = ft_strlen(arg_2);
	if (len_1 == 0 || len_2 == 0)
		return -1;
	flag = strcmp_end_logic(arg_1, arg_2, len_1, len_2);
	return (flag);
}