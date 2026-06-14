# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 10:25:03 by cgajean           #+#    #+#              #
#    Updated: 2025/10/20 14:07:43 by cgajean          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################################
#	GENERAL VARIABLES									#
#########################################################

CC				= cc
CFLAGS			= -Wall -Werror -Wextra -MMD -MP -g3
LDFLAGS 		= -lpthread
MAIN_DIR		= .

DEF_THREAD		= -DTHREAD
DEF_PROCESS		= -DPROCESS

DEF_MANDATORY	= $(DEF_THREAD)
DEF_BONUS		= $(DEF_PROCESS)
DEF_COMMON		= $(DEF_MANDATORY) $(DEF_BONUS)


#########################################################
#	PHILOSOPHERS										#
#########################################################

NAME			= philo_thread
BONUS			= philo_semaphore

SRC_DIR			= source_mutex
BNS_DIR			= source_semaphore
COM_DIR			= common
OBJ_DIR			= .build

INC_COM			= $(COM_DIR)/includes
INC_TH			= $(SRC_DIR)/includes
INC_BNS			= $(BNS_DIR)/includes

ERRORS_COM		= $(COM_DIR)/errors
DESTROY_TH		= $(SRC_DIR)/destroy

INIT_COM		= $(COM_DIR)/init
INIT_TH			= $(SRC_DIR)/init
PTHREAD_H		= $(SRC_DIR)/pthread_h

MAINLOOP_TH		= $(SRC_DIR)/mainloop



INIT_SEM		= $(BNS_DIR)/init
MAINLOOP_SEM	= $(BNS_DIR)/mainloop
DESTROY_SEM		= $(BNS_DIR)/destroy

UTILS			= $(COM_DIR)/utils

SRCS = \
		$(INIT_TH)/philo_th_init.c						\
		$(SRC_DIR)/main.c								\
		$(DESTROY_TH)/philo_th_destroy.c				\
		$(DESTROY_TH)/philo_th_kill.c					\
		$(INIT_TH)/fork_init.c							\
		$(INIT_TH)/threads_init.c						\
		$(MAINLOOP_TH)/check_death.c					\
		$(MAINLOOP_TH)/check_stop.c						\
		$(MAINLOOP_TH)/mainloop_th_start.c				\
		$(MAINLOOP_TH)/monitor_mainloop.c				\
		$(MAINLOOP_TH)/philo_eat.c						\
		$(MAINLOOP_TH)/philo_sleep.c					\
		$(MAINLOOP_TH)/philo_think.c					\
		$(MAINLOOP_TH)/set_forks.c						\
		$(MAINLOOP_TH)/sleep_split.c					\
		$(MAINLOOP_TH)/thread_mainloop.c				\
		$(PTHREAD_H)/ft_pthread_mutex_spinlock.c			\
		$(PTHREAD_H)/ft_pthread_mutex_unlock.c

COMS = \
		$(INIT_COM)/philo_init.c						\
		$(INIT_COM)/scenario_init.c						\
		$(ERRORS_COM)/exit_at_input.c					\
		$(UTILS)/ft_atoi.c								\
		$(UTILS)/ft_calloc.c							\
		$(UTILS)/ft_isdigit.c							\
		$(UTILS)/ft_itoa.c								\
		$(UTILS)/ft_min.c								\
		$(UTILS)/ft_puterr.c							\
		$(UTILS)/ft_strcmp.c							\
		$(UTILS)/ft_strlen.c							\
		$(UTILS)/randval.c								\
		$(UTILS)/timenow.c

BNS = \
		$(BNS_DIR)/main.c								\
		$(INIT_SEM)/philo_sem_init.c					\
		$(DESTROY_SEM)/kill_processes.c					\
		$(DESTROY_SEM)/philo_sem_destroy.c				\
		$(DESTROY_SEM)/philo_sem_kill.c					\
		$(DESTROY_SEM)/wait_processes.c					\
		$(DESTROY_SEM)/semaphores_close.c				\
		$(DESTROY_SEM)/semaphores_unlink.c				\
		$(MAINLOOP_SEM)/mainloop_sem_start.c			\
		$(MAINLOOP_SEM)/mainloop_sem_stop.c				\
		$(MAINLOOP_SEM)/monitor_mainloop.c				\
		$(MAINLOOP_SEM)/process_mainloop.c				\
		$(MAINLOOP_SEM)/philo_eat.c						\
		$(MAINLOOP_SEM)/philo_sleep.c					\
		$(MAINLOOP_SEM)/philo_think.c					\
		$(MAINLOOP_SEM)/sleep_split.c					\
		$(MAINLOOP_SEM)/check_death.c


OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:%.o=%.d)

OBJS_COM	= $(COMS:%.c=$(OBJ_DIR)/%.o)
DEPS_COM	= $(OBJS_COM:%.o=%.d)

OBJS_BNS	= $(BNS:%.c=$(OBJ_DIR)/%.o)
DEPS_BNS	= $(OBJS_BNS:%.o=%.d)


#########################################################
#	MAKE												#
#########################################################

all: $(NAME) semaphore

$(NAME): $(OBJS) $(OBJS_COM)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_COM) -D$(DEF_MANDATORY) -o $(NAME) $(LDFLAGS)

semaphore: $(BONUS)

$(BONUS): $(OBJS_BNS) $(OBJS_COM)
	$(CC) $(CFLAGS) $(OBJS_BNS) $(OBJS_COM) -D$(DEF_BONUS) -o $(BONUS) $(LDFLAGS)

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEF_MANDATORY) -I $(INC_COM) -I $(INC_TH) -c $< -o $@

$(OBJ_DIR)/$(BNS_DIR)/%.o: $(BNS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEF_BONUS) -I $(INC_COM) -I $(INC_BNS) -c $< -o $@

$(OBJ_DIR)/$(COM_DIR)/%.o: $(COM_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEF_COMMON) -I $(INC_COM) -c $< -o $@

-include $(DEPS) $(DEPS_COM) $(DEPS_BNS)

clean:
	rm -rf $(OBJ_DIR) $(OBJS_BNS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all semaphore

.PHONY: all semaphore clean fclean re
