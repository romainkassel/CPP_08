/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:25:40 by debian            #+#    #+#             */
/*   Updated: 2024/12/10 03:49:42 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	testVector()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "VECTOR" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//////////////////////////////////////

	std::vector<int>::const_iterator	rvalue;

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Initialization of vector" << std::endl;
	std::cout << END;
	std::cout << std::endl;
	
	std::vector<int>	vector1(5, 42);

	vector1.push_back(78);
	vector1.push_back(97);
	vector1.push_back(42);
	vector1.push_back(21);
	vector1.push_back(98);

	::printContainer(vector1);
	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "easyfind(vector1, 42) -> should return 42" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(vector1, 42);
	::printRvalue<std::vector<int>::const_iterator>(rvalue, vector1.end());

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "easyfind(vector1, 98) -> should return 98" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(vector1, 98);
	::printRvalue<std::vector<int>::const_iterator>(rvalue, vector1.end());

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "easyfind(vector1, 36) -> should return vector1.end()" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(vector1, 36);
	::printRvalue<std::vector<int>::const_iterator>(rvalue, vector1.end());
	
	return ;
}