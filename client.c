/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:01:15 by nboer             #+#    #+#             */
/*   Updated: 2024/08/10 17:39:57 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/nboer/git/Libft/libft.h"


// Write a program (main) in which the client takes two parameters/arguments
// The PID of the server to which it wants to send the message
// A message
// Encrypt the message (I did the encryption via bits)
// Send the message to the server (via its PID)
// Create a stop condition so that the server knows when it has finished receiving the message
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit



int	main(int argc, char *argv[])
{
	int i;
	int j;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, argv[i][j], 1);
			j++;
		}
		i++;
	}

	sigemptyset()

	sigaddset()
	
	// I need:
	// Set up a server and return its PID
	// the client takes the PID as argument, and a string to send
}