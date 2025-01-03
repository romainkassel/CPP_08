/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:25:40 by debian            #+#    #+#             */
/*   Updated: 2024/12/10 03:50:10 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	testList()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "LIST" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//////////////////////////////////////

	std::list<int>::const_iterator	rvalue;

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Initialization of list" << std::endl;
	std::cout << END;
	std::cout << std::endl;
	
	std::list<int>	lst1(5, 42);

	lst1.push_back(78);
	lst1.push_back(97);
	lst1.push_back(42);
	lst1.push_back(21);
	lst1.push_back(98);

	::printContainer(lst1);
	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "easyfind(lst1, 42) -> should return 42" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(lst1, 42);
	::printRvalue<std::list<int>::const_iterator>(rvalue, lst1.end());

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "easyfind(lst1, 98) -> should return 98" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(lst1, 98);
	::printRvalue<std::list<int>::const_iterator>(rvalue, lst1.end());

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "easyfind(lst1, 36) -> should return lst1.end()" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rvalue = ::easyfind(lst1, 36);
	::printRvalue<std::list<int>::const_iterator>(rvalue, lst1.end());
	
	return ;
}