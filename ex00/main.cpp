/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:02:27 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/21 10:49:39 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

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