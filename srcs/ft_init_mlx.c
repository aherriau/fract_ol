/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:25:35 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 13:33:39 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		ft_init_hook(t_env *e)
{
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, ft_keypress_hook, e);
	mlx_hook(e->win, BUTTONPRESS, BUTTONPRESSMASK, ft_button_press_hook, e);
	mlx_hook(e->win, MOTIONNOTIFY, BUTTONMOTIONMASK, ft_motion_notify_hook, e);
}

void		ft_mandel(t_fractal *fractal)
{
	fractal->origin_min_x[0] = -2.0;
	fractal->origin_max_x[0] = 0.5;
	fractal->origin_min_y[0] = -1.25;
	fractal->origin_max_y[0] = 1.25;
	fractal->origin_min_x[1] = -1.83912037037037023879;
	fractal->origin_max_x[1] = -1.68287037037037023879;
	fractal->origin_min_y[1] = -0.07841435185185188783;
	fractal->origin_max_y[1] = 0.07783564814814811217;
	fractal->origin_min_x[2] = -1.62680913783885849888;
	fractal->origin_max_x[2] = -1.62679006435253037388;
	fractal->origin_min_y[2] = -0.02365827560424820300;
	fractal->origin_max_y[2] = -0.02363920211792007800;
	fractal->origin_min_x[3] = -0.12392961868533795833;
	fractal->origin_max_x[3] = -0.08486711868533795833;
	fractal->origin_min_y[3] = -0.91386762095822460239;
	fractal->origin_max_y[3] = -0.87480512095822460239;
	fractal->min_x = fractal->origin_min_x[0];
	fractal->max_x = fractal->origin_max_x[0];
	fractal->min_y = fractal->origin_min_y[0];
	fractal->max_y = fractal->origin_max_y[0];
	fractal->origin_c_x = 0;
	fractal->origin_c_y = 0;
	fractal->c_x = fractal->origin_c_x;
	fractal->c_y = fractal->origin_c_y;
}

t_fractal	ft_init_fractal(t_env *e)
{
	t_fractal	fractal;

	fractal.color = 1;
	fractal.origin_max_iter = 212;
	fractal.max_iter = 212;
	fractal.info = 0;
	fractal.move = 0;
	fractal.x = 0;
	fractal.y = 0;
	fractal.speed = 0.1;
	if (e->name == MANDEL)
		ft_mandel(&fractal);
	if (e->name == JULIA)
		ft_julia(&fractal);
	if (e->name == SHIP)
		ft_ship(&fractal);
	if (e->name == PREY)
		ft_prey(&fractal);
	if (e->name == MAND5)
		ft_mand5(&fractal);
	if (e->name == INV)
		ft_inv(&fractal);
	return (fractal);
}

t_image		ft_new_image(t_env *e, int width, int height)
{
	t_image		image;

	image.width = width;
	image.height = height;
	image.img = mlx_new_image(e->mlx, image.width, image.height);
	if (image.img != NULL)
		image.data = (int *)mlx_get_data_addr(image.img, &(image.bpp),
				&(image.sl), &(image.endian));
	return (image);
}

int			ft_init_mlx(t_env *e, char *filename, int width, int height)
{
	char		*name;
	t_cl		cl;

	name = ft_strjoin("fract_ol: ", filename);
	e->win = mlx_new_window(e->mlx, width, height, name);
	ft_strdel(&name);
	if (e->win == NULL)
		return (0);
	e->fractal = ft_init_fractal(e);
	cl.list_size = 1080 * 1080;
	e->cl = cl;
	ft_init_hook(e);
	return (1);
}
