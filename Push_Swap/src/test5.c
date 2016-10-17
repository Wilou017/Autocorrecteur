/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 22:21:33 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PS.h>

void corr_test5(void)
{
	int fd;
	char *line;
	char **tab;

	fd = open("4.test", O_RDONLY);
	get_next_line(fd, &line);

	tab = ft_strsplit(line, ' ');
	if (!ft_strcmp(tab[0], "Error"))
		ft_printf("TEST5 = {{red}KO{eoc}} -> %s\n", "Must not return \"Error\"");
	else
		ft_printf("TEST5 = {{green}OK{eoc}}\n");
	unlink("4.test");
	close(fd);
}