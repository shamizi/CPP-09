/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:58:13 by shamizi           #+#    #+#             */
/*   Updated: 2023/05/05 16:23:34 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

void merge(std::vector<int>& vec, int l, int m, int r);
void mergeVec(std::vector<int>& vec, int l, int r);
void mergeD(std::deque<int>& liste, int l, int m, int r);
void mergeDeque(std::deque<int>& liste, int l, int r);


#endif
