/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:41:40 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/15 14:36:36 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p;

	p = (char *)str;
	p = p + ft_strlen(str);
	while ((p != str) && (*p != (char)c))
		p--;
	if (*p == (char)c)
		return ((char *)p);
	return (NULL);
}
