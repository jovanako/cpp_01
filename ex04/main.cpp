/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:01:02 by jkovacev          #+#    #+#             */
/*   Updated: 2026/03/02 20:51:27 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
	std::string outfileName;
	
	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	Replacer replacer(argv[1], argv[2], argv[3]);

	replacer.executeReplace();

	return 0;	
}