/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:42:23 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:47:41 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * Reads from the file descriptor into the buffer.
 * @param chest The buffer where the file content is stored.
 * @param fd The file descriptor.
 * @return The updated buffer after reading from the file.
 */
char	*read_file(char *chest, int fd)
{
	int		read_size;
	char	*buf;
	char	*tmp;

	read_size = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read_size > 0 && !ft_strchr(chest, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (free(chest), free(buf), NULL);
		buf[read_size] = '\0';
		tmp = ft_strjoin(chest, buf);
		free(chest);
		chest = tmp;
	}
	return (free(buf), chest);
}

/**
 * Extracts a line from the buffer.
 * @param chest The buffer where the file content is stored.
 * @param i The index to start extracting from.
 * @return The extracted line.
 */
char	*extract_line(char *chest, int i)
{
	char	*line;

	if (!chest[i])
		return (NULL);
	while (chest[i] != '\0' && chest[i] != '\n')
		i++;
	if (chest[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (chest[i] != '\0' && chest[i] != '\n')
	{
		line[i] = chest[i];
		i++;
	}
	if (chest[i] == '\n')
	{
		line[i] = chest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/**
 * Updates the buffer after a line has been extracted.
 * @param chest The buffer where the file content is stored.
 * @return The updated buffer.
 */
char	*update_chest(char *chest)
{
	char	*new_chest;
	int		i;
	int		j;

	i = 0;
	while (chest[i] != '\n' && chest[i] != '\0')
		i++;
	if (!chest[i])
		return (free(chest), NULL);
	new_chest = malloc(sizeof(char) * (ft_strlen(chest) - i + 1));
	if (!new_chest)
		return (free(chest), NULL);
	i++;
	j = 0;
	while (chest[i] != '\0')
	{
		new_chest[j] = chest[i];
		i++;
		j++;
	}
	new_chest[j] = '\0';
	return (free(chest), new_chest);
}

/**
 * Reads a line from a file descriptor.
 * @param fd The file descriptor.
 * @return The read line.
 */
char	*get_next_line(int fd)
{
	static char	*chest[1024];
	char		*get_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	if (!chest[fd])
	{
		chest[fd] = ft_calloc(1, 1);
		if (!chest[fd])
			return (NULL);
	}
	chest[fd] = read_file(chest[fd], fd);
	if (!chest[fd])
		return (NULL);
	get_line = extract_line(chest[fd], 0);
	chest[fd] = update_chest(chest[fd]);
	return (get_line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main(int argc, char *argv[])
// {
// 	int	fd;

// 	fd = open(argv[1], O_RDONLY);// file descriptor, open only readable file

//     if (fd == -1 || argc != 2)
// 	{
//         printf("ERROR: wrong file descriptor or file name.\n");
//         return (1);
//     }
// 	printf("%s", get_next_line(fd));
//     close(fd);
//     return 0;
// }
// int main(int argc, char *argv[])
// {
//     char	*line;
// 	int	fd;

// 	fd = open(argv[1], O_RDONLY);// file descriptor, open only readable file

//     if (fd == -1 || argc != 2)
// 	{
//         printf("ERROR: wrong file descriptor or file name.\n");
//         return (1);
//     }
//     while ((line = get_next_line(fd)) != NULL)
// 	{
//         printf("%s", line);
//     }
// 	free(line);
//     close(fd);
//     return 0;
// }
// int main(void)
// {
// 	int	fd;
// 	fd = fileno(stdin);

//     if (fd == -1)
// 	{
//         printf("ERROR: wrong file descriptor or file name.\n");
//         return (1);
//     }
// 	printf("%s", get_next_line(fd));
//     close(fd);
//     return 0;
// }