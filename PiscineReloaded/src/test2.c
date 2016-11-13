/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:00:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/13 22:47:19 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PR.h>

void corr_test2(void)
{
	int fd;
	int i;
	t_tab data;
	char *line;

	static char	*test[] = {"#test02",
							"Soudos",
							"sousdossier2",
							"",
							"test_ex02/Soudos:",
							"#dfghdfg",
							"#dfghsdf",
							"#dfghsdfg",
							"adfsgaf#",
							"ahah",
							"~adfsgaf",
							"",
							"test_ex02/Soudos/ahah:",
							"#dsfg",
							"dfgsdf",
							"dsfg#",
							"~dsfg",
							"",
							"test_ex02/sousdossier2:",
							"#lol",
							"lol",
							NULL
						};

	static char	*test2[] = {
		"./test_ex02/Soudos/#dfghsdf#",
		"./test_ex02/Soudos/#dfghsdfg#",
		"./test_ex02/Soudos/ahah/#dsfg#",
		"./test_ex02/Soudos/ahah/#dsfg~",
		"./test_ex02/Soudos/ahah/dsfg~",
		"./test_ex02/sousdossier2/#lol#",
		"./test_ex02/sousdossier2/lol~",
		"./test_ex02/test01 ahah~",
		NULL
	};

	system("cp -R src/test_ex02 .");
	// system("ls -R test_ex02 > 2.test");
	system("cp -R src/test_ex02 /tmp");
	system("rm -Rf src/test_ex02");

	i = 0;
	fd = open("reloaded/ex02/clean", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (i > 0)
		{
			ft_printf("TEST2 = {{red}KO{eoc}} -> Multiple line\n");
			return ;
		}
		else
			system(ft_strjoin(line, " > 2_2.test", 1));
		i++;
	}

	system("ls -R test_ex02 > 2.test");
	system("rm -Rf test_ex02");
	system("cp -R /tmp/test_ex02 src/");

	close(fd);
	fd = open("2.test", O_RDONLY);

	i = 0;
	while(get_next_line(fd, &line) == 1)
	{
		if (test[i] == NULL)
		{
			ft_printf("TEST2 = {{red}KO{eoc}} -> FAIL {1}\n");
			return ;
		}
		if (ft_strcmp(line, test[i]))
		{
			ft_printf("TEST2 = {{red}KO{eoc}} -> FAIL '%s' != '%s'\n", line, test[i]);
			return ;
		}
		i++;
	}
	if (i != ft_tablen(test, 0))
	{
		ft_printf("TEST2 = {{red}KO{eoc}} -> FAIL {2}\n");
		return ;
	}

	close(fd);
	fd = open("2_2.test", O_RDONLY);
	i = 0;
	while(get_next_line(fd, &line) == 1)
	{
		if (test2[i] == NULL)
		{
			ft_printf("TEST2 = {{red}KO{eoc}} -> FAIL {3}\n");
			return ;
		}
		if (ft_strcmp(line, test2[i]))
		{
			ft_printf("TEST2 = {{red}KO{eoc}} -> FAIL '%s' != '%s'\n", line, test2[i]);
			return ;
		}
		i++;
	}

	if (i != ft_tablen(test2, 0))
	{
		ft_printf("TEST2 = {{red}KO{eoc}} -> FAIL {4}\n");
		return ;
	}

	ft_printf("TEST2 = {{green}OK{eoc}}\n");

	close(fd);
}