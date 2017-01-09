/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:34:19 by ljeanner          #+#    #+#             */
/*   Updated: 2017/01/06 15:35:20 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUF_SIZE 20
# define MAX_PATTERNS 19

 /*
 ** Section FT_CHECKER
 */

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetris
{
	char		id;
	t_point		hash_pos[4];
	t_point		offset;
}				t_tetris;

typedef struct	s_map
{
	int			size;
	char		**grid;
	
}				t_map;

 /*
 ** Section FT_CHECKER
 */

t_bool			ft_containsinvalidchars(char *str);
t_point			*ft_gethashlocations(char *pattern, t_point *hash_array);
char			*ft_getpattern(char *str);
t_bool			ft_checkpattern(char *pattern);
int				ft_getmostleft(char *str);

 /*
 ** Section FT_FILE_READER
 */

t_list			*ft_file_reader(char *filename);
t_list			*ft_cut_tetriminos(int fd);
t_bool			ft_check_tetriminos(t_list *tetriminos_list);

/*
 ** Section FT_MAP
 */

t_map			*ft_createmap(int size);
void			ft_freemap(t_map *map);
void			ft_printmap(t_map *map);
void			ft_resetmap(t_map *map);

 /*
 ** Section FT_TETRIS
 */

t_bool			ft_createtetris(char *str, char id, t_tetris *tt);
t_bool			ft_caninsert(t_map *map, t_tetris *tts);
t_bool			ft_place(t_map *map, t_tetris *tts);
void			ft_remove(t_map *map, t_tetris *tts);
int				ft_move(t_map *map, t_tetris *tts, t_point *dest);

 /*
 ** Section FT_SOLVER
 */

int				ft_solvemap(t_map *map, t_tetris *tts, int i);
t_map			*ft_solve(t_tetris *tts, int count);

 /*
 ** Section FT_UTILS
 */

int				ft_sqrt(int nb);
t_point			*ft_newpoint(int x, int y);
int				ft_printerror(char *str);
#endif
