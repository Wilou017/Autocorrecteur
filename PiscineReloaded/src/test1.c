/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/07 20:51:11 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PR.h>

void corr_test1(void)
{
	int fd;
	char *line;

	system("cat -e reloaded/ex01/z > 1.test");

	fd = open("1.test", O_RDONLY);

	while (get_next_line(fd, &line) == 1)
		free(line);

	if (ft_strcmp(line, "Z$"))
		ft_printf("TEST1 = {{red}KO{eoc}} -> Fichier z NON CONFORME\n");
	else
		ft_printf("TEST1 = {{green}OK{eoc}}\n");
	if (!KEEP_FILE)
		unlink("1.test");
	close(fd);
}