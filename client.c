/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:45:51 by ezeper            #+#    #+#             */
/*   Updated: 2024/07/29 14:49:22 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *message)
{
	int		i;
	char	c;

	while (*message)
	{
		c = *message++;
		i = 0;
		while (i < 8)
		{
			if (c & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
