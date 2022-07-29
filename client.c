/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:37:20 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/15 19:26:37 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	handler_client(int signal)
{
	(void) signal;
	ft_putstr_len("came signal\n");
}

static void	ft_byte_sent(int pid, unsigned int c, int i)
{
	int	check;

	if (!(c / 2))
	{
		while (i-- > 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(ft_putstr_len("Error in client\n"));
			usleep (1000);
		}
		if (kill(pid, SIGUSR2) == -1)
			exit(ft_putstr_len("Error in client\n"));
		usleep (1000);
		return ;
	}
	if (i-- > 0)
		ft_byte_sent(pid, c / 2, i);
	if (c % 2)
		check = kill(pid, SIGUSR2);
	else
		check = kill(pid, SIGUSR1);
	if (check == -1)
		exit(ft_putstr_len("Error in client\n"));
	usleep (1000);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (ft_putstr_len("Need 3 arguments!\n"));
	signal(SIGUSR1, handler_client);
	i = 0;
	while (*(argv[2]) != '\0')
	{
		ft_byte_sent(ft_atoi(argv[1]), argv[2][i], 8);
		(argv[2])++;
	}
	i = 0;
	while (i++ <= 8)
	{
		if (kill(ft_atoi(argv[1]), SIGUSR1) == -1)
			exit(ft_putstr_len("Error in client\n"));
		usleep (1000);
	}
	return (0);
}
