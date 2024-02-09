/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:59:38 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/27 14:36:53 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	k;
	size_t	l;
	char	*scat;

	k = 0;
	l = 0;
	scat = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)(s1)) + ft_strlen((char *)(s2)) + 1));
	if (!scat)
		return (NULL);
	while (s1[k] != '\0')
	{
		scat[k] = s1[k];
		k++;
	}
	while (s2[l] != '\0')
	{
		scat[k] = s2[l];
		k++;
		l++;
	}
	scat[k] = '\0';
	return (scat);
}

char	*ft_strchr(const char *str, int x)
{
	int				i;
	unsigned char	temp;

	i = 0;
	temp = (unsigned char)x;
	while (str[i] != '\0')
	{
		if (str[i] == temp)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == temp)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	ptr = (char *)malloc(sizeof(char) * (j + 1));
	if (!ptr)
	{
		return (NULL);
	}
	while (i < j)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = NULL;
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (n * size))
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}
