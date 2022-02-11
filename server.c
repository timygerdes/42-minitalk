/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:06:36 by tgerdes           #+#    #+#             */
/*   Updated: 2022/01/17 17:53:38 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	process_msg(int sig, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
		c += (0 << i);
	if (sig == SIGUSR2)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_print_char('\n');
			i = 0;
			c = 0;
		}
		ft_print_char(c);
		i = 0;
		c = 0;
	}
	(void)context;
	(void)siginfo;
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &process_msg;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	ft_print_str("The server PID is: ");
	ft_print_nbr(getpid());
	ft_print_char('\n');
	while (1)
		pause();
	return (0);
}
