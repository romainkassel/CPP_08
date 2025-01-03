/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/12 03:26:37 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    
public:

    MutantStack( void );
    MutantStack( MutantStack const & src );
    ~MutantStack( void );

    MutantStack    &operator=( MutantStack const & rhs );
    
    typedef typename std::deque<T>::iterator iterator;

    iterator    begin( void );
    iterator    end( void );

};

#include "MutantStack.tpp"

#endif