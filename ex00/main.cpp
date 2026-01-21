/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:02:27 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/21 09:59:22 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

/*	main.cpp should:	- test a heap zombie (from newZombie)
						- test a stack zombie (from randomChump)
						- show destructor timing to understand lifetime
	- Test 1: Heap allocation	->	create a zombie using newZombie
								->	call announce()
								->	delete it manually
								->	observe constructor and destructor messages
									(constructor message appears immediately after newZombie, destructor message only after 'delete')
	
	- Test 2: Stack allocation	->	call randomChump with a name
								->	the zombie announces itself inside the function
								->	destructor runs automatically at the end of the function
	
	- Test 3: Multiple zombies	->	create multiple zombies with both methods
								->	observe order of destructor calls
*/

int main()
{
	{
		std::cout << "\n--- Test 1: Heap allocation ---\n";
		
		Zombie* heapZombie = newZombie("Brian");
		heapZombie->announce();
		delete heapZombie;		
	}

	{
		std::cout << "\n--- Test 2: Stack allocation ---\n";

		randomChump("Charlie");		
	}

	{
		std::cout << "\n--- Test 3: Multiple zombies ---\n";
		
		Zombie* z1 = newZombie("ZombieOne");
		Zombie* z2 = newZombie("ZombieTwo");
	
		randomChump("TempZombie");
	
		z1->announce();
		z2->announce();
	
		delete z1;
		delete z2;		
	}
	return 0;
}