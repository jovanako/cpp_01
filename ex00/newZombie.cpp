/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:30 by jkovacev          #+#    #+#             */
/*   Updated: 2026/03/04 21:17:23 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	new Zombie(name) creates a zombie by dynamic (heap) allocation
	-	returns a pointer to the zombie because the zombie must 
		survive after the function ends
	-	the caller of the function must delete the zombie
	-	the zombie survives until it is explicitly destroyed
	-	any object created with 'new' must eventually be destroyed
		with 'delete' to avoid a memory leak
*/

Zombie* newZombie(std::string name)
{
	Zombie* z = new Zombie(name);
	return z;
}