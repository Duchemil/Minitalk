/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:56:46 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/14 14:40:15 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char				*output = NULL;
	static unsigned char	c = 0;
	static int				i = 0;

	(void)context;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			ft_printf("%s\n", output);
			free(output);
			output = NULL;
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		output = ft_strjoin(output, c);
		kill(info->si_pid, SIGUSR1);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", getpid());
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	signal.sa_sigaction = handle_signal;
	signal.sa_flags = SA_SIGINFO;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, 0);
	sigaction(SIGUSR2, &signal, 0);
	while (1)
		pause();
	return (0);
}
