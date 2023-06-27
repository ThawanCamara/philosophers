# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:30:34 by tde-souz          #+#    #+#              #
#    Updated: 2023/06/27 01:03:29 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								   FILE NAME
NAME		= philo

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  OS SETTINGS
CURRENT_OS	:= $(shell uname)

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  TEXT CODES
GREEN		= \e[38;5;118m
GOLD		= \e[38;5;220m
RESET		= \e[0m
BOLD		= \e[1m

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
#								   FOLDERS
INCLUDES	= ./includes/

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									FLAGS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -fsanitize=thread -g
CFLAGS		= -Wall -Wextra -Werror -pthread -g
DEBUG		= 1
ifeq (${DEBUG}, 1)
CFLAGS		+= -fsanitize=thread
endif
CPPFLAGS	+= -I $(INCLUDES)
#CXXFLAGS
#LDFLAGS
ifeq ($(CURRENT_OS), Linux)
CFLAGS		+= -fPIE
endif
RM			= /bin/rm -f
#MAKEFLAGS	+= --silent

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
#								   FOLDERS
UTILS		:= srcs/utils
VALIDATION	:= srcs/validation
SIMCHECKS	:= srcs/sim/checks
SIMCONFIG	:= srcs/sim/config
SIMROUTINES	:= srcs/sim/routines

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								 SOURCE FILES
SRC	:=	$(VALIDATION)/validation.c $(VALIDATION)/print_error.c			\
		$(VALIDATION)/check_string.c $(VALIDATION)/check_typelimit.c	\
		$(UTILS)/ft_atol.c												\
		$(UTILS)/ft_atou.c												\
		$(UTILS)/ft_timer_utils.c										\
		$(UTILS)/ft_print_state.c										\
		$(SIMCHECKS)/ft_has_eaten_all.c									\
		$(SIMCHECKS)/ft_is_philo_alive.c								\
		$(SIMCHECKS)/ft_is_sim_running.c								\
		$(SIMCHECKS)/ft_is_simulation_active.c							\
		$(SIMCONFIG)/ft_clear_sim.c										\
		$(SIMCONFIG)/ft_init_philo.c									\
		$(SIMCONFIG)/ft_init_sim.c										\
		$(SIMCONFIG)/ft_launch_sim.c									\
		$(SIMCONFIG)/ft_mutexes_utils.c									\
		$(SIMCONFIG)/ft_philo_sim.c										\
		$(SIMCONFIG)/ft_threads_utils.c									\
		$(SIMCONFIG)/ft_terminate_sim.c									\
		$(SIMROUTINES)/ft_forks_handler.c								\
		$(SIMROUTINES)/ft_monitoring.c									\
		$(SIMROUTINES)/ft_needs.c										\
		main.c

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									 RULES

all:		$(NAME)

$(NAME):	$(SRC) $(INCLUDES)
			@$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC) -o $(NAME)
			@printf "$(RAW_NAME) [$(BOLD)$(GREEN)READY$(RESET)]\n"

clean:
#			$(RM) $(OBJS)
#			@printf "$(RAW_NAME) [$(BOLD)$(GOLD)INFO$(RESET)] - removing object files\n"

fclean:		clean
			$(RM) $(NAME)
			@printf "$(RAW_NAME) [$(BOLD)$(GOLD)INFO$(RESET)] - removing program\n"

re:			fclean all

run1:		all
			clear
			./philo 1 800 200 200
run2:		all
			clear
			./philo 5 800 200 200
run3:		all
			clear
			./philo 5 800 200 200 7 | grep "eating" | wc -l
run4:		all
			clear
			./philo 4 410 200 200
run5:		all
			clear
			./philo 4 310 200 100

.PHONY:		all clean fclean re run1 run2 run3 run4 run5
