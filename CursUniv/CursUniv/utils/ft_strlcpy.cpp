/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:32:07 by dcompreh          #+#    #+#             */
/*   Updated: 2023/05/29 23:28:03 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MyArrs.hpp"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	int				k;
	char			*str;

	str = (char *)src;
	i = 0;
	j = ft_strlen(str);
	k = (int)size;
	if (k)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}
