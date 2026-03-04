/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:32 by jkovacev          #+#    #+#             */
/*   Updated: 2026/03/04 20:49:09 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor definition
Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

// Destructor definition
Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}