/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:29:37 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/14 15:29:39 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNIX_H
# define FT_UNIX_H

# include "ft_printf.h"
# include "list.h"

# define ERROR(a) 		ft_error(0, a)
# define PERROR(a) 		ft_error(a, "error")
# define OPT_BUF_SIZE 	100
# define FAIL			0
# define SUCCESS		1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

int		ft_error(char *error, char *msg);
int		ft_options(char ***av, char *opt, int32_t size);
int		ft_is_option(char c);
// t_list	*ft_stdin_file(void);
char	*ft_options_sglt(void);

#endif
