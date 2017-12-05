/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:38:29 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 12:48:56 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_iter_info(t_env *e)
{
	void	*img;
	char	*iter;
	char	*info;

	img = mlx_new_image(e->mlx, 170, 30);
	if (img == NULL)
		exit(ft_error("Error\n"));
	mlx_put_image_to_window(e->mlx, e->win, img, 455, 17);
	mlx_destroy_image(e->mlx, img);
	iter = ft_itoa(e->fractal.max_iter);
	info = ft_strjoin("Iterations: ", iter);
	mlx_string_put(e->mlx, e->win, 462, 20, 0x00F3F312, info);
	ft_strdel(&iter);
	ft_strdel(&info);
}

void	ft_speed_info(t_env *e)
{
	void	*img;
	char	*speed;
	char	*info;
	char	*info2;

	img = mlx_new_image(e->mlx, 170, 30);
	if (img == NULL)
		exit(ft_error("Error\n"));
	mlx_put_image_to_window(e->mlx, e->win, img, 455, 17);
	mlx_destroy_image(e->mlx, img);
	speed = ft_itoa(e->fractal.speed * 250);
	info = ft_strjoin("Speed: ", speed);
	info2 = ft_strjoin(info, "%");
	mlx_string_put(e->mlx, e->win, 492, 20, 0x00F3F312, info2);
	ft_strdel(&speed);
	ft_strdel(&info);
	ft_strdel(&info2);
}

void	ft_iter_speed_info(t_env *e)
{
	void	*img;
	char	*iter_speed;
	char	*info;
	char	*info2;
	char	*info3;

	img = mlx_new_image(e->mlx, 170, 50);
	if (img == NULL)
		exit(ft_error("Error\n"));
	mlx_put_image_to_window(e->mlx, e->win, img, 17, 17);
	mlx_destroy_image(e->mlx, img);
	iter_speed = ft_itoa(e->fractal.max_iter);
	info = ft_strjoin("Iterations: ", iter_speed);
	ft_strdel(&iter_speed);
	iter_speed = ft_itoa(e->fractal.speed * 250);
	info2 = ft_strjoin("Speed: ", iter_speed);
	ft_strdel(&iter_speed);
	info3 = ft_strjoin(info2, "%");
	mlx_string_put(e->mlx, e->win, 20, 20, 0x00F3F312, info);
	mlx_string_put(e->mlx, e->win, 20, 40, 0x00F3F312, info3);
	ft_strdel(&info);
	ft_strdel(&info2);
	ft_strdel(&info3);
}

void	ft_spot(t_env *e, int spot)
{
	e->fractal.info = 0;
	e->fractal.max_iter = e->fractal.origin_max_iter;
	e->fractal.move = 0;
	e->fractal.x = 0;
	e->fractal.y = 0;
	e->fractal.speed = 0.1;
	e->fractal.c_x = e->fractal.origin_c_x;
	e->fractal.c_y = e->fractal.origin_c_y;
	e->fractal.min_x = e->fractal.origin_min_x[spot];
	e->fractal.max_x = e->fractal.origin_max_x[spot];
	e->fractal.min_y = e->fractal.origin_min_y[spot];
	e->fractal.max_y = e->fractal.origin_max_y[spot];
	ft_process_mlx(e);
}

int		ft_keypress_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	ft_keypress_tool(keycode, e);
	ft_keypress_tool_2(keycode, e);
	ft_keypress_tool_3(keycode, e);
	ft_keypress_tool_4(keycode, e);
	ft_keypress_tool_5(keycode, e);
	ft_keypress_tool_6(keycode, e);
	ft_keypress_tool_7(keycode, e);
	ft_keypress_tool_8(keycode, e);
	ft_keypress_tool_9(keycode, e);
	return (0);
}
