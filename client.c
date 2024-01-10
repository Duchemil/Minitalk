/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:24:10 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/10 16:54:38 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

int	main(int argc, char *argv[])
{
	int				pid;
	int				i;

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
			// Send string to server
			send_signal(pid, argv[2][i]);
			i++;
		}
	}

	return (0);
}
