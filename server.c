/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:29:00 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/13 16:36:18 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	put_bin(char *str)
{
	int		base;
	char	res;
	int		i;

	base = 128;
	res = 0;
	i = 0;
	while (str[i] != '\0' && base != 0)
	{
		if (str[i] == '1')
		{
			res += base;
			base /= 2;
		}
		else
			base /= 2;
		i++;
	}
	ft_putchar_fd(res, 1);
}

static void	sighandler(int signal)
{
	static int	byte;
	static char	*binary;

	if (binary == NULL)
	{
		binary = ft_strdup("");
		byte = 1;
	}
	if (signal == SIGUSR1)
		binary = ft_strjoin(binary, "0");
	else
		binary = ft_strjoin(binary, "1");
	if (byte == 8)
	{
		put_bin(binary);
		free(binary);
		binary = NULL;
	}
	byte++;
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause();
	return (0);
}
