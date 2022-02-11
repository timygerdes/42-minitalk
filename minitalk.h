/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:55:46 by tgerdes           #+#    #+#             */
/*   Updated: 2021/12/19 21:17:25 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_print_str(char *str);
void	ft_print_char(char c);
size_t	ft_strlen(char *str);
void	ft_print_nbr(int nbr);
int		ft_atoi(const char *str);

#endif