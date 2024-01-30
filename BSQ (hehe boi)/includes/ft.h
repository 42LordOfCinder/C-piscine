/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:44:07 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 20:32:10 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

void	ft_handle_args(char **argv, int is_stdin);
char	*ft_get_map_content(int fd, char *file_name);
int		ft_get_file_size(int fd);
void	ft_handle_stdin(void);
int		ft_check_map(char *content, char **splitted_content);
int		ft_check_header(char *str, char **ptr);
void	ft_resolve(char **splitted_content);
int		ft_is_obstacle(char c, char *splitted_content);
void	ft_draw(char **sc, t_coord maxcoord, int size);
void	ft_display(char **sc);

# define ERR_MAP "map error\n"
#endif
