/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 23:42:58 by srabah            #+#    #+#             */
/*   Updated: 2015/02/27 22:57:39 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define L_W 2800
# define H_W 1400
# define TAILLE_DES_CASE 10
# define INC 0.75
# define COL_B(i) (i >> 16) & 0x000000ff
# define COL_G(i) (i >> 8) & 0x000000ff
# define COL_R(i) i & 0x000000ff
# define BLEU 0x0066FF
# define BLEU_FONCE 0x3300CC
# define VERT_FONCE 0x006600
# define VERT 0x009933
# define BLANC 0xFAF0E6
# define MARRON_FONCE 0xA76726
# define MARRON 0xD2691E

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

typedef	struct	s_buf
{
	int			posx;
	int			posy;
	int			bufz;
	int			zoom;
	int			vue;
	int			higt;
	int			angle;
}				t_buf;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
}				t_env;

typedef struct	s_map
{
	int			**tab;
	int			long_x;
	int			long_y;
	int			color;
	char		*name;
}				t_map;

typedef struct	s_global
{
	t_env		env;
	t_buf		buf;
	t_map		map;
}				t_global;

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef enum	e_keys
{
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65361,
	LEFT = 65363,
	PLUS = 65451,
	MOIN = 65453,
	ALTIPLUS = 65450,
	ALTIMOIN = 65455,
	VIEW = 65469,
}				t_keys;

t_global		*g(void);
void			ft_put_img_pix(int x, int y, int color);
void			eco_aff_ligne(float tab[4], float y, float x);
void			ft_aff_ligne(float x, float y, float xf, float yf);
int				ft_strlen2(char **line);
void			ft_iso(t_point *p, float xf, float yf, float zf);
void			ft_color_pix(int i);
void			ft_par(t_point *p, float xf, float yf, float zf);
void			ft_check_color(int i, int j);
void			ft_check_color2(int i, int j);
void			eco_update_map(int i, int j);
void			update_map(void);
int				loop_hook(void *param);
void			ft_creattab(int y, int x, char *path);
void			init_struct(void);
void			ft_compt(int fd, char *path);
int				key_hook(int keycode);
void			eco_ft_creat(int nb[5], int x, int y);
int 			expose_hook(void);

#endif
