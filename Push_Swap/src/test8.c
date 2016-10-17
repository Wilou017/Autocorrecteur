/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 22:31:25 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PS.h>

void corr_test8(void)
{
	int fd;
	char *line;
	char **tab;

	fd = open("7.test", O_RDONLY);
	get_next_line(fd, &line);

	tab = ft_strsplit(line, ' ');
	if (ft_strcmp(tab[0], "Error") && ft_tablen(tab, 0) == 1)
		ft_printf("TEST8 = {{red}KO{eoc}} -> %s\n", "Must Return \"Error\"");
	else
		ft_printf("TEST8 = {{green}OK{eoc}}\n");
	unlink("7.test");
	close(fd);
}