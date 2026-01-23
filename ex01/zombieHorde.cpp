/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:25:40 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/23 18:52:12 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	->	Allocate N zombie objects in one single allocation 'new Zombie[N]'
	->	Give each zombie the same name
	->	Return a pointer to the first zombie
	->	Be properly cleaned up with delete[]

	->	Single allocation allocates one block of memory
	->	Why use setName()?
			-> Because constructors with parameters cannot be easily used with 'new'.
				So you can create them first, then assign values.
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