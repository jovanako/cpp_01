/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:34 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/21 08:29:27 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/*	- This file declares the class.
	- private	-> data is hidden - 'name' is stored privately as a std::string
	- public	-> interface exposed to users
	- Functions are declared, not implemented
	- announce()	-> confirms that the Zombie was created correctly
					-> shows which Zombie is speaking
	- destructor	-> prints a message with a zombie's name
					-> shows when a zombie is destroyed
					-> shows where it is destroyed (end of scope vs manual deletion)
*/

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