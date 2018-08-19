/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 02:30:06 by srabah            #+#    #+#             */
/*   Updated: 2014/11/11 06:51:38 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*demoncu;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		demoncu = (char*)malloc(ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			demoncu[i] = (*f)(i, s[i]);
			i++;
		}
		return (demoncu);
	}
	return (0);
}
