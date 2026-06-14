/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timenow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:11:13 by fox               #+#    #+#             */
/*   Updated: 2025/10/13 10:46:06 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timenow(struct timeval *tv)
{
	struct timeval	stime;

	if (tv)
	{
		gettimeofday(tv, NULL);
		return ((tv->tv_sec * 1000 + tv->tv_usec / 1000) % TIMESTAMP_MOD);
	}
	else
	{
		gettimeofday(&stime, NULL);
		return ((stime.tv_sec * 1000 + stime.tv_usec / 1000) % TIMESTAMP_MOD);
	}
}
