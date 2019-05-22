/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 09:38:30 by mrassokh          #+#    #+#             */
/*   Updated: 2017/01/03 16:18:08 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*create_buf(t_list **begin, int fd)
{
	t_list	*cursor;
	t_buf	*content;

	if (!begin)
		return (NULL);
	cursor = *begin;
	while (cursor)
	{
		if (((t_buf *)cursor->content)->fd == fd)
			return (cursor);
		cursor = cursor->next;
	}
	if ((content = (t_buf *)malloc(sizeof(t_buf))))
	{
		content->buf = NULL;
		content->fd = fd;
		content->count = 0;
		content->n_flag = 0;
		if ((cursor = ft_lstnew(content, sizeof(t_buf))))
			ft_lstadd(begin, cursor);
	}
	return (cursor);
}

int		append_from_buff(char **line, char *buf, size_t len, t_buf *buf_fd)
{
	char	temp[BUFF_SIZE + 1];
	char	*new_line;

	ft_bzero(temp, BUFF_SIZE + 1);
	if (buf_fd->n_flag)
	{
		free(*line);
		if (!(*line = ft_strsub(buf, 0, len)))
			return (0);
		buf_fd->n_flag = 0;
	}
	else
	{
		ft_strncpy(temp, buf, len);
		if (!(new_line = ft_strjoin(*line, temp)))
			return (0);
		free(*line);
		*line = new_line;
	}
	return (1);
}

int		rewrite_line(char **line, char *buf, size_t len, t_buf *buf_fd)
{
	if (!(*line))
	{
		if (!(*line = ft_strsub(buf, 0, len)))
			return (0);
		buf_fd->n_flag = 0;
	}
	else
	{
		if (!append_from_buff(line, buf, len, buf_fd))
			return (0);
	}
	return (1);
}

int		write_to_line(t_buf **buf_fd, char *buf, char **line, int ret)
{
	char	*sn;

	if (ret < 0)
		return (0);
	if (!(sn = ft_strchr(buf, '\n')))
	{
		if (!(rewrite_line(line, buf, ft_strlen(buf), *buf_fd)))
			return (0);
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((*buf_fd)->buf)
			free((*buf_fd)->buf);
		(*buf_fd)->buf = NULL;
		(*buf_fd)->count = 1;
	}
	else
	{
		if (!(rewrite_line(line, buf, sn - buf, *buf_fd)))
			return (0);
		if ((*buf_fd)->buf)
			free((*buf_fd)->buf);
		(*buf_fd)->buf = ft_strdup(sn + 1);
		(*buf_fd)->n_flag = 1;
		(*buf_fd)->count = 0;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*buff_begin;
	t_list			*curr;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !(curr = create_buf(&buff_begin, fd)))
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (((t_buf*)curr->content)->buf && ft_strlen(((t_buf*)curr->content)->buf))
	{
		ft_strncpy(buf, ((t_buf*)curr->content)->buf,
					ft_strlen(((t_buf*)curr->content)->buf));
		if (!write_to_line(((t_buf**)&(curr->content)), buf, line, 1))
			return (-1);
		else if (ft_strlen(buf))
			return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
		if (!write_to_line((t_buf**)&(curr->content), buf, line, ret))
			return (-1);
		else if (ft_strlen(buf))
			return (1);
	if (((t_buf*)curr->content)->count-- > 0)
		return (1);
	return (0);
}
