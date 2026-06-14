/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_th_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:46:06 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 11:46:08 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

t_monitor	philo_th_init(char **argv)
{
	t_monitor	new;

	new = philo_init(argv, philo_th_kill);
	if (new)
		threads_init(new);
	return (new);
}
