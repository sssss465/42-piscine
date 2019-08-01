/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:06:20 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/25 15:36:08 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_lib.h"
#include <errno.h>

#define BUF_SIZE 30

int		main(int argc, char **argv)
{
	int			fd;
	int			ret;
	int			i;
	char		buf[BUF_SIZE + 1];
	extern int	errno;

	i = (argc < 2) ? -1 : 1;
	while (i < argc)
	{
		fd = (i == -1) ? 0 : open(argv[i++], O_RDONLY);
		if (fd == -1 && errno == 2)
		{
			ft_putstr("ft_cat: ");
			ft_putstr(argv[i - 1]);
			ft_putstr(": No such file or directory\n");
			continue ;
		}
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
	}
	return (0);
}
