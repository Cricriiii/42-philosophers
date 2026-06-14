/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_enums.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:51:47 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/10 17:10:17 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ENUMS_H
# define PHILO_ENUMS_H

enum e_return
{
	INIT_SUCCESS,
	INIT_FAILURE
};

enum e_errors
{
	E_CREATE
};

enum e_thread_state
{
	ALIVE,
	DEAD
};

#endif