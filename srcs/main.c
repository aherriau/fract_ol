/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:22:04 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 13:33:49 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_read_arg(t_env *e, char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		e->name = MANDEL;
	else if (ft_strcmp(name, "julia") == 0)
		e->name = JULIA;
	else if (ft_strcmp(name, "ship") == 0)
		e->name = SHIP;
	else if (ft_strcmp(name, "prey") == 0)
		e->name = PREY;
	else if (ft_strcmp(name, "mandelbrot5") == 0)
		e->name = MAND5;
	else if (ft_strcmp(name, "inverse") == 0)
		e->name = INV;
	else
		exit(ft_usage());
	if (ft_init_mlx(e, name, 1080, 1080) == 0)
		exit(ft_error("Error\n"));
	ft_process_mlx(e);
}

int		main(int argc, char **argv)
{
	t_env	e;
	t_env	e2;

	if (argc < 2 || argc > 3)
		return (ft_usage());
	if (ft_strcmp(argv[1], "help") == 0)
		return (ft_man());
	e.mlx = mlx_init();
	if (e.mlx == NULL)
		return (ft_error("Error\n"));
	ft_read_arg(&e, argv[1]);
	if (argc == 3)
	{
		e2.mlx = e.mlx;
		ft_read_arg(&e2, argv[2]);
	}
	mlx_loop(e.mlx);
	return (0);
}
