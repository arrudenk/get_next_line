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

#include <stdio.h>
#include "get_next_line.h"

t_tail	*new_fd(int fd, t_list *fd_list)
{
	t_tail	*tail;

	tail = ft_memalloc(sizeof(tail));
	tail->fd = fd;
	ft_lstadd(&fd_list, ft_lstnew(tail, sizeof(t_tail)));
	free(tail);
	return (tail);
}

t_tail	*find_fd(t_list *fd_list, int fd)
{
	t_tail *tail;

	tail = (t_tail *)(fd_list->content);
	if (tail->fd != fd && fd_list->next == NULL)
		return (new_fd(fd, fd_list));
	if (tail->fd != fd)
		find_fd(fd_list->next, fd);

	return (tail);
}

t_list	*init_list(const int fd)
{
	t_list	*fd_list;
	t_tail	*tail;

	fd_list = NULL;
	tail = ft_memalloc(sizeof(t_tail));
	tail->fd = fd;
	ft_lstadd(&fd_list, ft_lstnew(tail, sizeof(t_tail)));
	free(tail);
	return (fd_list);
}

int		discard_tail(char **str)
{
	char	*result;

	if (!**str)
		return (0);
	result = *str;
	if (!ft_strchr(*str, '\n'))
	{
		if (*str != NULL)
			ft_strdel(str);
		return (1);
	}
	*str = ft_strdup(ft_strchr(*str, '\n') + 1);
	free(result);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	t_tail			*t;
	static t_list	*fd_list = NULL;

	buff = ft_strnew(sizeof(char) * BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE + 1);
	if (fd < 0 || !line || !buff)
		return (-1);
	if(fd_list == NULL)
		fd_list = init_list(fd);
	t = find_fd(fd_list, fd);
	if (t->str == NULL)
		t->str = ft_strnew(0);
	while (read(fd, (void *)buff, BUFF_SIZE) > 0)
	{
		t->str = ft_strjoin(t->str, buff);
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ft_strchr(t->str, '\n')))
			break ;
	}
	ft_strdel(&buff);
	*line = !ft_strchr(t->str, '\n') ? ft_strsub(t->str, 0, ft_strlen(t->str))
			:ft_strsub(t->str, 0, (ft_strchr(t->str, '\n') - t->str));
	return (discard_tail(&t->str));
}

int		main(int argc, char **argv)
{
	(void)argc;
	char *line;
	int		fd;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	int check;
	check = 1;
	while (check != 0 && check != -1)
	{
		check = get_next_line(fd, &line);
		if (check != 0 && check != -1)
			printf("%s\n",line);
		ft_strdel(&line);
	}
	close(fd);
	printf("\nReading complete\n\n");
	fd = open(argv[2], O_RDONLY);
	check = 1;
	while (check != 0 && check != -1)
	{
		check = get_next_line(fd, &line);
		if (check != 0 && check != -1)
			printf("%s\n",line);
		ft_strdel(&line);
	}
	close(fd);
	printf("\nReading complete\n\n");
	fd = open(argv[3], O_RDONLY);
	check = 1;
	while (check != 0 && check != -1)
	{
		check = get_next_line(fd, &line);
		if (check != 0 && check != -1)
			printf("%s\n",line);
		ft_strdel(&line);
	}
	close(fd);
	printf("\nReading complete\n\n");
	return (0);
}
