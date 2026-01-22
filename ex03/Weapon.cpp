/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:16:43 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/22 20:45:18 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
	return type;
}

void Weapon::setType(const std::string& newType) {
	type = newType;
}
