/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:55:19 by thi-phng          #+#    #+#             */
/*   Updated: 2021/01/24 10:15:59 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (!*needle)
		return (char*)haystack;
	k = 0;
	while (haystack[k] && k < len)
	{
		i = 0;
		if (haystack[k] == needle[i])
		{
			while (k + i < len && haystack[k + i] == needle[i])
			{
				i++;
				if (!needle[i])
					return ((char *)&haystack[k]);
			}
		}
		k++;
	}
	return (NULL);
}
