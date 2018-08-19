/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:47:04 by srabah            #+#    #+#             */
/*   Updated: 2014/11/13 02:47:35 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ptr;

	if (!content || !content_size)
	{
		if ((ptr = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		if ((ptr->content = (void *)malloc(sizeof(content_size))) == NULL)
			return (NULL);
		ptr->content = NULL;
		ptr->content_size = 0;
		return (ptr);
	}
	if (content != NULL)
	{
		if ((ptr = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		if ((ptr->content = (void *)malloc(sizeof(content_size))) == NULL)
			return (NULL);
		ptr->content_size = content_size;
		memcpy(ptr->content, content, content_size);
		ptr->next = NULL;
	}
	return (ptr);
}
