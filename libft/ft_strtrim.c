/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 02:12:11 by srabah            #+#    #+#             */
/*   Updated: 2014/11/11 06:00:48 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		j;
	int		i;
	int		k;
	char	*result;

	if (!s)
		return (NULL);
	j = 0;
	result = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	k = 0;
	while (j <= i)
		result[k++] = s[j++];
	result[k] = '\0';
	return (result);
}
