/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 22:30:38 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PS.h>

void corr_test6(void)
{
	int fd;
	char *line;
	char **tab;

	fd = open("5.test", O_RDONLY);
	get_next_line(fd, &line);

	tab = ft_strsplit(line, ' ');
	if (!ft_strcmp(tab[0], "Error"))
		ft_printf("TEST6 = {{red}KO{eoc}} -> %s\n", "Must not return \"Error\"");
	else
		ft_printf("TEST6 = {{green}OK{eoc}}\n");
	unlink("5.test");
	close(fd);
}