/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_includes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:49:35 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/19 11:12:23 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INCLUDES_H
# define PHILO_INCLUDES_H

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

# define TIMESTAMP_MOD 1000000

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <stdint.h>
# include <errno.h>
# include <stdint.h>

# include <signal.h>
# include <semaphore.h>

#endif
