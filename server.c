/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:56:46 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/10 17:06:29 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *output = NULL;

void	handle_signal(int signal)
{
	static unsigned char	current_char;
	static int				bit_index;

	if (signal == 2)
	{
		printf("\n\033[90mReceived SIGINT. Exiting...\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	if (signal == SIGUSR1)
		current_char |= (0x01 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
			ft_strjoin(output ,"\n");
		else
			ft_strjoin(output , current_char);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	// Register signal handler
	(void)argv;
	// Print server PID
	server_pid = getpid();
	printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", server_pid);
	printf("\033[90mWaiting for a message...\033[0m\n");
	// Infinite loop to wait for signals
	while (argc == 1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		signal(SIGINT, handle_signal);
		pause(); // You may implement a more efficient way to wait for signals
	}
	return (0);
}
