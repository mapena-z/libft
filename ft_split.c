/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:56:30 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/23 16:56:37 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			words++;
			while (str[i] && str[i + 1] && str[i] == c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

int	len_word_array(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

void	free_mem(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

void	create_words(char **array, char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
		{
			array[j] = ft_substr(str, 0, len_word_array(str, c));
			if (array[j] == NULL)
			{
				free_mem(array, j);
				return (NULL);
			}
			str = str + len_word_array(str,c);
			j++;
		}		
	}
	array[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**array;

	if (!s)
		return (NULL);
	array = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	create_words(array, s, c);
	return (array);
}
