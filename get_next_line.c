/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:54:56 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 14:54:58 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_tail	*init_list(int fd)
{
	t_tail	*tail;

	tail = ft_memalloc(sizeof(t_tail));
	tail->fd = fd;
	tail->str = ft_strnew(0);
	tail->next = NULL;
	tail->start = tail;
	return (tail);
}

t_tail	*add_fd(int fd, t_tail *tail)
{
	tail = ft_memalloc(sizeof(t_tail));
	tail->fd = fd;
	tail->str = ft_strnew(0);
	tail->next = NULL;
	return (tail);
}

t_tail	*find_fd(t_tail *tail, int fd)
{
	t_tail	*temp;

	temp = tail;
	while (tail != NULL)
	{
		if (tail->fd == fd)
			return (tail);
		tail = tail->next;
	}
	tail = add_fd(fd, tail);
	tail->next = temp;
	return (tail);
}

int		discard_tail(t_tail *tail)
{
	char	*result;

	if (!tail->str[0])
		return (0);
	result = tail->str;
	if (!ft_strchr(tail->str, '\n'))
	{
		if (tail->str != NULL)
			ft_strdel(&tail->str);
		return (1);
	}
	tail->str = ft_strdup(ft_strchr(tail->str, '\n') + 1);
	free(result);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	ssize_t			bs;
	static t_tail	*t = NULL;

	if (fd == 4)
		ft_putchar('j');
	buff = ft_strnew(sizeof(char) * BUFF_SIZE);
	if (fd < 0 || !line || !buff)
		return (-1);
	if (t == NULL)
		add_fd(fd, t);
	t = (t == NULL) ? (add_fd(fd, t)) : (find_fd(t, fd));
	if (t->str == NULL)
		return (0);
	while ((bs = read(fd, (void *)buff, BUFF_SIZE)))
	{
		if (bs == -1)
			return (-1);
		t->str = ft_strjoin(t->str, buff);
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ft_strchr(t->str, '\n')))
			break ;
	}
	ft_strdel(&buff);
	*line = (!ft_strchr(t->str, '\n')) ? ft_strsub(t->str, 0, ft_strlen(t->str))
			: ft_strsub(t->str, 0, (ft_strchr(t->str, '\n') - t->str));
	return (discard_tail(t));
}
