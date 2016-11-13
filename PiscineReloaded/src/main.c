/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 20:09:39 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/13 22:03:28 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PR.h>

void fork_exec(const char *bin)
{
	static int index = 0;

	int p = fork();
	if (!p)
	{
		char *str = ft_strjoin(ft_itoa(index, 10), ".test", 1);
		// char **tab = ft_strsplit(test[index], ' ');
		freopen(str, "w", stdout);
		// execve(bin, tab, NULL);
		exit (0);
	}
	else
	{
		int sl;
		wait(&sl);
		index++;
	}
}

void corr_test(int test)
{
	switch (test)
	{
		case 0:
			corr_test0();
			break;
		case 1:
			corr_test1();
			break;
		case 2:
			corr_test2();
			break;
		default:
			break;
	}
}

int main(int argc, char const *argv[])
{
	int NB_TEST = 3;

	ft_putmessage("Correcteur Piscine Reloaded");

	for (int i = 0; i < NB_TEST; i++)
		corr_test(i);
	if (!KEEP_FILE)
		system("rm -Rf *.test");
	return (0);
}
