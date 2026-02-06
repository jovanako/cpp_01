/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:17:15 by jkovacev          #+#    #+#             */
/*   Updated: 2026/02/05 19:18:27 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;
		
	public:
		HumanB(const std::string& name);		
		~HumanB();
		
		void setWeapon(Weapon& weapon);
		void attack() const;
};
#endif