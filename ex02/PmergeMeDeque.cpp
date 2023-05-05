/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:55:26 by shamizi           #+#    #+#             */
/*   Updated: 2023/05/05 16:20:41 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void mergeD(std::deque<int>& liste, int l, int m, int r)
{
	int n1 = m - l +1;
	int n2 = r - m;
	std::deque<int> L(n1);
	std::deque<int> R(n2);

	for(int i = 0; i < n1; i++)
		L[i] = liste[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = liste[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			liste[k] = L[i];
			i++;
		}
		else
		{
			liste[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1)
	{
		liste[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		liste[k] = R[j];
		j++;
		k++;
	}
}

void mergeDeque(std::deque<int>& liste, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeDeque(liste, l, m);
		mergeDeque(liste, m + 1, r);
		mergeD(liste, l, m, r);
	}
}
