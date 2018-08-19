/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 02:16:37 by srabah            #+#    #+#             */
/*   Updated: 2015/02/27 22:48:24 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_global	*g(void)
{
	static t_global *sg = NULL;

	if (!sg)
		sg = malloc(sizeof(t_global));
	return (sg);
}

void		ft_put_img_pix(int x, int y, int color)
{
	unsigned long pos;

	if (x < L_W && y < H_W && x >= 0 && y >= 0)
	{
		pos = y * L_W * 4 + x * 4;
		g()->env.img_data[pos] = COL_R(color);
		g()->env.img_data[pos + 1] = COL_G(color);
		g()->env.img_data[pos + 2] = COL_B(color);
	}
}

void		eco_aff_ligne(float tab[4], float y, float x)
{
	int i;

	i = 1;
	tab[4] = tab[0] / 2;
	while (i++ <= tab[0])
	{
		if ((tab[4] += tab[1]) >= tab[0])
		{
			tab[4] -= tab[0];
			y += tab[3];
		}
		ft_put_img_pix((x += tab[2]), y, g()->map.color);
	}
}

void		ft_aff_ligne(float x, float y, float xf, float yf)
{
	float tab[4];
	float i;

	tab[0] = abs(xf - x);
	tab[1] = abs(yf - y);
	tab[2] = (xf - x > 0) ? 1 : -1;
	tab[3] = (yf - y > 0) ? 1 : -1;
	ft_put_img_pix(x, y, g()->map.color);
	if (tab[0] > tab[1])
		eco_aff_ligne(tab, y, x);
	else if ((i = 1))
	{
		tab[4] = tab[1] / 2;
		while (i++ <= tab[1])
		{
			if ((tab[4] += tab[0]) >= tab[1])
			{
				tab[4] -= tab[1];
				x += tab[2];
			}
			ft_put_img_pix(x, (y += tab[3]), g()->map.color);
		}
	}
}

int			ft_strlen2(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}
