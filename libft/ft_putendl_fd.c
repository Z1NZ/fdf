/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:43:45 by srabah            #+#    #+#             */
/*   Updated: 2014/11/07 18:45:22 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	*ptrs;

	i = 0;
	ptrs = (char*)s;
	while (ptrs[i] != '\0')
		ft_putchar_fd(ptrs[i++], fd);
	ft_putchar_fd('\n', fd);
}
