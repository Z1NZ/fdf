/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 02:17:21 by srabah            #+#    #+#             */
/*   Updated: 2015/02/27 22:48:54 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		eco_update_map(int i, int j)
{
	t_point *p;

	p = malloc(sizeof(t_point) * 1);
	p->x = j;
	p->y = i;
	p->z = g()->map.tab[i][j];
	ft_check_color(i, j);
	if (j + 1 < g()->map.long_x && g()->map.tab[i][j + 1] != -2147483648)
	{
		if (g()->buf.vue)
			ft_iso(p, j + 1, i, g()->map.tab[i][j + 1]);
		else
			ft_par(p, j + 1, i, g()->map.tab[i][j + 1]);
	}
	ft_check_color2(i, j);
	if (i + 1 < g()->map.long_y && g()->map.tab[i + 1][j] != -2147483648)
	{
		if (g()->buf.vue)
			ft_iso(p, j, i + 1, g()->map.tab[i + 1][j]);
		else
			ft_par(p, j, i + 1, g()->map.tab[i + 1][j]);
	}
}

int 	expose_hook(void)
{
	update_map();
	return (1);
}

void		update_map(void)
{
	int i;
	int j;

	i = 0;
	ft_bzero(g()->env.img_data, L_W * H_W * 4);
	while (i < g()->map.long_y)
	{
		j = 0;
		while (j < g()->map.long_x && g()->map.tab[i][j] != -2147483648)
		{
			eco_update_map(i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window (g()->env.mlx, g()->env.win, g()->env.img, 0, 0);
	mlx_string_put(g()->env.mlx, g()->env.win, 10, 10, 0x00FF00, g()->map.name);
	mlx_string_put(g()->env.mlx, g()->env.win, 10, 25, 0x00FF00, "BY SRABAH");
}

int			loop_hook(void *param)
{
	param = param;
	return (1);
}

int			key_hook(int keycode)
{
	if (keycode == 65307)
		exit(1);
	if (keycode == UP)
		g()->buf.posy += 10;
	if (keycode == DOWN)
		g()->buf.posy -= 10;
	if (keycode == RIGHT)
		g()->buf.posx += 10;
	if (keycode == LEFT)
		g()->buf.posx -= 10;
	if (keycode == PLUS)
		g()->buf.zoom += 1;
	if (keycode == MOIN)
		g()->buf.zoom -= 1;
	if (keycode == ALTIPLUS)
		g()->buf.higt += 10;
	if (keycode == ALTIMOIN)
		g()->buf.higt -= 10;
	if (keycode == VIEW)
		g()->buf.vue = (g()->buf.vue == 1) ? 0 : 1;
	update_map();
	return (1);
}
