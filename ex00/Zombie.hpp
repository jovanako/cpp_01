/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:34 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/21 10:55:31 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string name;
	
	public:
		// Constructor
		Zombie(std::string name);

		// Destructor
		~Zombie();

		// Member function
		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif