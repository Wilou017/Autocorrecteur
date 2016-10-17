/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 22:31:32 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PS.h>

void corr_test2(void)
{
	int fd;
	char *line;
	char **tab;

	fd = open("1.test", O_RDONLY);
	get_next_line(fd, &line);

	tab = ft_strsplit(line, ' ');
	int nbcmd = ft_tablen(tab, 0);
	if (nbcmd > 8)
		ft_printf("TEST2 = {{red}KO{eoc}} -> Too many commands, must be less than 8 .. You do {red}%d{eoc} commands\n", nbcmd);
	else
		ft_printf("TEST2 = {{green}OK{eoc}}\n");
	unlink("1.test");
	close(fd);
}