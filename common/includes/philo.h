/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:24:58 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 14:29:01 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef DEBUG
#  define DEBUG
# endif

# ifdef DEBUG
#  ifndef PROCESS
#   define PROCESS
#  endif
#  ifndef THREAD
#   define THREAD
#  endif
# endif

# include "philo_includes.h"
# include "philo_typedefs.h"
# include "philo_structures.h"
# include "philo_enums.h"

t_monitor	philo_init(char **argv, void (*kill)(t_monitor, int, char *));
void		scenario_init(t_monitor philo, char **argv, \
										void (*kill)(t_monitor, int, char *));

void		exit_at_input(int argc, char **argv, \
										void (*kill)(t_monitor, int, char *));

void		*ft_calloc(size_t nmemb, size_t size);
int			ft_puterr(char *errmsg);
size_t		ft_strlen(const char *s);
long		timenow(struct timeval *tv);
void		precise_sleep(long time_to_sleep);
int			ft_min(int a, int b);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
int			ft_strcmp(const char *s1, const char *s2);
int			randval(int max);

#endif
