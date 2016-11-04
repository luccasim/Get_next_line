/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:53:45 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/21 16:53:48 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

# include <time.h>

# define TIME 		time(NULL)
# define CLOCK 		clock()
# define CPS(a)		ft_cps(a)

double	ft_cps(clock_t clock);
/*
** IN BUILDING
*/

#endif
