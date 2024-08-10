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


sigset_t	set;

// 1. a socket (an endpoint for communication) is identified by 
// 		an IP adress concatenated with a port number
// 2. the server waits for incoming client requests by listening to 
// 		a specified port. Once a request is received, the server
//		accepts a connection from the socket to complete the 
//		connection.
// 3. A port number identifies what kind of services will be provided
// 4. Most ports below the number 1024 are reserved for standard services
// 5. When a client process initiates a request for a connection,
//		it is assigned a port by the host computer, which is
//		an arbitrary number greater than 1024.
// 6. Based on the destination port number, the packets traveling 
// 		between the hosts are delivered to the appropriate process.

int	main(int argc, char *argv[])
{
	int i;
	int j;
	typedef struct sigaction
	{
	} sig;


	
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

void	client(server PID, char *str);
{

}

void	server()
