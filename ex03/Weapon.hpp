/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:16:34 by jkovacev          #+#    #+#             */
/*   Updated: 2026/02/05 19:17:58 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

/*	--- getType() --- member function that returns a constant reference to type
	- first 'const' protects what you return (callers cannot modify 'type')
	- second 'const' applies to the member function itself
		-> it means that this function does not modify the object
	- with both 'const's, the function does not modify the object,
		and it returns a read-only reference to the weapon type

	--- setType() --- member function that sets 'type' using a new value passed as a parameter
*/


class Weapon
{
	private:
		std::string _type;
	
	public:		
		Weapon(const std::string& type);
		~Weapon();
		
		const std::string& getType() const;

		void setType(const std::string& newType);
};
#endif