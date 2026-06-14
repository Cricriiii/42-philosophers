/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:08:16 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 10:46:06 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	randval(int max)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (max)
		return (tv.tv_usec % max);
	else
		return (0);
}
