/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:28:39 by nboer             #+#    #+#             */
/*   Updated: 2024/08/10 21:04:54 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "/home/nboer/git/Libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Display its PID
// Create an endless loop so that the server can receive signals at any time
// Receive signals
// Decrypt signals
// For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action

void	handle_sig(int sig)
{
	static int	bitcount;
	unsigned char	 read_char;

	if (sig == SIGUSR1)
		read_char | 1;
	else if (sig == SIGUSR2)
		read_char | 0;
	bitcount++;
	if (bitcount == 8)
	{
		TERMINATE PROCESS;
		printf("%c", read_char);
		read_char = 0;
		bitcount = 0;
	}

}


int	main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, &handle_sig);
	signal(SIGUSR2, &handle_sig);
	while (1)
	{
		printf("Running... Press Ctrl+C to send SIGINT.\n");
		sleep(2);
	}

}
