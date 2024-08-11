/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:28:39 by nboer             #+#    #+#             */
/*   Updated: 2024/08/11 21:40:14 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/nboer/git/minitalk/ft_printf/ft_printf.h"
#include "/home/nboer/git/minitalk/Libft/libft.h"

// Display its PID
// Create an endless loop so that the server can receive signals at any time
// Receive signals
// Decrypt signals
// For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action

void	handle_sig(int sig)
{
	int		bitcount;
	//int				read_char[8];
	char	read_char;

	read_char = 1;
	while (read_char != 0)
	{
		read_char = 0;
		bitcount = 0;
		while (bitcount < 8)
		{
			if (sig == SIGUSR1)
				read_char++;
			read_char = read_char << 1;
			bitcount++;
		}
		ft_putchar_fd(read_char, 1);
	}
	ft_putchar_fd('\n', 1);
	// if (sig == SIGUSR1)
	// {
	// 	// read_char |= 1;
	// 	write(1, "1", 1);
	// }
	// else if (sig == SIGUSR2)
	// {
	// 	// read_char |= 0;
	// 	write(1, "0", 1);
	// }
	// bitcount++;
	// if (bitcount == 8)
	// {
	// 	else
	// 		ft_printf("%c", read_char);
	// 	read_char = 0;
	// 	bitcount = 0;
	// }
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
	{
		// ft_printf("Running... Press Ctrl+C to send SIGINT.\n");
		pause();
	}
}
