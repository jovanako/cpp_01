/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:30 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/20 21:56:22 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	This function creates a zombie, names it, and returns it so you can use it outside of the function scope
	- The function must return a pointer
	- The zombie must survive after the function ends -> must be allocated on the heap
	- The caller is responsible for deleting the zombie later to avoid memory leaks

	Zombie* z = new Zombie(name);	-> heap allocation
	
	- 'new' allocates Zombie on heap (dynamically)
	- initialization:	- you need to pass the name to the constructor when creating it
						- this ensures the member variable 'name' is set correctly
	- after creating the heap object, we return it, which lets the caller of newZombie use the zombie later
	- important: any object created with 'new' must eventually be destroyed with 'delete' to avoid a memory leak
	
	Memory:	- Heap	-> Zombie object lives here
			- Stack	-> pointer z point to it
*/

Zombie* newZombie(std::string name)
{
	Zombie* z = new Zombie(name);
	return z;
}