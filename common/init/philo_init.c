/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_th_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:32:48 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 10:24:55 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_monitor	philo_init(char **argv, void (*kill)(t_monitor, int, char *))
{
	t_monitor	new;

	new = ft_calloc(1, sizeof(struct s_monitor));
	if (new)
	{
		new->monitor = ft_calloc(1, sizeof(pthread_t *));
		if (!new->monitor)
			kill(new, EXIT_FAILURE, "Error at init. Exit now...\n");
		scenario_init(new, argv, kill);
	}
	else
	{
		kill(new, EXIT_FAILURE, "Error at init. Exit now...\n");
	}
	return (new);
}
