/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 22:30:03 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PS.h>

void corr_test7(void)
{
	int fd;
	char *line;
	char **tab;

	fd = open("6.test", O_RDONLY);
	get_next_line(fd, &line);

	tab = ft_strsplit(line, ' ');
	if (ft_strcmp(tab[0], "Error") && ft_tablen(tab, 0) == 1)
		ft_printf("TEST7 = {{red}KO{eoc}} -> %s\n", "Must Return \"Error\"");
	else
		ft_printf("TEST7 = {{green}OK{eoc}}\n");
	unlink("6.test");
	close(fd);
}