/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 03:30:27 by srabah            #+#    #+#             */
/*   Updated: 2014/11/11 22:14:42 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	if ((!s2 && !s1) || n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = ft_strncmp(s1, s2, n - 1);
	if (i != 0)
		return (0);
	else
		return (1);
}
