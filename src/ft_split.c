/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:56:42 by mneller           #+#    #+#             */
/*   Updated: 2025/01/21 19:17:25 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t count_token(char *str, char del)
{
    size_t i;
    size_t token;
    int inside_t;

    token = 0;
    i = 0;
    while (str[i])
    {
        inside_t = 0;
        while (str[i] && str[i] == del)
            i++;
        while (str[i] && str[i] != del)
        {
            if (!inside_t)
            {
                token++;
                inside_t = 1;
            }
            i++;
        }
    }
    return (token);
}

int	safe_malloc(char **tokens, int pos, size_t buffer)
{
	tokens[pos] = malloc(buffer);
	if (tokens[pos] == NULL)
	{
		while (pos > 0)
		{
			free(tokens[pos - 1]);
			pos--;
		}
		free(tokens);
		return (1);
	}
	return (0);
}

int fill_token(char **tokens, char *str, char del)
{
	size_t	len;
	int		i;

	i = 0;
	while (*str)
	{
		len = 0;
		while (*str && *str == del)
			str++;
		while (*str && *str != del)
		{
			len++;
			str++;
		}
		if (len)
		{
			if (safe_malloc(tokens, i, len + 1))
				return (1);
			ft_strlcpy(tokens[i], str - len, len + 1);
			i++;
		}
	}
	return (0);
}

char **ft_split(char *str, char del)
{
    char **tokens;
    size_t nb_token;

    nb_token = count_token(str, del);
    tokens = malloc((nb_token + 1) * sizeof(char *));
    if (!tokens)
        return (NULL);
    if (fill_token(tokens, str, del))
        return (NULL);
    return (tokens);
}