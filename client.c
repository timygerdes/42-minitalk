/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:59:42 by tgerdes           #+#    #+#             */
/*   Updated: 2021/12/19 21:16:49 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	if (argc == 3)
		send_msg(ft_atoi(argv[1]), argv[2]);
	else
		ft_print_str("Your input is simply wrong! Please try again.\n");
	return (0);
}
