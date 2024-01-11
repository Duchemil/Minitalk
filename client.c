/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:24:10 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/11 16:22:47 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	static int	nb_bit;

	nb_bit = 0;
	while (nb_bit < 8)
	{
		if ((character & (0x01 << nb_bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		nb_bit++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		printf("Usage: ./client <server_pid> <string>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_signal(pid, argv[2][i]);
			i++;
		}
		send_signal(pid, '\0');
	}
	return (0);
}
