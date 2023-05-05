/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:15:12 by shamizi           #+#    #+#             */
/*   Updated: 2023/05/03 14:33:36 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>
#include <cstdlib>

int	checkdate(std::string & date)
{
	//std::cout << "date dans la fonction checkdate : " << date << std::endl;
	int year, month, day;
	std::string last;
	char delimiter1;
	char delimiter2;

	std::istringstream iss(date);
	if (iss >> year >> delimiter1 >> month >> delimiter2 >> day)
	{
		if(day > 31 || day <= 0 || month > 12 || month <= 0 || delimiter1 != '-'  || delimiter2 != '-' || !iss.eof())
			return 1;
	//	std::cout << "year : " << year << " month : " << month << " day : " << day << std::endl;
	}
	else
		return 1;
	return 0;
}

int	ft_check(char *str, std::map<std::string, double> csv)
{
	//(void)csv;
	std::string line;
	std::ifstream file(str);
	if (!file.is_open())
	{
		std::cout << "Error : couldn't open file" << std::endl;
		return 1;
	}

	while (std::getline(file, line))
	{
		std::string date;
		double quantity;
		char sep;
		std::istringstream iss(line);
		std::map<std::string, double>::iterator it;
		if (!(iss >> date >> sep >> quantity) || sep != '|' || iss.bad())
		{
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		if (quantity > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (quantity < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (checkdate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		it = csv.lower_bound(date);
		std::cout << date << " => " << quantity << " = "<< it->second * quantity << std::endl;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : file.txt" << std::endl;
		return 1;
	}

	std::ifstream file_csv("data.csv");
	if (!file_csv.is_open())
	{
		std::cout << "Error : couldn't open file .csv" << std::endl;
		return 1;
	}

	std::map<std::string, double> csv;
	std::string line;
	std::string date;
	std::string price_tmp;
	double price;
	while (std::getline(file_csv,line))
	{
		date = line.substr(0, line.find(","));
		price_tmp = line.substr(line.find(",") + 1, line.size());
		price = std::strtod(price_tmp.c_str(), NULL);
	//	std::cout << "date : " << date << " price : " << price << std::endl;
		csv[date] = price;
	//	std::cout << "csv[date] : " << csv[date] << std::endl;
	}

	////////////////////////////////////////
	//check file
	ft_check(argv[1], csv);
	return 0;
}
