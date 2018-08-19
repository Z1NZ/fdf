/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 03:16:41 by srabah            #+#    #+#             */
/*   Updated: 2014/11/11 06:27:00 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	a;
	int		f;
	int		d;

	f = ft_strlen(str) - 1;
	d = 0;
	while (d < f && d != f)
	{
		a = str[f];
		str[f] = str[d];
		str[d] = a;
		f--;
		d++;
	}
	return (str);
}
