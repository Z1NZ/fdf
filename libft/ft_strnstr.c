/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:47:00 by srabah            #+#    #+#             */
/*   Updated: 2014/11/09 01:35:53 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2 || !s2[0])
		return ((char *)s1);
	while (s1[j] != '\0' && j < len)
	{
		i = 0;
		while (s2[i] == s1[j + i] && j + i < len && s2[i] != '\0'
				&& s1[j + i] != '\0')
			i++;
		if (s2[i] == '\0')
			return ((char *)s1 + j);
		j++;
	}
	return (0);
}
