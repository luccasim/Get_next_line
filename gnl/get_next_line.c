/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:32:50 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 02:47:39 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_printf.h"

static char			*save_char(char *cpy, char **line, int *lec)
{
	int		i;
	char	*new;
	char	*ret;

	if (!cpy)
		return (NULL);
	i = 0;
	while (cpy[i])
	{
		if (cpy[i] == '\n')
		{
			ret = ft_strsub(cpy, 0, i);
			new = ft_strdup(cpy + i + 1);
			free(cpy);
			*line = ret;
			return (new);
		}
		i++;
	}
	*line = cpy;
	*lec = (*cpy) ? 1 : 0;
	return (NULL);
}

static char			*ft_realloc(char *s1, char const *s2)
{
	char	*new;

	if (!s1)
		s1 = ft_strnew(0);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	free(s1);
	return (new);
}

static t_list		*find_fd(int fd)
{
	static t_list	*list = NULL;
	t_list			*tmp;
	t_list			*new;
	t_fd			content;
	
	content.fd = fd;
	content.str = NULL;
	if (!list)
		return (list = ft_lstnew(&content, sizeof(content)));
	else
	{
		tmp = list;
		while (tmp)
		{
			if (fd == ((t_fd*)(tmp->content))->fd)
				return (tmp);
			new = tmp;
			tmp = tmp->next;
		}
		tmp = ft_lstnew(&content, sizeof(content));
		new->next = tmp;
	}
	return (tmp);
}

int					get_next_line(int fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	char			*cpy;
	t_list			*lst;
	int				ret;

	if (line == NULL || fd < 0)
		return (GNL_ERROR);
	lst = find_fd(fd);
	cpy = ((t_fd*)(lst->content))->str;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (GNL_ERROR);
		buf[ret] = 0;
		cpy = ft_realloc(cpy, buf);
		if ((((t_fd*)(lst->content))->str = save_char(cpy, line, &ret)))
			return (GNL_READ);
	}
	if ((((t_fd*)(lst->content))->str = save_char(cpy, line, &ret)))
		return (GNL_READ);
	return (ret);
}
