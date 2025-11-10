/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:32:03 by lperalta          #+#    #+#             */
/*   Updated: 2025/07/08 13:43:57 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int		len;
	t_list *temp;

	temp = lst;
	len = 1;
	while (temp->next)
	{
		temp = temp->next;
		len++;
	}
	return(len);
}
