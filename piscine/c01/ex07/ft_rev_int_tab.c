/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:07:11 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/11 10:49:04 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
    int i;
    int t;

    i = 0;
    while (i < size)
    {
        t = tab[i];
        tab[i] = tab [size - 1 - i];
        tab[size - 1 - i] = t;
        i++;
        size--;
    }
}
/*
int	main()
{
	int tab[7] = {0, 1, 2, 3, 4, 5, 6};
	int size = 7;

	ft_rev_int_tab(tab, size);
	printf("%d, %d, %d, %d, %d, %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]); 
	return (0);
}	
*/
#include <stdio.h>
#include <stdlib.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int *tab;
	int counter;

	tab = calloc(10, sizeof(int));
	counter = 0;
	while (counter < 10)
	{
		tab[counter] = counter;
		counter++;
	}
	counter = 0;
	while (counter < 10)
	{
		printf("%d ", tab[counter]);
		counter++;
	}
	printf("\n");
	ft_rev_int_tab(tab, 10);
	counter = 0;
	while (counter < 10)
	{
		printf("%d ", tab[counter]);
		counter++;
	}
	printf("\n");
	return (0);
}