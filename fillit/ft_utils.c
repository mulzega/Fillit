/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:12:04 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/07 18:25:32 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int nb)
{
	int		i;

	i = 2;
	if (nb == 1)
		return (1);
	while ((i * i) < nb && i <= 13)
		i++;
	return (i);
}

t_point		*ft_newpoint(int x, int y)
{
	t_point		*point;

	point = (t_point *)ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

int			ft_printerror(char *str)
{
	ft_putstr(str);
	return (1);
}
