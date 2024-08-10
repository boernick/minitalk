/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:28:39 by nboer             #+#    #+#             */
/*   Updated: 2024/08/10 20:53:58 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "/home/nboer/git/Libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Checks if the signal is SIGUSR1. If it is, it will
 * assign 1 to the LSB. Else, it will assign 0 (actually it simply
 * won't modify it).
 *
 * Example:
 * 00101100   current_char
 * 00000001   result of (sigsent == SIGUSR1)
 * --------
 * 00101101   result stored in message after the bitwise OR operation
 *
 * It will then increment the bit index.
 * If it is 8, it means that
 * the char has been fully transmitted. It will then print it and
 * reset the bit index and the current char.
 * Else, it will shift the current char to the left by 1.
*/

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
		TERMINATE PROCESS;
	read_char = 0;
	bitcount = 0;
	
	printf("test");
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
