/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:55:16 by srabah            #+#    #+#             */
/*   Updated: 2014/11/11 08:12:37 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*demoncu;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		demoncu = (char*)malloc(ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			demoncu[i] = (*f)(s[i]);
			i++;
		}
		return (demoncu);
	}
	return (NULL);
}
