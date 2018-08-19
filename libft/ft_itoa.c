/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 01:37:28 by srabah            #+#    #+#             */
/*   Updated: 2014/11/11 07:44:16 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned	int	convert_to_unsigned(int n, int *positif)
{
	unsigned int		nb;

	if (n < 0)
	{
		*positif = 1;
		n = -n;
	}
	nb = (unsigned int)n;
	return (nb);
}

static	int				howlong(unsigned int tmp)
{
	int					i;

	i = 0;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}

char					*ft_itoa(int n)
{
	int					j;
	char				*str;
	int					i;
	int					positif;
	unsigned int		new;

	j = 0;
	positif = 0;
	if (n == 0)
		return (ft_strdup("0"));
	new = convert_to_unsigned(n, &positif);
	i = howlong(new);
	str = (char*)malloc(sizeof(char*) * i + 1);
	while (new / 10 > 0)
	{
		str[j] = new % 10 + '0';
		new /= 10;
		j++;
	}
	str[j] = new % 10 + '0';
	if (positif == 1)
		str[++j] = '-';
	str[j + 1] = '\0';
	ft_strrev(str);
	return (str);
}
