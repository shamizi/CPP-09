/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:22 by shamizi           #+#    #+#             */
/*   Updated: 2023/05/02 14:15:03 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : file.txt" << std::endl;
		return 1;
	}

	//meme chose avec les donner du .csv | je pars du principe que cette base de donner n'est pas modifiable
	std::ifstream file2("data.csv");
	if (!file2.is_open())
	{
		std::cout << "Error : couldn't open file .csv" << std::endl;
		return 1;
	}

	std::map<std::string, double> csv;
	std::map<std::string, double>::iterator it;
	std::string line2;
	double price2;
	std::string date2;
	std::string tmp;
	while (std::getline(file2, line2))
	{

		date2 = line2.substr(0, line2.find(","));
		tmp = line2.substr(line2.find(",") + 1, line2.size());
		price2 = std::strtod(tmp.c_str(), NULL);
		csv[date2] = price2;
	}

	//verifier si on peut ouvrir le fichier avec std::ifstream
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Error : couldn't open file" << std::endl;
		return 1;
	}
	std::map<std::string, double> map;
	std::string line;
	//parcourir le fichier avec std::getline
	while (std::getline(file, line))
	{
		//std::istringstream va permettre de diviser la ligne comme ft_split
		std::string date;
		double price;
		char sep;
		std::istringstream iss(line);
		if (!(iss >> date >> sep >> price) || sep != '|' || iss.bad())
		{
			std::cout << " Error : bad input" << std::endl;
			continue
		}
		//check si le prix est bien entre 0 et 1000;
		if (price > 1000 || price < 0)
		{
			std::cout << "Error : incorrect price" << std::endl;
			continue
		}
		map[date] = price;
		it = csv.find(date);
		if (it != csv.end())
		{
			int res = price * price2;
			std::cout << date << " => " << price << " = " << res << std::endl; 
		}
		else if (it = )
		else
			std::cout << "Error: couldn't find this date => " << date << std::endl;
	}
return 0;
}
