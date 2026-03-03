/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 21:22:24 by jkovacev          #+#    #+#             */
/*   Updated: 2026/03/03 22:02:14 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return 1;
	}
	
	Harl harl;

	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	int level_index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == argv[1])
		{
			level_index = i;
			break;
		}
	}
	
	harl.status(level_index);
	
	return 0;
}