/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:52:38 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 20:32:45 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "utils.h"

char	*ft_prompt(char *prompt)
{
	char	*result;

	while (1)
	{
		ft_putstr(prompt);
		result = get_next_line(0);
		if (!result)
		{
			ft_putstrerror("\nError: wrong argument\n");
			continue ;
		}
		if (ft_strlen(result) == 1)
		{
			ft_putstrerror("Error: argument can't be empty\n");
			continue ;
		}
		return (result);
	}
	return (NULL);
}

void	ft_handle_stdin(void)
{
	char	**argtab;
	char	*arg;

	arg = ft_prompt("Please enter some file(s): ");
	argtab = ft_split(arg, " \n");
	free(arg);
	ft_handle_args(argtab, 1);
}
