/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:45:38 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/02 03:30:04 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define GNL_BUFFER_LENGTH 15

char	*ft_append(char *buffer, size_t buf_len, char c[], size_t nread);
int		ft_is_in_charset(char c, char *charset);
void	ft_putstr(char *str);
char	**ft_split(char *str, char *charset);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, int n);
char	*get_next_line(int fd);
int		ft_atoi(char *str, unsigned long long *resptr);
int		ft_isspace(char c);
int		ft_isdigit(char c);
int		ft_strtablen(char **tab);
char	*ft_strdup(char *src);
void	ft_putstrerror(char *str);
#endif
