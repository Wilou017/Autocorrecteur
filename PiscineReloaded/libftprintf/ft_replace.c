/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:14:10 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/09 16:02:13 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_select_len_res(char *search, char *rby, char *str)
{
	size_t	len_str;
	size_t	len_search;
	size_t	len_rby;

	len_str = ft_strlen(str);
	len_search = ft_strlen(search);
	len_rby = ft_strlen(rby);
	return (len_str + (len_rby - len_search));
}

char			*ft_replace(char *search, char *rby, char *str, int ifre)
{
	char	*result;
	char	*ftstrstr;
	int		i;
	size_t	j;

	result = str;
	while (str != NULL && ft_strstr(str, search))
	{
		result = ft_strnew(ft_select_len_res(search, rby, str));
		ftstrstr = ft_strstr(str, search);
		i = -1;
		while (ft_strcmp(&str[++i], ftstrstr) != 0)
			result[i] = str[i];
		ft_strcat(result, rby);
		j = i + ft_strlen(rby);
		i += ft_strlen(search);
		while (str[i] != '\0')
			result[j++] = str[i++];
		(ifre == 2 || ifre == 4 || ifre == 5) ? free(search) : 0;
		(ifre == 3 || ifre == 5 || ifre == 6) ? free(rby) : 0;
		(ifre == 1 || ifre == 4 || ifre == 6) ? free(str) : 0;
		str = result;
	}
	return (result);
}
