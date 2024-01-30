/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:10:38 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 20:32:25 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_handle_stdin();
	else
		ft_handle_args(argv + 1, 0);
	return (0);
}
