/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:56:46 by lduchemi          #+#    #+#             */
/*   Updated: 2024/04/11 14:55:20 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static char			*output = NULL;
	static int			current_char = 0;
	static int			bit_index = 0;

	if (signal == SIGUSR1)
		current_char |= (0x01 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		output = ft_strjoin(output, current_char);
		if (current_char == 0)
		{
			ft_printf("%s\n", output);
			free(output);
			output = NULL;
		}
		bit_index = 0;
		current_char = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	(void)argv;
	server_pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", server_pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	while (argc == 1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
