/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmikola <jmikola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:13:45 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/16 10:10:04 by jmikola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rush02(int x, int y);
int		ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if ((ft_atoi(argv[1])) < 0 || ft_atoi(argv[2]) < 0)
			write(1, "Error: positive number expected", 30);
		else
			ft_rush02(ft_atoi(argv[1]), ft_atoi(argv[2]));
	}
	else
	{
		write(1, "Error: 2 arguments expected, ", 29);
	}
	return (0);
}
