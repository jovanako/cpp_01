/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:16:34 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/22 20:42:53 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string type;
	
	public:		
		Weapon(const std::string& type);
		~Weapon();
		
		// getType() member function that returns a constant reference to type
		// first 'const' protects what you return (callers cannot modify 'type')
		// second 'const protects the object itself
		const std::string& getType() const;

		// setType() member function that sets 'type' using a new value passed as a parameter
		void setType(const std::string& newType);
};
#endif