/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:49:17 by mneller           #+#    #+#             */
/*   Updated: 2025/01/30 13:44:26 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_atoi(char *str)
{
    long num = 0;
    int sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' 
        || *str == '\v' || *str == '\f')
    {
        str++;
    }
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        if (*str == '+') 
            sign = +1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return (num * sign);
}

int ft_isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

size_t ft_strlen(char *str)
{
    size_t i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}