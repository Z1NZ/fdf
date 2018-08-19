/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 23:45:04 by srabah            #+#    #+#             */
/*   Updated: 2015/01/04 01:55:08 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		eco_ft_creat(int nb[5], int x, int y)
{
	char	*line;
	char	**tmp;

	while ((nb[5] = get_next_line(nb[2], &line)) > 0)
	{
		nb[1] = 0;
		tmp = ft_strsplit(line, ' ');
		g()->map.tab[y] = (int *)ft_memalloc(sizeof(int) * (x + 1));
		while (tmp[nb[1]])
		{
			g()->map.tab[y][nb[1]] = ft_atoi(tmp[nb[1]]);
			nb[1]++;
		}
		g()->map.tab[y][nb[1]] = 0;
		while (nb[5] < x)
		{
			g()->map.tab[y][nb[1]] = -2147483648;
			nb[5]++;
		}
		y++;
		ft_strdel(&line);
	}
}

void		ft_creattab(int y, int x, char *path)
{
	int		nb[5];

	nb[2] = open(path, O_RDONLY);
	g()->map.tab = (int **)ft_memalloc(sizeof(int *) * (y + 1));
	g()->env.mlx = mlx_init();
	g()->env.win = mlx_new_window(g()->env.mlx, L_W, H_W, "42");
	g()->env.img = mlx_new_image (g()->env.mlx, L_W, H_W);
	g()->env.img_data = mlx_get_data_addr(g()->env.img, &nb[0], &nb[3], &nb[4]);
	y = 0;
	eco_ft_creat(nb, x, y);
	update_map();
	mlx_loop_hook(g()->env.mlx, loop_hook, NULL);
	mlx_key_hook(g()->env.win, key_hook, NULL);
	mlx_expose_hook(g()->env.win, expose_hook, NULL);
	mlx_loop(g()->env.mlx);
}

void		init_struct(void)
{
	g()->buf.posy = 160;
	g()->buf.posx = 570;
	g()->map.long_y = -1;
	g()->map.long_x = 0;
	g()->buf.zoom = 10;
	g()->buf.higt = 10;
	g()->buf.vue = 1;
	g()->map.color = 0xA76726;
}

void		ft_compt(int fd, char *path)
{
	char	*line;
	int		test;

	line = NULL;
	test = 1;
	init_struct();
	while (test == 1)
	{
		test = get_next_line(fd, &line);
		g()->map.long_y++;
		if (ft_strlen2(ft_strsplit(line, ' ')) > g()->map.long_x)
			g()->map.long_x = ft_strlen2(ft_strsplit(line, ' '));
	}
	close(fd);
	ft_strdel(&line);
	g()->map.name = path;
	ft_creattab(g()->map.long_y, g()->map.long_x, path);
}

int			main(int argc, char *argv[])
{
	int fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
		{
			ft_putstr("\033[31mfdf: ");
			perror(argv[1]);
			ft_putstr("\033[m");
		}
		else
			ft_compt(fd, argv[1]);
	}
	else
		ft_putendl("\033[31mUn seul argument requis\033[m");
	return (0);
}
