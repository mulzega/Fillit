/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:18:23 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/02 18:22:21 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstcount(t_list *lst)
{
	int		i;
	t_list *tmp;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
