/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:08:43 by ikalende          #+#    #+#             */
/*   Updated: 2023/03/07 06:06:03 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

char	*get_next_line(int fd);
char	*ft_readtil_nl(int fd, char *buf, char *tmp_buf);
char	*ft_ret_nl(char *str, char *buf);
char	*ft_edit_buf(char *buf);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_jonfre(char *buf, const char *tmp_buf);
int		ft_is_nwln(char *str);
void	*ft_camalloc(size_t count, size_t size);
#endif
