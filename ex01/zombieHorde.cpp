/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:25:40 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/21 09:37:34 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	This function should:
	1. Allocate N Zombie objects in one single allocation
	2. Give each Zombie the same name
	3. Return a pointer to the first Zombie
	4. Allow the caller to later call announce() on each Zombie
	5. Be properly cleaned up with delete[]

	"Single allocation" - what this really means (the most important concept of the exercise)
	Zombie* horde = new Zombie[N];
	This:	-	Allocates one block of memory
			-	Holds N Zombies contiguously
			-	Must be freed using: delete[] horde;
	
	Initializing each Zombie:
	- After allocating the array, the Zombies exist but may not have names yet
	- You must loop through them and use setName()
	- Why?	->	Constructors with parameters cannot be easily used with 'new'
			->	So you create them first, then assign values
	
	Returning the pointer:
	- When you return 'return horde;' you are returning:
			->	A pointer to the first Zombie
			->The caller can access others using indexing: horde[0], horde[1], horde[2]...
*/

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}