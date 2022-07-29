/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:37:37 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/15 19:26:11 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static unsigned int	ft_change(int signal, unsigned int byt)
{
	if (signal == 0)
		return (0);
	if (byt == 0)
		return (256);
	if (byt == 1)
		return (128);
	if (byt == 2)
		return (64);
	if (byt == 3)
		return (32);
	if (byt == 4)
		return (16);
	if (byt == 5)
		return (8);
	if (byt == 6)
		return (4);
	if (byt == 7)
		return (2);
	else
		return (1);
}

static void	sighandler(int signal, struct __siginfo *act, void *contenxt)
{
	static unsigned int	abc;
	static unsigned int	byt;

	(void) act;
	(void) contenxt;
	abc += ft_change(signal - 30, byt);
	if (act->si_pid)
		kill(act->si_pid, SIGUSR1);
	if (++byt == 9)
	{
		ft_putchar_len(abc);
		abc = 0;
		byt = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	ft_putstr_len("Server run\nPID: ");
	pid = getpid();
	ft_putnbr_len(pid);
	write(1, "\n", 1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sighandler;
	pid = sigaction(SIGUSR1, &act, 0);
	if (pid < 0)
		exit(ft_putstr_len("Error\n"));
	pid = sigaction(SIGUSR2, &act, 0);
	if (pid < 0)
		exit(ft_putstr_len("Error\n"));
	while (1)
		sleep (1);
	return (0);
}
