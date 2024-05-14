/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:24:10 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/14 14:40:18 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_string;

void	verif_signal(int sig, siginfo_t *info, void *context)
{
	static int	nbchar = 0;

	if (sig == SIGUSR1)
		nbchar++;
	else
	{
		if (nbchar != ft_strlen(g_string))
		{
			ft_printf("Error\n Chars sent and received differ");
			exit(1);
		}
		else
		{
			ft_printf("Message well received\n");
			exit(0);
		}
	}
	(void)info;
	(void)context;
}

void	send_signal(int pid, char *str)
{
	int		j;
	char	c;
	int		i;

	i = -1;
	while (str[++i])
	{
		j = 7;
		c = str[i];
		while (j >= 0)
		{
			if (c >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(100);
		}
	}
	j = 7;
	while (j-- >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	signal;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
	{
		ft_printf("Usage: ./client <server_pid> <string>\n");
		return (0);
	}
	pid = atoi(argv[1]);
	g_string = argv[2];
	signal.sa_sigaction = verif_signal;
	signal.sa_flags = SA_SIGINFO;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, 0);
	sigaction(SIGUSR2, &signal, 0);
	send_signal(pid, argv[2]);
	return (0);
}
