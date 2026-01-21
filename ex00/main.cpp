/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:02:27 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/20 22:08:14 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	main.cpp should:	- test a heap zombie (from newZombie)
						- test a stack zombie (from randomChump)
						- show destructor timing to understand lifetime
*/

int main()
{
	// Test 1
	Zombie* heapZombie = newZombie("Brian");
	heapZombie->announce();
	delete heapZombie;

	// Test 2
	randomChump("Charlie");

	// Test 3
	Zombie* z1 = newZombie("ZombieOne");
	Zombie* z2 = newZombie("ZombieTwo");

	randomChump("TempZombie");

	z1->announce();
	z2->announce();

	delete z1;
	delete z2;
	return 0;
}