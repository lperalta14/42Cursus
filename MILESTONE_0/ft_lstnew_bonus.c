/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:13:32 by lperalta          #+#    #+#             */
/*   Updated: 2025/07/08 13:24:21 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new;
	
	new = (t_list*) malloc(sizeof(t_list));
		if (!new)
			return(NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
