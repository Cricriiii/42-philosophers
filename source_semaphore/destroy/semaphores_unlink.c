/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_unlink.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:22:27 by fox               #+#    #+#             */
/*   Updated: 2025/10/17 13:46:56 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	semaphores_unlink(void)
{
	sem_unlink(SEM_TOTAL_MEALS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_TBL_SEATS);
	sem_unlink(SEM_FORKS);
}
