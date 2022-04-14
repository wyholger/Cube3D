//#include "get_next_line.h"
#include "libft.h"

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	char	*str;
//	size_t	i;
//	size_t	o;
//
//	i = 0;
//	o = 0;
//	if (!s1 || !s2)
//		return (NULL);
//	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//	if (!str)
//		return (NULL);
//	while (s1[i])
//	{
//		str[i] = s1[i];
//		i++;
//	}
//	while (s2[o])
//	{
//		str[i++] = s2[o++];
//	}
//	str[i] = '\0';
//	return (str);
//}

int	mr_cleaner(char **a)
{
	if (*a)
	{
		free(*a);
		*a = NULL;
	}
	return (0);
}

char	*check_memder(char *member, char **line)
{
	char	*p_n_l;
	char	*tmp;

	tmp = NULL;
	(void)tmp;
	p_n_l = NULL;
	if (member)
	{
		p_n_l = ft_strchr(member, '\n');
		if (p_n_l)
		{
			*p_n_l++ = '\0';
			tmp = *line;
			*line = ft_strjoin(member, "");
			member = ft_memmove(member, p_n_l, ft_strlen(p_n_l));
			member[ft_strlen(p_n_l)] = '\0';
		}
		else
		{
			tmp = *line;
			*line = ft_strjoin(member, "");
			ft_bzero(member, ft_strlen(member));
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (p_n_l);
}

int	bufer_nl(char *bufer, char **pointer_n_line, char **member)
{
	char	*tmp;

	*pointer_n_line = ft_strchr(bufer, '\n');
	if (*pointer_n_line)
	{
		*(*pointer_n_line) = '\0';
		*pointer_n_line = *pointer_n_line + 1;
		if (*(*pointer_n_line) != '\0')
		{
			tmp = *member;
			*member = ft_strjoin(*pointer_n_line, "");
			mr_cleaner(&tmp);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*member;
	char		bufer[BUFFER_SIZE + 1];
	int			read_len;
	char		*pointer_n_line;
	char		*tmp;

	if (fd < 0 || fd > 256 || !line || BUFFER_SIZE < 1)
		return (-1);
	read_len = 1;
	pointer_n_line = check_memder(member, line);
	while (!pointer_n_line && read_len)
	{
		read_len = read(fd, bufer, BUFFER_SIZE);
		if (read_len == -1)
			return (-1);
		bufer[read_len] = '\0';
		bufer_nl(&bufer[0], &pointer_n_line, &member);
		tmp = *line;
		*line = ft_strjoin(*line, bufer);
		mr_cleaner(&tmp);
	}
	if (read_len == 0)
		return (mr_cleaner(&member));
	return (1);
}
