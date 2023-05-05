/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:10:19 by shamizi           #+#    #+#             */
/*   Updated: 2023/05/05 16:30:20 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;
	int n;

	if (argc < 2)
	{
		std::cout << "Too few arguments" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		n = atoi(argv[i]);
		if (n < 0)
		{
			std::cout << "Error: negative number" << std::endl;
			return 1;
		}
		vec.push_back(n);
		deq.push_back(n);
	}

	std::cout << "Before:  ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	clock_t start = clock();
	mergeVec(vec, 0, vec.size() - 1);
	clock_t end = clock() - start;

	std::cout << "After:   ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of   " << vec.size() << " elements with std::vector : " << ((double)end / CLOCKS_PER_SEC) * 1000000 << " nanoseconde" << std::endl;

	clock_t start2 = clock();
	mergeDeque(deq, 0, deq.size() - 1);
	clock_t end2 = clock() - start2;

	std::cout << "Time to process a range of   " << deq.size() << " elements with std::deque : " << ((double)end2 / CLOCKS_PER_SEC) * 1000000 << " nanoseconde" << std::endl;

	return 0;
}
