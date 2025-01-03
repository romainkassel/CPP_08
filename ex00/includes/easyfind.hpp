/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/10 04:27:46 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_H__
#define __EASYFIND_H__

// start colors

#define BOLD "\033[1;"
#define NORMAL "\033[0;"

#define MAGENTA "35m"
#define GREEN "32m"

#define END "\033[0m"

// end colors

#include <iostream>

#include <vector>
#include <deque>
#include <list>

#include <algorithm>

template <typename T>
typename T::const_iterator	easyfind( T const & container, int const & value );

template<typename T>
void	printContainer( T const & container );

template<typename T>
void	printRvalue( T const & rvalue, T const & last);

#include "easyfind.tpp"

#endif