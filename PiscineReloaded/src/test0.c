/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/07 21:08:12 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PR.h>

void corr_test0(void)
{
	int fd;
	int i;
	t_tab data;
	char *line;

	static char	*test[] = {"drwx--xr-x",
						"-rwx--xr--",
						"dr-x---r--",
						"-r-----r--",
						"-rw-r----x",
						"-r-----r--",
						"lrwxr-xr-x"};

	static char	*test2[] = {"XX",
						"4",
						"XX",
						"1",
						"2",
						"1",
						"5"};

	static char	*test3[] = {"20:47",
						"21:46",
						"22:45",
						"23:44",
						"23:43",
						"23:44",
						"22:20"};

	system("tar -xvf reloaded/ex00/exo.tar -C tar_files");

	system("ls -l tar_files > 0.test");

	system("rm -Rf tar_files/*");

	fd = open("0.test", O_RDONLY);

	i = -1;
	while (get_next_line(fd, &line) == 1)
	{
		if (i >= 0)
		{
			data = ft_strsplit(line, ' ');
			if (ft_strcmp(data[0], test[i]))
			{
				ft_printf("TEST0 = {{red}KO{eoc}} -> test%d fail %s != %s\n", i, data[0], test[i]);
				return ;
			}
			if (i != 0 && i != 2)
			{
				if (ft_strcmp(data[4], test2[i]))
				{
					ft_printf("TEST0 = {{red}KO{eoc}} -> test%d fail %s != %s\n", i, data[4], test2[i]);
					return ;
				}
			}
			if (ft_strcmp(data[5], "Jun"))
			{
				ft_printf("TEST0 = {{red}KO{eoc}} -> test%d fail %s != Jun\n", i, data[5]);
				return ;
			}
			if (ft_strcmp(data[6], "1"))
			{
				ft_printf("TEST0 = {{red}KO{eoc}} -> test%d fail %s != 1\n", i, data[6]);
				return ;
			}
			if (ft_strcmp(data[7], test3[i]))
			{
				ft_printf("TEST0 = {{red}KO{eoc}} -> test%d fail %s != %s\n", i, data[7], test3[i]);
				return ;
			}
			if (i == 6)
			{
				if (!data[9] || ft_strcmp(data[9], "->") || ft_strcmp(data[10], "test0"))
				{
					ft_printf("TEST0 = {{red}KO{eoc}} -> test%d fail symbolic link != ->\n", i);
					return ;
				}
			}
		}
		i++;
		free(line);
	}

	ft_printf("TEST0 = {{green}OK{eoc}}\n");
	if (!KEEP_FILE)
		unlink("0.test");
	close(fd);
}