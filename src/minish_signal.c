/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:35:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/08 16:57:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish_signal.h"

volatile sig_atomic_t	g_sig_sts = 0;

/**
 * @brief Handler function when ctrl+c is pressed
 *
 * @param signum
 */
static void	ctrl_c(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig_sts = signum + 2;
}

/**
 * @brief Sets the value of the sigaction structure
 *
 * @param sa		: sigaction structure
 * @param handler	: handler funciton
 */
static void	_set_sigaction(struct sigaction *sa, void (*handler)(int))
{
	if (!handler)
		sa->sa_handler = SIG_IGN;
	else
		sa->sa_handler = handler;
	sigemptyset(&(sa->sa_mask));
	sa->sa_flags = 0;
}

/**
 * @brief Sets SIGINT(ctrl+c) and SIGQUIT(ctrl+\).
 *
 * @note ctrl+d is EOF, so it is managed separately.
 */
void	minish_signal(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	_set_sigaction(&sa_int, ctrl_c);
	_set_sigaction(&sa_quit, NULL);
	sigaction(SIGINT, &sa_int, NULL);
	sigaction(SIGQUIT, &sa_quit, NULL);
}
