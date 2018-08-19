/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 02:16:49 by srabah            #+#    #+#             */
/*   Updated: 2015/02/27 22:59:13 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_iso(t_point *p, float xf, float yf, float zf)
{
	float x1;
	float y1;
	float x2;
	float y2;

	x1 = INC * p->x * g()->buf.zoom - INC * p->y *
		g()->buf.zoom + g()->buf.posx;
	x2 = INC * xf * g()->buf.zoom - INC * yf *
		g()->buf.zoom + g()->buf.posx;
	y1 = -p->z * (g()->buf.higt / 10) + (INC / 2) * p->x *
		g()->buf.zoom + (INC / 2) * p->y * g()->buf.zoom + g()->buf.posy;
	y2 = -zf * (g()->buf.higt / 10) + (INC / 2) * xf *
		g()->buf.zoom + (INC / 2) * yf * g()->buf.zoom + g()->buf.posy;
	ft_aff_ligne(x1, y1, x2, y2);
}

void        ft_color_pix(int i)
{
    if (i > 14)
        g()->map.color = BLANC;
    if (i > 10 && i <= 14)
        g()->map.color = MARRON_FONCE;
    else if (i > 6 && i <= 10)
        g()->map.color = MARRON;
    else if (i > 4 && i <= 6)
        g()->map.color = VERT_FONCE;
    else if (i >= 0 && i <= 4)
        g()->map.color = VERT;
    else if (i > -5 && i < 0)
        g()->map.color = BLEU;
    else if (i < -5)
        g()->map.color = BLEU_FONCE;
}

void		ft_par(t_point *p, float xf, float yf, float zf)
{
	float x1;
	float x2;
	float y1;
	float y2;

	x1 = p->x * g()->buf.zoom + INC * -p->z + g()->buf.posx;
	x2 = xf * g()->buf.zoom + INC * -zf + g()->buf.posx;
	y1 = p->y * g()->buf.zoom + (INC / 2) *
		(-p->z * (g()->buf.higt / 10)) + g()->buf.posy;
	y2 = yf * g()->buf.zoom + (INC / 2) *
		(-zf * (g()->buf.higt / 10)) + g()->buf.posy;
	ft_aff_ligne(x1, y1, x2, y2);
}

void		ft_check_color(int i, int j)
{
	if (j <= g()->map.long_x - 1)
	{
		if (g()->map.tab[i][j] == g()->map.tab[i][j + 1])
			ft_color_pix(g()->map.tab[i][j]);
		else if (g()->map.tab[i][j] < g()->map.tab[i][j + 1])
			ft_color_pix(g()->map.tab[i][j + 1]);
		else if (g()->map.tab[i][j] > g()->map.tab[i][j + 1])
			ft_color_pix(g()->map.tab[i][j]);
	}
}

void		ft_check_color2(int i, int j)
{
	if (i <= g()->map.long_y - 1)
	{
		if (i + 1 >= g()->map.long_y)
			ft_color_pix(g()->map.tab[i][j]);
		else if (g()->map.tab[i][j] == g()->map.tab[i + 1][j])
			ft_color_pix(g()->map.tab[i][j]);
		else if (g()->map.tab[i][j] < g()->map.tab[i + 1][j])
			ft_color_pix(g()->map.tab[i + 1][j]);
		else if (g()->map.tab[i][j] > g()->map.tab[i + 1][j])
			ft_color_pix(g()->map.tab[i][j]);
	}
}
