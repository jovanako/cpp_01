/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:04:27 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/20 21:57:21 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	This function creates a zombie, names it, and makes it announce itself immediately
	- the function does not return anything
	- the zombie only needs to exist inside the function
	- the zombie should announce itself before the function ends
	- after the function ends, the zombie is automatically destroyed

	- this zombie does not need to survive outside the function, which means you can create it as a local variable on the stack
	
	Zombie z(name);	-> stack allocation
	
	- no 'new' is needed - the compiler automatically calls the destructor when the function ends
*/

void randomChump(std::string name)
{
	Zombie z(name);
	z.announce();
}