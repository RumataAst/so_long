/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:47:46 by akretov           #+#    #+#             */
/*   Updated: 2024/06/05 18:46:22 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line_bonus.h"

// char	*ft_strdup(const char *s)
// {
// 	size_t		i;
// 	size_t		j;
// 	char		*temp;

// 	i = ft_strlen(s);
// 	j = 0;
// 	temp = (char *)malloc(sizeof (char) * i + 1);
// 	if (!temp)
// 		return (0);
// 	while (j < i)
// 	{
// 		temp[j] = s[j];
// 		j++;
// 	}
// 	temp[i] = '\0';
// 	return (temp);
// }

static char	*extract(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free (temp);
		temp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (temp);
}

static char	*read_line(int fd, char *buf, char *backup)
{
	int		test;
	char	*temp;

	test = 1;
	while (test)
	{
		test = read(fd, buf, BUFFER_SIZE);
		if (test == -1)
			return (0);
		else if (test == 0)
			break ;
		buf[test] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		if (!backup)
			return (NULL);
		free (temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, backup[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup[fd] = extract(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd1,fd2,fd3;
// 	char	*line;
// 	char	*line_1;
// 	char	*line;

// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("test1.txt", O_RDONLY);
// 	fd3 = open("test2.txt", O_RDONLY);

// 	while (1)
// 	{
// 		line = get_next_line(fd1);
// 		if (!line)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		printf("%s", line);
// 		free(line);
// 				line = get_next_line(fd2);
// 		if (!line)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		printf("%s", line);
// 		free(line);
// 				line = get_next_line(fd3);
// 		if (!line)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
