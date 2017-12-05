/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_tools_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:44:48 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 12:49:15 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_keypress_tool_6(int keycode, t_env *e)
{
	double	d;
	double	xr;
	double	yr;

	if (keycode == 27)
	{
		d = (e->fractal.max_x - e->fractal.min_x);
		xr = e->fractal.min_x + d / e->image.width * 540;
		yr = e->fractal.min_y + d / e->image.height * 540;
		e->fractal.min_x = xr - d;
		e->fractal.max_x = xr + d;
		e->fractal.min_y = yr - d;
		e->fractal.max_y = yr + d;
		ft_process_mlx(e);
	}
	if (keycode == 125)
	{
		if (e->fractal.speed - 0.004 >= 0)
			e->fractal.speed -= 0.004;
		if (e->fractal.info == 0)
			ft_speed_info(e);
		else
			ft_process_mlx(e);
	}
}

void	ft_keypress_tool_7(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		if (e->fractal.speed + 0.004 <= 0.404)
			e->fractal.speed += 0.004;
		if (e->fractal.info == 0)
			ft_speed_info(e);
		else
			ft_process_mlx(e);
	}
}

void	ft_keypress_tool_8(int keycode, t_env *e)
{
	double	d;
	double	xr;
	double	yr;

	if (keycode == 49)
	{
		d = (e->fractal.max_x - e->fractal.min_x);
		xr = (3 / 4.0) * ((e->fractal.min_x + e->fractal.max_x) / 2) +
			(1 / 4.0) * (e->fractal.min_x + d / e->image.width * e->fractal.x);
		yr = (3 / 4.0) * ((e->fractal.min_y + e->fractal.max_y) / 2) +
			(1 / 4.0) * (e->fractal.min_y + d / e->image.height * e->fractal.y);
		if ((xr - d / 2 / 1.1) != (xr + d / 2 / 1.1))
		{
			e->fractal.min_x = xr - d / 2 / (1 + e->fractal.speed);
			e->fractal.max_x = xr + d / 2 / (1 + e->fractal.speed);
			e->fractal.min_y = yr - d / 2 / (1 + e->fractal.speed);
			e->fractal.max_y = yr + d / 2 / (1 + e->fractal.speed);
			ft_process_mlx(e);
		}
	}
}

void	ft_keypress_tool_9(int keycode, t_env *e)
{
	double	d;
	double	xr;
	double	yr;

	if (keycode == 11)
	{
		d = (e->fractal.max_x - e->fractal.min_x);
		xr = (3 / 4.0) * ((e->fractal.min_x + e->fractal.max_x) / 2) +
			(1 / 4.0) * (e->fractal.max_x - d / e->image.width * e->fractal.x);
		yr = (3 / 4.0) * ((e->fractal.min_y + e->fractal.max_y) / 2) +
			(1 / 4.0) * (e->fractal.max_y - d / e->image.height * e->fractal.y);
		e->fractal.min_x = xr - d / 2 * (1 + e->fractal.speed);
		e->fractal.max_x = xr + d / 2 * (1 + e->fractal.speed);
		e->fractal.min_y = yr - d / 2 * (1 + e->fractal.speed);
		e->fractal.max_y = yr + d / 2 * (1 + e->fractal.speed);
		ft_process_mlx(e);
	}
	if (keycode == 82)
		ft_spot(e, 0);
	if (keycode == 83)
		ft_spot(e, 1);
	if (keycode == 84)
		ft_spot(e, 2);
	if (keycode == 85)
		ft_spot(e, 3);
}
