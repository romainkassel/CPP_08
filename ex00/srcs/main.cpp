/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/12/10 04:28:52 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Sources:

o Behavior of find function: https://cplusplus.com/reference/algorithm/find/
o Standard Containers: https://cplusplus.com/reference/stl/

*/

#include "easyfind.hpp"
#include <iostream>

void	testVector();
void	testDeque();
void	testList();

int	main( void )
{	
	testVector();
	testDeque();
	testList();

	std::cout << std::endl;
	
	return (0);
}


