/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:25:13 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/23 18:55:30 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "\n--- Test 1: Horde of 5 ---\n";
		int N = 5;
		Zombie* horde = zombieHorde(N, "Bill");
	
		for (int i = 0; i < N; i++)
			horde[i].announce();	
		delete[] horde;		
	}

	{
		std::cout << "\n--- Test 2: Single Zombie ---\n";
		Zombie* horde = zombieHorde(1, "Solo");
		horde[0].announce();
		delete[] horde;		
	}

	{
		std::cout << "\n--- Test 3: Multiple hordes ---\n";
		Zombie* horde1 = zombieHorde(3, "Jane");
		Zombie* horde2 = zombieHorde(2, "Ben");
	
		for (int i = 0; i < 3; i++)
			horde1[i].announce();
		for (int i = 0; i < 2; i++)
			horde2[i].announce();	
		delete[] horde1;
		delete[] horde2;		
	}
	
	{
		std::cout << "\n--- Test 4: Zero Zombies (edge case) ---\n";
		Zombie* horde = zombieHorde(0, "Nobody");
		delete[] horde;		
	}

	{
		std::cout << "\n--- Test 5: Large horde (stress test) ---\n";
		Zombie* horde = zombieHorde(1000, "Thousand");
		for (int i = 0; i < 5; i++)
			horde[i].announce();
		delete[] horde;		
	}
}