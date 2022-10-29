/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:52:55 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/25 16:43:48 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strtlen(const char *s, char t)
{
	size_t	len;

	if (s == NULL)
		return (0UL);
	len = 0;
	while (s[len] != t)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;

	if (s == NULL)
		return (NULL);
	i = 0;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *)(&s[i]));
		i++;
	}
	if (chr == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;

	i = 0;
	s1_len = ft_strtlen(s1, '\0');
	s2_len = ft_strtlen(s2, '\0');
	joined_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	while (i < s1_len)
	{
		joined_str[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		joined_str[i] = s2[i - s1_len];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}

char	*ft_strdup(const char *s1)
{
	size_t	src_size;
	size_t	i;
	char	*cpy;

	src_size = ft_strtlen(s1, '\0') + 1;
	cpy = (char *)malloc(src_size * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0UL;
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_i;
	size_t	s_i;
	char	*substr;

	substr = (char *)malloc((len + 1UL) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	substr_i = 0;
	s_i = 0;
	while (s[s_i] != '\0')
	{
		if (s_i >= start && substr_i < len)
		{
			substr[substr_i] = s[s_i];
			substr_i++;
		}
		s_i++;
	}
	substr[substr_i] = '\0';
	return (substr);
}
