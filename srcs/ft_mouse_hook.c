/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:40:35 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 00:19:22 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		ft_button_press_hook(int button, int x, int y, t_env *e)
{
	if (y > 4)
	{
		if (button == 1)
			ft_button_1(e, x, y);
		if (button == 2)
			ft_button_2(e, x, y);
		if (button == 4)
			ft_button_4(e);
		if (button == 5)
			ft_button_5(e);
	}
	return (0);
}

int		ft_motion_notify_hook(int x, int y, t_env *e)
{
	double	d;

	if (x > 0 && x < 1080 && y > 4 && y < 1080)
	{
		e->fractal.x = x;
		e->fractal.y = y;
		if (e->fractal.move == 1)
		{
			d = (e->fractal.max_x - e->fractal.min_x);
			e->fractal.c_x = e->fractal.min_x + d / e->image.width * x;
			e->fractal.c_y = e->fractal.min_y + d / e->image.height * y;
			ft_process_mlx(e);
		}
	}
	return (0);
}
