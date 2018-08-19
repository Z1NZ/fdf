/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 00:06:26 by srabah            #+#    #+#             */
/*   Updated: 2014/11/11 22:19:32 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	int mem;

	i = 0;
	mem = -1;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			mem = i;
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char*)&s[i]);
	if (mem != -1)
		return ((char *)&s[mem]);
	return (NULL);
}
