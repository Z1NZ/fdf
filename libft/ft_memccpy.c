/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:35:16 by srabah            #+#    #+#             */
/*   Updated: 2014/11/05 16:35:55 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dp;
	const char		*sp;

	sp = s2;
	dp = s1;
	while (n--)
	{
		if (*sp == c)
		{
			*dp++ = *sp++;
			return (dp);
		}
		*dp++ = *sp++;
	}
	return (NULL);
}
