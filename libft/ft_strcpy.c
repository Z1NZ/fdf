/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:33:53 by srabah            #+#    #+#             */
/*   Updated: 2014/11/03 16:25:52 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcpy(char *strdest, const char *strscr)
{
	int	i;

	i = 0;
	while (strscr[i] != '\0')
	{
		strdest[i] = strscr[i];
		i++;
	}
	strdest[i] = '\0';
	return (strdest);
}
