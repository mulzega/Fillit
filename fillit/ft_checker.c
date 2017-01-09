/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:24:13 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/07 18:24:38 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const char		*g_patterns[MAX_PATTERNS] = {
	"###...#.........",
	".#...#..##......",
	"#...###.........",
	"##..#...#.......",
	"###.#...........",
	"##...#...#......",
	"..#.###.........",
	"#...#...##......",
	"###..#..........",
	".#..##...#......",
	".#..###.........",
	"#...##..#.......",
	".##.##..........",
	"#...##...#......",
	"##...##.........",
	".#..##..#.......",
	"####............",
	"#...#...#...#...",
	"##..##.........."
};

t_bool		ft_containsinvalidchars(char *str)
{
	char		*tmp;
	size_t		p_count;
	size_t		h_count;
	size_t		endl_count;

	tmp = str;
	p_count = 0;
	h_count = 0;
	endl_count = 0;
	while (*tmp)
	{
		if (*tmp == '.')
			p_count++;
		else if (*tmp == '#')
			h_count++;
		else if (*tmp == '\n')
			endl_count++;
		else
			return (TRUE);
		tmp++;
	}
	if (p_count != 12 || h_count != 4 || endl_count != 4)
		return (TRUE);
	return (FALSE);
}

t_point		*ft_gethashlocations(char *pattern, t_point *hash_array)
{
	int			i;
	int			j;
	int			x;
	int			y;

	i = 0;
	j = -1;
	x = 0;
	y = 0;
	while (pattern[++j])
	{
		if (pattern[j] == '#')
		{
			hash_array[i].x = x;
			hash_array[i].y = y;
			i++;
		}
		x++;
		if (j == 3 || j == 7 || j == 11)
		{
			x = 0;
			y++;
		}
	}
	return (hash_array);
}

char		*ft_getpattern(char *str)
{
	int			ijh[3];
	char		*pattern;

	ijh[0] = 0;
	ijh[1] = 0;
	ijh[2] = 0;
	pattern = ft_strnew(16);
	while (str[ijh[0]] != '#')
		ijh[0]++;
	ijh[0] -= ft_getmostleft(str);
	while (str[ijh[0] - 1] != '\n' && str[ijh[0] - 1])
		ijh[0]--;
	ijh[0] += ft_getmostleft(str) - 1;
	while (str[++ijh[0]] && ijh[2] < 4)
	{
		if (str[ijh[0]] != '\n')
		{
			pattern[ijh[1]++] = str[ijh[0]];
			if (str[ijh[0]] == '#')
				ijh[2]++;
		}
	}
	while (ijh[1] < 16)
		pattern[ijh[1]++] = '.';
	return (pattern);
}

int			ft_getmostleft(char *str)
{
	t_point		*hash_pos;
	int			i;
	int			j;
	int			x_min;
	char		*tmp;

	i = -1;
	j = 0;
	x_min = 4;
	tmp = ft_strnew(16);
	while (str[++i])
		if (str[i] != '\n')
			tmp[j++] = str[i];
	hash_pos = (t_point *)ft_memalloc(sizeof(t_point) * 4);
	hash_pos = ft_gethashlocations(tmp, hash_pos);
	i = -1;
	while(++i < 4)
		if (hash_pos[i].x < x_min)
			x_min = hash_pos[i].x;
	ft_memdel((void **)&hash_pos);
	return (x_min);
}


t_bool		ft_checkpattern(char *pattern)
{
	int			i;

	i = 0;
	while (i < MAX_PATTERNS)
	{
		if (ft_strequ(pattern, g_patterns[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
