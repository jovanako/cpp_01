/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:30:33 by jkovacev          #+#    #+#             */
/*   Updated: 2026/03/03 21:17:57 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl; 
	std::cout
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl; 
	std::cout
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}	

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
		<< std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl; 
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(std::string level)
{
	static void (Harl::*complaints[])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return;
		}
	}
	std::cerr << "Error: invalid level '" << level << "'" << std::endl;
}