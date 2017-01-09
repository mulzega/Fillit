/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:27:11 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/07 18:25:00 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*ft_createmap(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = -1;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->grid = (char **)ft_memalloc(sizeof(char *) * size);
	while (++i < size)
	{
		j = -1;
		map->grid[i] = ft_strnew(size);
		while (++j < size)
			map->grid[i][j] = '.';
	}
	return (map);
}

void		ft_freemap(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->size)
		ft_memdel((void **)&(map->grid[i]));
	ft_memdel((void **)&(map->grid));
	ft_memdel((void **)&map);
}

void		ft_printmap(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->size)
	{
		ft_putstr(map->grid[i]);
		ft_putchar('\n');
	}
}

void		ft_resetmap(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->size)
	{
		j = -1;
		while (++j < map->size)
			map->grid[i][j] = '.';
	}
}
