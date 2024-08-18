/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:28:39 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 15:16:18 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/nboer/git/minitalk/ft_printf/ft_printf.h"
#include "/home/nboer/git/minitalk/Libft/libft.h"

void	handle_sig(int sig)
{
	static int				bitcount;
	static unsigned char	read_char;

	if (bitcount < 8)
	{
		if (sig == SIGUSR1)
			read_char++;
		if (bitcount < 7)
			read_char <<= 1;
		bitcount++;
	}
	if (bitcount == 8)
	{
		if (read_char == 0)
			ft_printf("\n");
		else
		{
			ft_printf("%c", read_char);
			read_char = 0;
		}
		bitcount = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
		pause();
	return (0);
}
