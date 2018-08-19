/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 02:23:22 by srabah            #+#    #+#             */
/*   Updated: 2014/11/07 18:14:20 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	tmp[n];
	char	*pdest;
	char	*psrc;
	size_t	i;

	i = 0;
	pdest = (char *)dest;
	psrc = (char *)src;
	if (n == 0)
		return (0);
	while (i < n)
	{
		tmp[i] = psrc[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		pdest[i] = tmp[i];
		i++;
	}
	return (pdest);
}
