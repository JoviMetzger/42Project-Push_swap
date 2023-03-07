/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 10:00:04 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/01/12 00:20:31 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	3.	after extracting the line that was read, we don't need those characters 
 *  	anymore.
	3.1 this function clears the stash so only he characters that have not been 
		returned at, the end of get_next_line() remain in our static stash. */

char	*clear_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = ft_strlen(stash);
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (j - i));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

/*	2. extracts all characters from our stash and stores them in out line.
	2.1 stopped after the first \n is encountered. */

char	*add_to_stash(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[0] == '\0')
		return (NULL);
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/*	1. uses read() to add characters to the stash. 
	1.1 adds the content of our buffer to the end of our stash. */

char	*read_and_stash(int fd, char *stash, char *read_file, char *str)
{
	int	read_bytes;

	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, stash, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		stash[read_bytes] = '\0';
		read_file = str;
		if (!read_file)
		{
			read_file = (char *)malloc(sizeof(char) * 1);
			read_file[0] = '\0';
		}
		str = ft_strjoin(read_file, stash);
		free(read_file);
		if (gnl_strchr(str) == 1)
			break ;
	}
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*stash;
	char		*read_file;	

	read_file = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	stash = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);
	str = read_and_stash(fd, stash, read_file, str);
	if (!str)
		return (NULL);
	line = add_to_stash(str);
	str = clear_stash(str);
	return (line);
}

//GET_NEXT_LINE_UTILS

int	gnl_strchr(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
