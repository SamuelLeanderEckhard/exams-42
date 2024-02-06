//#include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

# define OK 0
# define FAILURE 1

int	ft_strlen(const char *str)
{
	int i = 0;
	if (!str)
		return (OK);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	size;
	int	i;
	int	x;
	char	*str;
	
	i = 0;
	x = -1;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[++x])
	{
		str[i++] = s2[x];
		if (s2[x] == '\n')
			break ;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_buffer_manager(char *buffer)
{
	int	flag;
	int	i;
	int	x;
	
	flag = 0;
	i = 0;
	x = 0;
	while (buffer[i])
	{
		if (flag)
			buffer[x++] = buffer[i];
		if (buffer[i] == '\n')
			flag = 1;
		buffer[i++] = '\0';
	}
	return (flag);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE +1];
	char		*str;
	int		i;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	str = NULL;
	while (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		if (ft_buffer_manager(buffer))
			break ;
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
	}
	return (str);
}

