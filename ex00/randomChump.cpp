/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:27 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/23 11:10:26 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	Zombie z(name);				- is a direct initialization which doesn't make a copy (safer in C++98)
	Zombie z = Zombie(name);	- would have the same result theoretically, but it would make a copy
								- it creates a temporary Zombie object using the constructor Zombie("Bob"),
									but then it copy-initialies z from that temporary
	- Automatic allocation: This is a local variable, allocated on stack
							-> object lives only inside a scope <-
	- No need to call delete explicitly, the zombie is destroyed as soon as the function finishes
							-> automatically destroyed <-
							-> no memory management required <-
	- The function does not return the zombie because it does not survive after the function ends.
	
*/

void randomChump(std::string name)
{
	Zombie z(name);
	z.announce();
}