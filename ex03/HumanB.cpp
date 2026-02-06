/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:17:22 by jkovacev          #+#    #+#             */
/*   Updated: 2026/02/05 19:18:49 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
	: _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack() const
{
	if (_weapon)
	{
		std::cout << _name
				<< " attacks with their "
				<< _weapon->getType()
				<< std::endl;
	}
	else
	{
		std::cout << _name
				<< " attacks with their bare hands"
				<< std::endl;
	}
}