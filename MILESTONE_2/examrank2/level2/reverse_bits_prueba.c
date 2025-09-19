/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits_prueba.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:26:50 by lperalta          #+#    #+#             */
/*   Updated: 2025/08/01 10:30:41 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
unsigned char reverse_bits(unsigned char octet)
{
	unsigned char result = 0x80;
	int i = 8;
	while(--i)
	{
		result = (result << 1 | (octet & 1));
		octet >>= 1;
	}
	return(result);
}

/*unsigned char	reverse_bits2(unsigned char octet)
{
	return(octet * 2);
}*/

int main(int argc, char **argv)
{
	printf("binario bitsoriginal:%b\n", argv[1][0]);
	printf("binario bits:%b\n", reverse_bits(argv[1][0]));
	//printf("binario bits2:%b\n", reverse_bits2(argv[1][0]));
	return(0);
}
