/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:30 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/23 11:20:08 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	new Zombie(name) creates a zombie by dynamic (heap) allocation
	- This function returns a pointer to the zombie
		-> because the zombie must survive after the function ends
	- The caller of the function is responsible for the destruction of the zombie
			-> object lives until you explicitly destroy it <-
			-> it survives function boundaries <-
			-> it can cause memory leaks if not destroyed where necessary <-
	- Important: 	any object created with 'new' must eventually 
					be destroyed with 'delete' to avoid a memory leak
*/

Zombie* newZombie(std::string name)
{
	Zombie* z = new Zombie(name);
	return z;
}