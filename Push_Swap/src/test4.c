/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 22:19:23 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PS.h>

void corr_test4(void)
{
	int fd;
	char *line;
	char **tab;

	fd = open("3.test", O_RDONLY);
	get_next_line(fd, &line);

	tab = ft_strsplit(line, ' ');
	if (ft_strcmp(tab[0], "Error") && ft_tablen(tab, 0) == 1)
		ft_printf("TEST4 = {{red}KO{eoc}} -> %s\n", "Must Return \"Error\"");
	else
		ft_printf("TEST4 = {{green}OK{eoc}}\n");
	unlink("3.test");
	close(fd);
}