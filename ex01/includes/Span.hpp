/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/12 09:27:44 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
#define __SPAN_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

class   Span {

private:

    std::vector<int>  _inventory;
    unsigned int      _N;

public:

    Span( void );
    Span( unsigned int N );
    Span( Span const & src );
    ~Span( void );

    Span    &operator=( Span const & rhs );

    void        addNumber( int const & number );
    int         shortestSpan( void ) const;
    int         longestSpan( void ) const;
    void        addNumberBulk( unsigned int nbOfIntToAdd, unsigned int randMax );

    std::vector<int>  &getInventory( void );
    unsigned int      getN(void ) const;

    class   SpanFullException : public std::exception {

        public:

            virtual const char *what() const throw()
            {
                return ("The Span is full");
            }
        
    };

    class NoDistanceAvailableException : public std::exception {
        
        public:

            virtual const char *what() const throw()
            {
                return ("No distance between stored numbers has be found");
            }
    };

};

#endif