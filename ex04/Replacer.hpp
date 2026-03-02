/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:08:18 by jkovacev          #+#    #+#             */
/*   Updated: 2026/03/02 20:32:15 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>
#include <iostream>

class Replacer
{
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;
	
	public:
		// Constructor: Takes the initial arguments
		Replacer(std::string filename, std::string s1, std::string s2);

		~Replacer();

		// The method that does the work
		void executeReplace();
};

#endif