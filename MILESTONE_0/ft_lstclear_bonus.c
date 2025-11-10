/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:58:53 by lperalta          #+#    #+#             */
/*   Updated: 2025/07/08 17:15:32 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	
	temp = (t_list*)malloc(sizeof(tlist));
		if (!temp)
			return(NULL);
	temp = *lst;
	lst = NULL;
	while ((lst || del) && (lst->next))
	{
		temp = temp->next;
		del(temp->content);
		free(temp)
	}
}
