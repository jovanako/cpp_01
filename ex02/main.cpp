/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:37:27 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/21 11:11:23 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string     str = "HI THIS IS BRAIN";
    std::string*    stringPTR = &str;
    std::string&    stringREF = str;

	std::cout << "\n--- Printing memory addresses ---\n";
	std::cout << &str << " <- Memory address of str" << std::endl;
	std::cout << stringPTR << " <- Memory address held by stringPTR" << std::endl;
	std::cout << &stringREF << " <- Memory address held by stringREF" << std::endl;

	std::cout << "\n--- Printing values ---\n";
	std::cout << str << " <- Value of str" << std::endl;
	std::cout << *stringPTR << " <- Value pointed to by stringPTR" << std::endl;
	std::cout << stringREF << " <- Value pointed to by stringREF" << std::endl;
	return 0;
}