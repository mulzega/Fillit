/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:45:55 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/07 18:25:14 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool		ft_createtetris(char *str, char id, t_tetris *tt)
{
	t_point		*hash_locs;
	char		*pattern;
	int			i;

	hash_locs = (t_point *)ft_memalloc(sizeof(t_point) * 4);
	if (!(pattern = ft_getpattern(str)))
		return (FALSE);
	if (!(ft_checkpattern(pattern)))
		return (FALSE);
	if (!(hash_locs = ft_gethashlocations(pattern, hash_locs)))
		return (FALSE);
	tt->id = id;
	i = -1;
	while (++i < 4)
		tt->hash_pos[i] = hash_locs[i];
	tt->offset = *ft_newpoint(0, 0);
	ft_memdel((void **)&hash_locs);
	return (TRUE);
}

t_bool		ft_caninsert(t_map *map, t_tetris *tts)
{
	int		i;
	t_point	*pos;

	i = -1;
	pos = (t_point *)ft_memalloc(sizeof(t_point) * 4);
	while (++i < 4)
	{
		pos[i].y = (tts->hash_pos[i].y + tts->offset.y);
		pos[i].x = (tts->hash_pos[i].x + tts->offset.x);
		if (pos[i].y >= map->size || pos[i].y < 0
				|| pos[i].x >= map->size || pos[i].x < 0)
			return (FALSE);
		if (ft_isupper(map->grid[pos[i].y][pos[i].x]))
			return (FALSE);
	}
	ft_memdel((void **)&pos);
	return (TRUE);
}

t_bool		ft_place(t_map *map, t_tetris *tts)
{
	int		i;
	t_point	pos[4];

	i = -1;
	if (!map || !tts)
		return (FALSE);
	if (!ft_caninsert(map, tts))
		return (FALSE);
	while (++i < 4)
	{
		pos[i].y = (tts->hash_pos[i].y + tts->offset.y);
		pos[i].x = (tts->hash_pos[i].x + tts->offset.x);
		map->grid[pos[i].y][pos[i].x] = tts->id;
	}
	return (TRUE);
}

void		ft_remove(t_map *map, t_tetris *tts)
{
	int		i;
	t_point pos[4];

	i = -1;
	while (++i < 4)
	{
		pos[i].y = (tts->hash_pos[i].y + tts->offset.y);
		pos[i].x = (tts->hash_pos[i].x + tts->offset.x);
		if (pos[i].y < map->size && pos[i].y >= 0
				&& pos[i].x < map->size && pos[i].x >= 0
				&& map->grid[pos[i].y][pos[i].x] == tts->id)
			map->grid[pos[i].y][pos[i].x] = '.';
	}
}

int		ft_move(t_map *map, t_tetris *tts, t_point *dest)
{
	ft_remove(map, tts);
	tts->offset.x = (dest->x - tts->hash_pos[0].x);
	tts->offset.y = (dest->y - tts->hash_pos[0].y);
	if (ft_place(map, tts) == TRUE)
		return (1);
	return (0);
}
