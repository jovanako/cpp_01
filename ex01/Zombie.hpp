/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:25:23 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/21 09:02:20 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/*	Contains the class declaration:
	->	Class name: Zombie
	->	Private member: std::string name
	->	Public methods:	- Constructor(s)
						- announce()
						- Possibly a setName() function
	This file tells the compiler what a Zombie is
*/

class Zombie
{
	private:
		std::string name;
	public:
		// Constructor
		Zombie();

		// Destructor
		~Zombie();

		// Member function
		void setName(std::string name);
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif