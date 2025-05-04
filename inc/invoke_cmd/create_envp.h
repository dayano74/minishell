/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_envp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:58:03 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 12:26:30 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_ENVP_H
# define CREATE_ENVP_H

# define EQUAL_LEN 1

# include "libft.h"
# include "struct.h"
# include <stdlib.h>

char	**create_envp(t_minish *minish);

#endif
