/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:04:12 by aherriau          #+#    #+#             */
/*   Updated: 2017/11/08 21:59:52 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		index;

	if (s != NULL)
	{
		index = 0;
		while (s[index] != '\0')
		{
			ft_putchar(s[index]);
			index++;
		}
	}
}