/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:25:22 by srabah            #+#    #+#             */
/*   Updated: 2014/11/07 18:05:10 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl(char const *s)
{
	int		i;
	char	*ptrs;

	i = 0;
	ptrs = (char*)s;
	while (ptrs[i] != '\0')
		ft_putchar(ptrs[i++]);
	ft_putchar('\n');
}
