/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:56:46 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/05 17:40:25 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	current_char;
	static int				bit_index;

	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int	main(void)
{
	pid_t	server_pid;

	// Register signal handler
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	// Print server PID
	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	// Infinite loop to wait for signals
	while (1)
	{
		sleep(1); // You may implement a more efficient way to wait for signals
	}
	return (0);
}
