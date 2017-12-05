/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:44:40 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 12:45:30 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_keypress_tool(int keycode, t_env *e)
{
	if (keycode == 18)
	{
		e->fractal.color = 1;
		ft_process_mlx(e);
	}
	if (keycode == 19)
	{
		e->fractal.color = 2;
		ft_process_mlx(e);
	}
	if (keycode == 20)
	{
		e->fractal.color = 3;
		ft_process_mlx(e);
	}
	if (keycode == 34)
	{
		if (e->fractal.info == 0)
			e->fractal.info = 1;
		else
			e->fractal.info = 0;
		ft_process_mlx(e);
	}
}

void	ft_keypress_tool_2(int keycode, t_env *e)
{
	if (keycode == 78)
	{
		if (e->fractal.max_iter - 50 >= 0)
			e->fractal.max_iter -= 50;
		else
			e->fractal.max_iter = 0;
		ft_process_mlx(e);
		if (e->fractal.info == 0)
			ft_iter_info(e);
	}
	if (keycode == 69)
	{
		if (e->fractal.max_iter + 50 <= 1200)
			e->fractal.max_iter += 50;
		else
			e->fractal.max_iter = 1200;
		ft_process_mlx(e);
		if (e->fractal.info == 0)
			ft_iter_info(e);
	}
}

void	ft_keypress_tool_3(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		if (e->fractal.max_iter - 1 >= 0)
			e->fractal.max_iter -= 1;
		ft_process_mlx(e);
		if (e->fractal.info == 0)
			ft_iter_info(e);
	}
	if (keycode == 124)
	{
		if (e->fractal.max_iter + 1 <= 1200)
			e->fractal.max_iter += 1;
		ft_process_mlx(e);
		if (e->fractal.info == 0)
			ft_iter_info(e);
	}
	if (keycode == 12)
	{
		if (e->fractal.move == 0)
			e->fractal.move = 1;
		else
			e->fractal.move = 0;
	}
}

void	ft_keypress_tool_4(int keycode, t_env *e)
{
	double	d;

	if (keycode == 86)
	{
		d = (e->fractal.max_x - e->fractal.min_x);
		e->fractal.min_x -= d / 25;
		e->fractal.max_x -= d / 25;
		ft_process_mlx(e);
	}
	if (keycode == 88)
	{
		d = (e->fractal.max_x - e->fractal.min_x);
		e->fractal.min_x += d / 25;
		e->fractal.max_x += d / 25;
		ft_process_mlx(e);
	}
	if (keycode == 87)
	{
		d = (e->fractal.max_x - e->fractal.min_x);
		e->fractal.min_y += d / 25;
		e->fractal.max_y += d / 25;
		ft_process_mlx(e);
	}
}

void	ft_keypress_tool_5(int keycode, t_env *e)
{
	double	d;
	double	xr;
	double	yr;

	if (keycode == 91)
	{
		d = (e->fractal.max_x - e->fractal.min_x);
		e->fractal.min_y -= d / 25;
		e->fractal.max_y -= d / 25;
		ft_process_mlx(e);
	}
	if (keycode == 24)
	{
		d = (e->fractal.max_x - e->fractal.min_x);
		xr = e->fractal.min_x + d / e->image.width * 540;
		yr = e->fractal.min_y + d / e->image.height * 540;
		if ((xr - d / 4) != (xr + d / 4))
		{
			e->fractal.min_x = xr - d / 4;
			e->fractal.max_x = xr + d / 4;
			e->fractal.min_y = yr - d / 4;
			e->fractal.max_y = yr + d / 4;
			ft_process_mlx(e);
		}
	}
}
