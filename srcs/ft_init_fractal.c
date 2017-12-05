/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:19:59 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 13:33:30 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_julia(t_fractal *fractal)
{
	fractal->origin_min_x[0] = -2.0;
	fractal->origin_max_x[0] = 2.0;
	fractal->origin_min_y[0] = -2.0;
	fractal->origin_max_y[0] = 2.0;
	fractal->origin_min_x[1] = 0.48171296296296328698;
	fractal->origin_max_x[1] = 0.54421296296296328698;
	fractal->origin_min_y[1] = -0.09247685185185171297;
	fractal->origin_max_y[1] = -0.02997685185185171297;
	fractal->origin_min_x[2] = -0.28995225694444415332;
	fractal->origin_max_x[2] = -0.16495225694444407005;
	fractal->origin_min_y[2] = -0.28985821759259267072;
	fractal->origin_max_y[2] = -0.16485821759259261521;
	fractal->origin_min_x[3] = -0.06244624460840186853;
	fractal->origin_max_x[3] = 0.06255375539159813147;
	fractal->origin_min_y[3] = -0.06269984393261732181;
	fractal->origin_max_y[3] = 0.06230015606738267819;
	fractal->min_x = fractal->origin_min_x[0];
	fractal->max_x = fractal->origin_max_x[0];
	fractal->min_y = fractal->origin_min_y[0];
	fractal->max_y = fractal->origin_max_y[0];
	fractal->origin_c_x = -0.772691322542185;
	fractal->origin_c_y = 0.124281466072787;
	fractal->c_x = fractal->origin_c_x;
	fractal->c_y = fractal->origin_c_y;
}

void	ft_ship(t_fractal *fractal)
{
	fractal->origin_min_x[0] = -2.0;
	fractal->origin_max_x[0] = 1.5;
	fractal->origin_min_y[0] = -2.5;
	fractal->origin_max_y[0] = 1.0;
	fractal->origin_min_x[1] = -1.80248178996403463081;
	fractal->origin_max_x[1] = -1.71208922798056373260;
	fractal->origin_min_y[1] = -0.08004548324150614902;
	fractal->origin_max_y[1] = 0.01034707874196474919;
	fractal->origin_min_x[2] = 0.56351968270761054747;
	fractal->origin_max_x[2] = 0.78226968270761054747;
	fractal->origin_min_y[2] = -1.27704890215838351430;
	fractal->origin_max_y[2] = -1.05829890215838351430;
	fractal->origin_min_x[3] = 0.97002603263678599532;
	fractal->origin_max_x[3] = 0.97002603304423962172;
	fractal->origin_min_y[3] = -1.68254449277311990407;
	fractal->origin_max_y[3] = -1.68254449236566627768;
	fractal->min_x = fractal->origin_min_x[0];
	fractal->max_x = fractal->origin_max_x[0];
	fractal->min_y = fractal->origin_min_y[0];
	fractal->max_y = fractal->origin_max_y[0];
	fractal->origin_c_x = 0;
	fractal->origin_c_y = 0;
	fractal->c_x = fractal->origin_c_x;
	fractal->c_y = fractal->origin_c_y;
}

void	ft_prey(t_fractal *fractal)
{
	fractal->origin_min_x[0] = -1.5;
	fractal->origin_max_x[0] = 1.5;
	fractal->origin_min_y[0] = -1.5;
	fractal->origin_max_y[0] = 1.5;
	fractal->origin_min_x[1] = -0.47208727904040598267;
	fractal->origin_max_x[1] = -0.46564196654040596046;
	fractal->origin_min_y[1] = -0.62818916706123939520;
	fractal->origin_max_y[1] = -0.62174385456123926197;
	fractal->origin_min_x[2] = 0.99194878472222292043;
	fractal->origin_max_x[2] = 0.99341362847222292043;
	fractal->origin_min_y[2] = -0.99341091579861118266;
	fractal->origin_max_y[2] = -0.99194607204861118266;
	fractal->origin_min_x[3] = -1.19193238152397684715;
	fractal->origin_max_x[3] = -1.14505738152397684715;
	fractal->origin_min_y[3] = -0.13872727288140157542;
	fractal->origin_max_y[3] = -0.09185227288140156154;
	fractal->min_x = fractal->origin_min_x[0];
	fractal->max_x = fractal->origin_max_x[0];
	fractal->min_y = fractal->origin_min_y[0];
	fractal->max_y = fractal->origin_max_y[0];
	fractal->origin_c_x = 0;
	fractal->origin_c_y = 0;
	fractal->c_x = fractal->origin_c_x;
	fractal->c_y = fractal->origin_c_y;
}

void	ft_mand5(t_fractal *fractal)
{
	fractal->origin_min_x[0] = -1;
	fractal->origin_max_x[0] = 1;
	fractal->origin_min_y[0] = -1;
	fractal->origin_max_y[0] = 1;
	fractal->origin_min_x[1] = 0.50248921712239613679;
	fractal->origin_max_x[1] = 0.50255025227864613679;
	fractal->origin_min_y[1] = -0.62406036942093467967;
	fractal->origin_max_y[1] = -0.62399933426468467967;
	fractal->origin_min_x[2] = 0.50578269958496124836;
	fractal->origin_max_x[2] = 0.50584373474121124836;
	fractal->origin_min_y[2] = -0.62665037402400280975;
	fractal->origin_max_y[2] = -0.62658933886775280975;
	fractal->origin_min_x[3] = -0.77417910540545398224;
	fractal->origin_max_x[3] = -0.77416384661639148224;
	fractal->origin_min_y[3] = -0.88126797146267332739;
	fractal->origin_max_y[3] = -0.88125271267361082739;
	fractal->min_x = fractal->origin_min_x[0];
	fractal->max_x = fractal->origin_max_x[0];
	fractal->min_y = fractal->origin_min_y[0];
	fractal->max_y = fractal->origin_max_y[0];
	fractal->origin_c_x = 0;
	fractal->origin_c_y = 0;
	fractal->c_x = fractal->origin_c_x;
	fractal->c_y = fractal->origin_c_y;
}

void	ft_inv(t_fractal *fractal)
{
	fractal->origin_min_x[0] = -2;
	fractal->origin_max_x[0] = 2;
	fractal->origin_min_y[0] = -2;
	fractal->origin_max_y[0] = 2;
	fractal->origin_min_x[1] = 0.07692418981481508045;
	fractal->origin_max_x[1] = 1.07692418981481496942;
	fractal->origin_min_y[1] = -1.16341145833333348136;
	fractal->origin_max_y[1] = -0.16341145833333348136;
	fractal->origin_min_x[2] = 0.65403645833333334814;
	fractal->origin_max_x[2] = 0.68528645833333334814;
	fractal->origin_min_y[2] = -0.63462094907407384792;
	fractal->origin_max_y[2] = -0.60337094907407384792;
	fractal->origin_min_x[3] = -1.67545428349165637094;
	fractal->origin_max_x[3] = -1.67545426859049517709;
	fractal->origin_min_y[3] = 1.09146360552714605241;
	fractal->origin_max_y[3] = 1.09146362042830724626;
	fractal->min_x = fractal->origin_min_x[0];
	fractal->max_x = fractal->origin_max_x[0];
	fractal->min_y = fractal->origin_min_y[0];
	fractal->max_y = fractal->origin_max_y[0];
	fractal->origin_c_x = -0.772691322542185;
	fractal->origin_c_y = 0.124281466072787;
	fractal->c_x = fractal->origin_c_x;
	fractal->c_y = fractal->origin_c_y;
}
