/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:34 by jkovacev          #+#    #+#             */
/*   Updated: 2026/03/04 20:44:41 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

// Declaration of the class
class Zombie
{
	private:
		std::string _name;
	
	public:
		Zombie(std::string name);

		~Zombie();

		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif