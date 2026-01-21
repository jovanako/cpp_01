/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:25:30 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/21 09:23:27 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

/*	Contains the implementation of the Zombie class:
		->	Constructor definition
		->	Destructor definition
		->	announce() implementation
*/

// The constructor definition for the Zombie class
Zombie::Zombie() {}

//The destructor definition of the Zombie class
Zombie::~Zombie() {}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}