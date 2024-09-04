/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 03:04:19 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/04 14:24:52 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_signals(int signal)
{
	static unsigned int		i = 0;
	static unsigned int		array[8];
	unsigned char	value;
	int				final_value;

	value = 0;
	final_value = 7;
	if (i < 8)
	{
		if (signal == SIGUSR1)
			array[i] = 0;
		else if (signal == SIGUSR2)
			array[i] = 1;
	}
	i++;
	if (i == 8)
	{
		while (final_value >= 0)
			value = value * 2 + array[final_value--];
		ft_printf("%c", value);
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	ft_printf("Welcome to aeberius's server (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧\n");
	ft_printf("The server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, receive_signals);
		signal(SIGUSR2, receive_signals);
		pause();
	}
	return (0);
}
