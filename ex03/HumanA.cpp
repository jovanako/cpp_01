/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:17:03 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/22 21:08:40 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string name, Weapon& weapon)
	: name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const {
	std::cout << name
			<< " attacks with their "
			<< weapon.getType()
			<< std::endl;
}