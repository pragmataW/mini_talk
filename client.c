/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:28:51 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/13 12:47:02 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	get_bit(int pid, char c)
{
	int	bit;
	int	n;
	int	i;

	n = 7;
	i = 0;
	while (n >= 0)
	{
		bit = (c >> n) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		n--;
	}
}

void	get_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		get_bit(pid, str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc < 3)
		ft_putstr_fd(LOWARGERR, 1);
	if (argc > 3)
		ft_putstr_fd(TOOARGERR, 1);
	pid = atoi(argv[1]);
	get_char(pid, argv[2]);
	return (0);
}
