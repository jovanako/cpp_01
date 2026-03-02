/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:52:08 by jkovacev          #+#    #+#             */
/*   Updated: 2026/03/02 20:23:31 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <fstream>
#include <sstream>

// Constructor with an initialization list
Replacer::Replacer(std::string filename, std::string s1, std::string s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Replacer::~Replacer() {}

void Replacer::executeReplace()
{
	// Open the input file
	std::ifstream infile(_filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Could not open file '" << _filename << "'!" << std::endl;
		return;
	}

	// Read file into a string:
	std::stringstream buffer; // Create a stringstream
	buffer << infile.rdbuf(); // Pipe the entire file buffer into the stringstream
	std::string fileContent = buffer.str(); // Convert the stringstream into a standard string
	infile.close();

	// Open the output file
	std::string outfileName = _filename + ".replace";
	std::ofstream outfile(outfileName.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		return;
	}
	
	// The replacement logic
	if (_s1.empty())
	{
		outfile << fileContent;
		return;
	}

	std::string	result;
	size_t		i = 0;
	size_t pos = fileContent.find(_s1, i);
	size_t s1_len = _s1.length();

	while (pos != std::string::npos)
	{
		result.append(fileContent, i, pos - i);
		result.append(_s2);
		i = pos + s1_len;
		pos = fileContent.find(_s1, i);
	}

	result.append(fileContent, i, std::string::npos); // append everything left over after the final match
	outfile << result; // put the string into the outfile
	outfile.close();
}