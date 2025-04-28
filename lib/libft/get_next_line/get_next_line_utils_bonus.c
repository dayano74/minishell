/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:08:41 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 16:24:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Copy src to dst up to the number of characters srcsize 
 * 
 * @param dst 
 * @param src 
 * @param srcsize 
 * @return char* 
 */
char	*gnl_strncpy(char *dst, const char *src, size_t srcsize)
{
	size_t	i;

	i = 0;
	while (i < srcsize && *src)
		dst[i++] = *src++;
	if (i < srcsize)
		dst[i] = '\0';
	return (dst);
}

/**
 * @brief Fill memory area b with the contents of c up to size len
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
 */
void	*gnl_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}

/**
 * @brief Allocate a memory area of count * size filled with 0. 
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*gnl_calloc(size_t count, size_t size)
{
	void	*_block;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / count)
		return (NULL);
	_block = malloc(count * size);
	if (!_block)
		return (NULL);
	gnl_memset(_block, 0, count * size);
	return (_block);
}

/**
 * @brief Releases the string in line and sets NULL.
 * 
 * @param line 
 * @return void* 
 */
void	*gnl_line_free(t_string *line)
{
	if (line->str)
	{
		free(line->str);
		line->str = NULL;
	}
	return (NULL);
}

/**
 * @brief Sets the status of gnl.
 * 
 * @param status 
 * @return t_sts* 
 */
t_sts	*set_sts(t_sts *status)
{
	if (status->getc_sts == GETC_OTHER && status->putc_sts == PUTC_OK)
		status->gnl_sts = GNL_READ;
	else if (status->getc_sts == GETC_LF && status->putc_sts == PUTC_OK)
		status->gnl_sts = GNL_LF;
	else if (status->getc_sts == GETC_EOF && status->putc_sts == PUTC_OK)
		status->gnl_sts = GNL_EOF;
	else
		status->gnl_sts = GNL_ERR;
	return (status);
}
