/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:21:33 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/15 14:38:07 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s || start > ft_strlen(s))
		return (NULL);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (i < start)
		i++;
	while (s[i] && k < len)
	{
		str[k] = s[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
