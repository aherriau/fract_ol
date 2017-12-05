/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:13:52 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/04 23:19:12 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		ft_error(char *msg)
{
	ft_putstr(msg);
	return (1);
}

int		ft_usage(void)
{
	ft_putstr("usage ./fractol fractal_name [fractal_name2]\n");
	ft_putstr("fractals: mandelbrot julia ship prey mandelbrot5 inverse\n");
	ft_putstr("More information at: ./fractol help\n");
	return (1);
}

void	ft_man_2(void)
{
	ft_putstr("\t- +\t\tzoom - dezoom centered\n");
	ft_putstr("\t1 2 3\t\tinteresting spots\n\n");
	ft_putstr("AUTHOR\n\taherriau\n\n");
	ft_putstr("December 5, 2017\n\n");
}

int		ft_man(void)
{
	ft_putstr("\nman\n\n\n");
	ft_putstr("NAME\n\t./fractol - graphically display nice fractals\n\n");
	ft_putstr("SYNOPSIS\n\t./fractol fractal_name [fractal_name2]\n\n");
	ft_putstr("FRACTALS\n\tmandelbrot\tmandelbrot set\n");
	ft_putstr("\tjulia\t\tjulia set\n");
	ft_putstr("\tship\t\tburning ship fractal\n");
	ft_putstr("\tprey\t\tbird of prey fractal\n");
	ft_putstr("\tmandelbrot5\tmandelbrot set with z5\n");
	ft_putstr("\tinverse\t\tpersonnal inverse mandelbrot\n\n");
	ft_putstr("MOUSE OPTIONS\n\tleft click\tzoom\n");
	ft_putstr("\tright click\tdezoom\n");
	ft_putstr("\twheel\t\tzoom - dezoom\n\n");
	ft_putstr("KEYBOARD OPTIONS\n\tesc\t\texit\n");
	ft_putstr("\t0\t\treset\n");
	ft_putstr("\t1 2 3\t\tcolors\n");
	ft_putstr("\ti\t\tinformations\n");
	ft_putstr("\tq\t\tlock - unlock movement\n");
	ft_putstr("\tup down\t\tspeed - + 1\n");
	ft_putstr("\tleft right\titerations - + 1\n");
	ft_putstr("\t- +\t\titerations - + 50\n");
	ft_putstr("\tspace\t\tzoom with mouse\n");
	ft_putstr("\tb\t\tdezoom with mouse\n");
	ft_putstr("\t4 5 6 8\t\tmove\n");
	ft_man_2();
	return (1);
}
