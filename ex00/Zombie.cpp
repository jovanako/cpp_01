/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:32 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/20 21:21:47 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

/*	1. The constructor definition for the Zombie class
	Zombie::Zombie		-> scope resolution operator - tells the compiler this is the 'Zombie' class's constructor
	(std::string name)	-> constructor parameter - the caller must pass a string (e.g., "Brian") when creating a 'Zombie'
	: name(name)		-> member initializer list	- initializes the private member variable 'name' with the parameter 'name'
													- tells C++: before running the constructor body, initialize these member variables with these values
	std::cout			-> standard output stream
	std::endl			-> ends the line with newline and flushes the output buffer
	
	Why we write here: helps debug the object lifetime and shows exactly when the constructor runs

	2. The destructor definition for the Zombie class
	-	It runs automatically when a Zombie object is destroyed
	-	Important points in C++98:	-	Called automatically for stack objects when they go out of scope
									-	Called manually for heap objects when you 'delete' them
	
	Why we write here: lets you see object lifetimes and helps distinguish stack vs heap objects in debugging

	3. A member function of the Zombie class
	Zombie::announce	-> scope resolution, this function belongs to Zombie
*/

// The constructor definition for the Zombie class

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie " << this->name << " created" << std::endl;
}

// The destructor definition for the Zombie class

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}