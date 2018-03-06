#include "../get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	(void)argc;
	char *line;
	int		fd;
	int		fd2;
	int		fd3;
	int		i;

	i = 1;
	fd = 3;


	line = NULL;
//	while(fd > 2)
//	{
//		fd = open(argv[i++], O_RDONLY);
//		printf("%d\n", fd);
//		while(get_next_line(fd, &line))
//		{
//			printf("%s\n", line);
//		}
//
//	}
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	get_next_line(fd, &line);
	printf("%s\n", line);
	fd = open(argv[2], O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	get_next_line(fd, &line);
	printf("%s\n", line);
	fd = open(argv[3], O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	get_next_line(fd, &line);
	printf("%i\n", get_next_line(fd, &line));
	return (0);
}