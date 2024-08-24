/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 03:04:19 by aeberius          #+#    #+#             */
/*   Updated: 2024/08/24 03:38:01 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signal)
{
	// Handle the received signal here
	printf("Received signal: %d\n", signal);
}

int main()
{
	ft_printf("Welcome to aeberius's server (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧\n");
	ft_printf("The server PID is: %d\n", getpid());

	// Register the signal handler
	signal(SIGINT, signal_handler);

	while (1)
	{
		// Your server logic here
	}

	return 0;
}
