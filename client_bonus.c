/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:37:51 by tgerdes           #+#    #+#             */
/*   Updated: 2021/12/19 21:10:44 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	msg_received(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR1)
	{
		ft_print_str("Received");
		ft_print_char('\n');
	}
	(void)siginfo;
	(void)context;
}

void	send_msg(int spid, char *str)
{
	size_t	str_len;
	size_t	i;
	int		bit;

	if (!str)
		return ;
	str_len = ft_strlen(str);
	str[str_len] = '\0';
	i = 0;
	while (i <= str_len)
	{
		bit = 0;
		while (bit <= 7)
		{
			if (str[i] >> bit & 1)
				kill(spid, SIGUSR2);
			else
				kill(spid, SIGUSR1);
			bit++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = msg_received;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, 0);
	if (argc == 3)
		send_msg(ft_atoi(argv[1]), argv[2]);
	else
		ft_print_str("You and your input suck!\n");
	return (0);
}
