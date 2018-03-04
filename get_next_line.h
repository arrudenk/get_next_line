/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:55:03 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 14:55:07 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include "fcntl.h"
# define BUFF_SIZE 32

typedef struct		s_tail
{
	char			*str;
	int				fd;
	struct s_tail	*start;
	struct s_tail	*next;
}					t_tail;

int					get_next_line(const int fd, char **line);

#endif
