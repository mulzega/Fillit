/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:11:28 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/07 18:25:09 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_solvemap(t_map *map, t_tetris *tts, int i)
{
	int			x;
	int			y;
	t_point		*pos;
	t_tetris	*tt;

	y = 0;
	tt = &tts[i];
	if (!(ft_isupper(tt->id)))
		return (1);
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			pos = ft_newpoint(x, y);
			if (ft_move(map, &tts[i], pos) == TRUE)
			{
				if (ft_solvemap(map, tts, i+1))
					return (1);
				ft_remove(map, &tts[i]);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map		*ft_solve(t_tetris *tts, int count)
{
	t_map	*map;
	int		size;

	size = ft_sqrt(count * 4);
	map = ft_createmap(size);
	while (!ft_solvemap(map, tts, 0))
	{
		size++;
		ft_freemap(map);
		map = ft_createmap(size);
	}
	return (map);
}
