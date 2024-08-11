/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:01:15 by nboer             #+#    #+#             */
/*   Updated: 2024/08/11 21:25:23 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/nboer/git/minitalk/ft_printf/ft_printf.h"
#include "/home/nboer/git/minitalk/Libft/libft.h"

int	bit_len(int nbr)
{
	int	i;

	i = 1;
	while (nbr > 1)
	{
		i++;
		nbr = nbr / 2;
	}
	return (i);
}

void	get_bits(int number, int pid)
{
	int	i;

	if (number >= 2)
		get_bits(number / 2, pid);
	i = number % 2;
	if (i == 0)
		kill(pid, SIGUSR2);
	else if (i == 1)
		kill(pid, SIGUSR1);
	usleep(100);
}

void	send_char(char c, int pid)
{
	int	n;

	n = 8 - bit_len(c);
	while (n > 0)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		n--;
	}
	get_bits(c, pid);
}


int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	pid;

	if (argc < 3)
	{
		ft_printf("error");
		exit(EXIT_FAILURE);
	}

	pid = ft_atoi(argv[1]);
	i = 2;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			send_char(argv[i][j], pid);
			j++;
		}
		if (i < argc - 1)
			send_char(' ', pid);
		i++;
	}
	send_char('\0', pid);
}
