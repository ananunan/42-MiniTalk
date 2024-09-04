/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 02:54:13 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/04 14:27:00 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(pid_t pid, char *message)
{
	int	i;
	int	bit;

	i = 0;
	while (message[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if (message[i] % 2 == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(250);
			message[i] = message[i] / 2;
			bit++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		ft_printf ("Error! Invalid Number of Arguments\n");
	else
	{
		pid = ft_atoi(argv[1]);
		send_signals(pid, argv[2]);
	}
}
