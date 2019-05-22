/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 09:37:58 by mrassokh          #+#    #+#             */
/*   Updated: 2017/01/02 18:20:07 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000
# include "libft.h"
# include <fcntl.h>

typedef struct		s_buf
{
	char			*buf;
	int				fd;
	int				count;
	int				n_flag;
}					t_buf;

int					get_next_line(const int fd, char **line);

#endif
