/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 22:18:03 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PS.h>

void corr_test1(void)
{
	int fd;
	char *line;
	char **tab;

	fd = open("0.test", O_RDONLY);
	get_next_line(fd, &line);

	tab = ft_strsplit(line, ' ');
	if (ft_strcmp(tab[0], "sa") && ft_tablen(tab, 0) == 1)
		ft_printf("TEST1 = {{red}KO{eoc}} -> %s\n", line);
	else
		ft_printf("TEST1 = {{green}OK{eoc}}\n");
	unlink("0.test");
	close(fd);
}