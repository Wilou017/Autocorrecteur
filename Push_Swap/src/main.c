/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 20:09:39 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 22:31:54 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Corr_PS.h>
#include <sys/wait.h>

void fork_exec(const char *bin)
{
	static int index = 0;

	static char	*test[] = {"1 2 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19",
						"2 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 19 18",
						"1 2 5r 3",
						"1 2 r 5",
						"1 2 2147483647 5",
						"1 2 -2147483648 5",
						"1 2 2147483648 5",
						"1 2 -2147483649 5"};


	int p = fork();
	if (!p)
	{
		char *str = ft_strjoin(ft_itoa(index, 10), ".test", 1);
		char **tab = ft_strsplit(test[index], ' ');
		freopen(str, "w", stdout);
		execve(bin, tab, NULL);
		exit (0);
	}
	else
	{
		int sl;
		wait(&sl);
		index++;
	}
}

int main(int argc, char const *argv[])
{
		ft_putmessage("Correcteur PushSwap");

		fork_exec(argv[1]);
		fork_exec(argv[1]);
		fork_exec(argv[1]);
		fork_exec(argv[1]);
		fork_exec(argv[1]);
		fork_exec(argv[1]);
		fork_exec(argv[1]);
		fork_exec(argv[1]);
		corr_test1();
		corr_test2();
		corr_test3();
		corr_test4();
		corr_test5();
		corr_test6();
		corr_test7();
		corr_test8();
		return (0);
}
