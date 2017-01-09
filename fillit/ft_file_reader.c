/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:43:53 by ljeanner          #+#    #+#             */
/*   Updated: 2017/01/09 16:12:50 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*ft_file_reader(char *filename)
{
	int		fd;
	t_list	*entry;

	entry = NULL;
	fd = open(filename, O_RDONLY);
	entry = ft_cut_tetriminos(fd);
	if (close(fd) == -1)
		return (NULL);
	if (ft_check_tetriminos(entry) == FALSE)
		return (NULL);
	return (entry);
}

t_list		*ft_cut_tetriminos(int fd)
{
	char	buffer[BUF_SIZE + 1];
	char	c;
	int		reader;
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	tmp = NULL;
	c = 0;
	if ((reader = read(fd, buffer, BUF_SIZE)) < 0)
		return (NULL);
	while (reader > 0)
	{
		buffer[reader] = '\0';
		tmp = ft_lstpushend(tmp, buffer, reader + 1);
		if (!head)
			head = tmp;
		reader = read(fd, &c, 1);
		if (c != '\n' && c)
			return (NULL);
		reader = read(fd, buffer, BUF_SIZE);
	}
	return (head);
}

t_bool		ft_check_tetriminos(t_list *tetriminos_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = tetriminos_list;
	while (tmp != NULL)
	{
		if (ft_containsinvalidchars(tmp->content) == TRUE)
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}
