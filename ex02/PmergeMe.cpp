/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:54:55 by shamizi           #+#    #+#             */
/*   Updated: 2023/05/05 15:55:14 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge(std::vector<int>& vec, int l, int m, int r)
{
	int n1 = m - l +1;
	int n2 = r - m;
	std::vector<int> L(n1);
	std::vector<int> R (n2);

	for(int i = 0; i < n1; i++)
		L[i] = vec[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = vec[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			vec[k] = L[i];
			i++;
		}
		else
		{
			vec[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1)
	{
		vec[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		vec[k] = R[j];
		j++;
		k++;
	}
}

void mergeVec(std::vector<int>& vec, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeVec(vec, l, m);
		mergeVec(vec, m + 1, r);
		merge(vec, l, m, r);
	}
}
