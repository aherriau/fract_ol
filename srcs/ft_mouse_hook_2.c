/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 00:17:45 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 00:18:07 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_button_1(t_env *e, int x, int y)
{
	double	d;
	double	xr;
	double	yr;

	d = (e->fractal.max_x - e->fractal.min_x);
	xr = e->fractal.min_x + d / e->image.width * x;
	yr = e->fractal.min_y + d / e->image.height * y;
	if ((xr - d / 4) != (xr + d / 4))
	{
		e->fractal.min_x = xr - d / 4;
		e->fractal.max_x = xr + d / 4;
		e->fractal.min_y = yr - d / 4;
		e->fractal.max_y = yr + d / 4;
		ft_process_mlx(e);
	}
}

void	ft_button_2(t_env *e, int x, int y)
{
	double	d;
	double	xr;
	double	yr;

	d = (e->fractal.max_x - e->fractal.min_x);
	xr = e->fractal.max_x - d / e->image.width * x;
	yr = e->fractal.max_y - d / e->image.height * y;
	e->fractal.min_x = xr - d;
	e->fractal.max_x = xr + d;
	e->fractal.min_y = yr - d;
	e->fractal.max_y = yr + d;
	ft_process_mlx(e);
}

void	ft_button_4(t_env *e)
{
	double	d;
	double	xr;
	double	yr;

	d = (e->fractal.max_x - e->fractal.min_x);
	xr = (3 / 4.0) * ((e->fractal.min_x + e->fractal.max_x) / 2) +
		(1 / 4.0) * (e->fractal.min_x + d / e->image.width * e->fractal.x);
	yr = (3 / 4.0) * ((e->fractal.min_y + e->fractal.max_y) / 2) +
		(1 / 4.0) * (e->fractal.min_y + d / e->image.height * e->fractal.y);
	if ((xr - d / 2 / 1.1) != (xr + d / 2 / 1.1))
	{
		e->fractal.min_x = xr - d / 2 / 1.1;
		e->fractal.max_x = xr + d / 2 / 1.1;
		e->fractal.min_y = yr - d / 2 / 1.1;
		e->fractal.max_y = yr + d / 2 / 1.1;
		ft_process_mlx(e);
	}
}

void	ft_button_5(t_env *e)
{
	double	d;
	double	xr;
	double	yr;

	d = (e->fractal.max_x - e->fractal.min_x);
	xr = (3 / 4.0) * ((e->fractal.min_x + e->fractal.max_x) / 2) +
		(1 / 4.0) * (e->fractal.max_x - d / e->image.width * e->fractal.x);
	yr = (3 / 4.0) * ((e->fractal.min_y + e->fractal.max_y) / 2) +
		(1 / 4.0) * (e->fractal.max_y - d / e->image.height * e->fractal.y);
	e->fractal.min_x = xr - d / 2 * 1.1;
	e->fractal.max_x = xr + d / 2 * 1.1;
	e->fractal.min_y = yr - d / 2 * 1.1;
	e->fractal.max_y = yr + d / 2 * 1.1;
	ft_process_mlx(e);
}
