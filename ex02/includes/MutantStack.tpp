/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:30:26 by debian            #+#    #+#             */
/*   Updated: 2024/12/12 03:16:16 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack( void )
{
    std::cout << "Default constructor (void) from MustantStack called" << std::endl;
    return ;
}

template <typename T>
MutantStack<T>::MutantStack( MutantStack const & src ) : std::stack<T>(src)
{
    std::cout << "Copy constructor from MustantStack called" << std::endl;
    (void)src;
    return ;
}

template <typename T>
MutantStack<T>::~MutantStack( void )
{
    std::cout << "Destructor from MustantStack called" << std::endl;
    return ;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=( MutantStack<T> const & rhs )
{
    std::cout << "Affectation operator from MustantStack called" << std::endl;
    this->c = rhs.c;
    return (*this);
}

template <typename T>
typename std::deque<T>::iterator   MutantStack<T>::begin( void )
{
    return (this->c.begin());
}

template <typename T>
typename std::deque<T>::iterator   MutantStack<T>::end( void )
{
    return (this->c.end());
}