/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:16:22 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/22 21:50:18 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "\n--- Test 1 ---\n";
		Weapon club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		bob.attack();
		
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << "\n--- Test 2 ---\n";
		Weapon club = Weapon("crude spiked club");
		
		HumanB jim("Jim");
		jim.attack();
		
		jim.setWeapon(club);
		jim.attack();
		
		club.setType("some other type of club");
		jim.attack();
	}
}