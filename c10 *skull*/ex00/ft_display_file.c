/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:31:54 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/28 18:38:39 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(1, "File name is missing.\n", 22);
		return (0);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
}
