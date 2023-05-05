/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:48:34 by shamizi           #+#    #+#             */
/*   Updated: 2023/05/03 14:45:26 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : 2 arguments" << std::endl;
		return 1;
	}

	std::string input = argv[1];
	std::istringstream iss(input);
	std::stack<int> s;
	std::string token;

	while (iss >> token)
	{
		if (token == "+")
		{
			if (s.size() < 2)
			{
				std::cout << "Error : not enough number for + operator" << std::endl;
				return 1;
			}
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			s.push(op1 + op2);
		}
		else if (token == "-")
		{
			if (s.size() < 2)
			{
				std::cout << "Error : not enough number for - operator" << std::endl;
				return 1;
			}
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			s.push(op1 - op2);
		}
		else if (token == "*")
		{
			if (s.size() < 2)
			{
				std::cout << "Error : not enough number for * operator" << std::endl;
				return 1;
			}
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			s.push(op1 * op2);
		}
		else if (token == "/")
		{
			if (s.size() < 2)
			{
				std::cout << "Error : not enough number for / operator" << std::endl;
				return 1;
			}
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			if (op2 == 0)
			{
				std::cout << "Error : Division par 0" << std::endl;
				return 1;
			}
			s.pop();
			s.push(op1 / op2);
		}
		else
		{
			int num;
			try 
			{
				num = atoi(token.c_str());
			}
			catch (...)
			{
				std::cout << "Error : invalid token" << std::endl;
				return 1;
			}
			s.push(num);
		}
	}
	if (s.size() != 1)
	{
		std::cout << "Error : invalide expression" << std::endl;
		return 1;
	}
	std::cout << s.top() << std::endl;
	return 0;
}
