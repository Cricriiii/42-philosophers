/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:52:48 by fox               #+#    #+#             */
/*   Updated: 2025/10/13 10:55:55 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

void	set_forks(t_thread thread, t_mutex *fork_1, t_mutex *fork_2)
{
	if (thread->id % 2)
	{
		*fork_1 = thread->fork_cur;
		*fork_2 = thread->fork_prev;
	}
	else
	{
		*fork_1 = thread->fork_prev;
		*fork_2 = thread->fork_cur;
	}
}
