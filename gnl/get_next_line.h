/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 02:06:04 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:13:15 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include "libft.h"

# define BUF_SIZE 	8

typedef struct	s_fd
{
	char		*str;
	int			fd;
}				t_fd;

int				get_next_line(int fd, char **line);

#endif
