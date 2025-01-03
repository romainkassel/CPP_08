/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:25:40 by debian            #+#    #+#             */
/*   Updated: 2024/12/10 04:28:31 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	testDeque()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "DEQUE" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//////////////////////////////////////

	std::deque<int>::const_iterator	rvalue;

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Initialization of deque" << std::endl;
	std::cout << END;
	std::cout << std::endl;
	
	std::deque<int>	deque1(5, 42);

	deque1.push_back(78);
	deque1.push_back(97);
	deque1.push_back(42);
	deque1.push_back(21);
	deque1.push_back(98);

	::printContainer(deque1);
	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "easyfind(deque1, 42) -> should return 42" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(deque1, 42);
	::printRvalue<std::deque<int>::const_iterator>(rvalue, deque1.end());

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "easyfind(deque1, 98) -> should return 98" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(deque1, 98);
	::printRvalue<std::deque<int>::const_iterator>(rvalue, deque1.end());

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "easyfind(deque1, 36) -> should return deque1.end()" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(deque1, 36);
	::printRvalue<std::deque<int>::const_iterator>(rvalue, deque1.end());
	
	return ;
}