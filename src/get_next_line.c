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

int		check_n(char *line, t_tail *tail)
{
	int		i;
	int		rt;
	int		v;
	int		t;

	i = -1;
	rt = 1;
	v = 0;
	while (line[++i])
	{
		if (line[i] == '\n')
		{
			t = i;
			tail->str = ft_memalloc(ft_strlen(line) - i + 1);
			while (line[++i])
			{
				tail->str[v] = line[i];
				line[i] = '\0';
				v++;
			}
			line = ft_strsub(line, 0, t);
			tail->str[v] = '\0';
			rt = 0;
		}
	}
	return (rt);
}

t_tail	*find_fd(t_list *fd_list, int fd)
{
	t_tail *tail;

	tail = (t_tail *)(fd_list->content);
	if (fd_list->content == NULL)
	{
		tail = ft_memalloc(sizeof(t_tail));
		tail->fd = fd;
		ft_lstadd(&fd_list, ft_lstnew(tail, sizeof(t_tail)));
	}
	if (tail->fd == fd)
		return (tail);
	else
		find_fd(fd_list->next, fd);
}

t_list	*init_list(const int fd)
{
	t_list	*fd_list;
	t_tail	*tail;

	fd_list = NULL;
	tail = ft_memalloc(sizeof(tail));
	tail->fd = fd;
	ft_lstadd(&fd_list, ft_lstnew(tail, sizeof(t_tail)));
	return (fd_list);
}

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	t_tail			*tail;
	static t_list	*fd_list = NULL;

	buff = NULL;
	if(fd_list == NULL)
		fd_list = init_list(fd);
	tail = find_fd(fd_list, fd);
	if (*line == NULL)
		*line = ft_memalloc(sizeof(char));
	if (tail->str != NULL)
		*line = ft_strjoin(*line, tail->str);
	ft_strdel(&tail->str);
	check_n(*line, tail);
	buff = ft_memalloc(sizeof(char) * BUFF_SIZE);
	while (read(fd, (void *)buff, BUFF_SIZE) > 0)
	{
		*line = ft_strjoin(*line, buff);
		if (!check_n(*line, tail))
			break ;
	}
	if (tail->str == NULL && ft_strlen(*line) == 0)
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	(void)argc;
	char *line;
	int		fd;
	char	*arg;

	line = NULL;

	arg = argv[1];

	fd = open(argv[1], O_RDONLY);
	int check;
	check = 1;
	while (check != 0 && check != -1)
	{
		check = get_next_line(fd, &line);
		if (check != 0 && check != -1)
			printf("gnl returned %d | line is %s\n", check, line);
		ft_strdel(&line);
	}
	printf("Reading complete\n");
	return (0);
}
