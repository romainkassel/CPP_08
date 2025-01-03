/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/12/12 09:39:07 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void )
{
	std::cout << "Default constructor (void) from Span called" << std::endl;
	return ;
}

Span::Span( unsigned int N ) : _N(N)
{
	std::cout << "Default constructor (unsigned int N) from Span called" << std::endl;
	this->_inventory.reserve(N);
	return ;
}

Span::Span( Span const & src )
{
	std::cout << "Copy constructor from Span called" << std::endl;
	*this = src;
	return ;
}

Span::~Span( void )
{
	std::cout << "Destructor from Span called" << std::endl;
	return ;
}

Span    &Span::operator=( Span const & rhs )
{
	std::cout << "Affectation operator from Span called" << std::endl;

	this->_N = rhs._N;

	std::vector<int>	tmpSpan( rhs._inventory );

	this->_inventory.swap(tmpSpan);
	
	return (*this);
}

void	Span::addNumber( int const & number )
{
	if (this->_inventory.size() >= this->_N)
	{
		Span::SpanFullException	SpanFullException;
		throw SpanFullException;
	}

	this->_inventory.push_back(number);
	
	return ;
}

int	Span::shortestSpan() const
{
	if (this->_inventory.size() <= 1)
	{
		Span::NoDistanceAvailableException	NoDistanceAvailableException;
		throw NoDistanceAvailableException;
	}

	std::vector<int>	tmpSpan;

	tmpSpan.assign(this->_inventory.begin(), this->_inventory.end());
	std::sort(tmpSpan.begin(), tmpSpan.end());

	int	shortestSpan = this->longestSpan();
	int	shortestSpanTmp = shortestSpan;

	std::vector<int>::const_iterator	it1;
	std::vector<int>::const_iterator	it2;
	std::vector<int>::const_iterator	ite = tmpSpan.end();

	for (it1 = tmpSpan.begin(); it1 !=ite; it1++)
	{
		for (it2 = tmpSpan.begin(); it2 != ite; it2++)
		{
			if (it2 < it1)
				shortestSpanTmp = *it1 - *it2;
			else if (it2 > it1)
				shortestSpanTmp = *it2 - *it1;

			if (shortestSpanTmp < shortestSpan)
				shortestSpan = shortestSpanTmp;
		}
	}

	return (shortestSpan);
}

int	Span::longestSpan() const
{
	if (this->_inventory.size() <= 1)
	{
		Span::NoDistanceAvailableException	NoDistanceAvailableException;
		throw NoDistanceAvailableException;
	}

	int	min = *(std::min_element(this->_inventory.begin(), this->_inventory.end()));
	int	max = *(std::max_element(this->_inventory.begin(), this->_inventory.end()));
	
	return (max - min);
}

std::vector<int>  &Span::getInventory( void )
{
	return (this->_inventory);
}

unsigned int	Span::getN( void ) const
{
	return (this->_N);
}

void	Span::addNumberBulk( unsigned int nbOfIntToAdd, unsigned int randMax )
{
	if (nbOfIntToAdd == 0)
		nbOfIntToAdd = this->_N;
	
	srand(time(NULL));
	
	this->_inventory.resize(nbOfIntToAdd);
	
	std::fill(this->_inventory.begin(), this->_inventory.begin()+nbOfIntToAdd, std::rand() % randMax);
		
	return ;
}

/*void	Span::addNumberBulk( unsigned int nbOfIntToAdd, unsigned int randMax )
{
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	ite;

	srand(time(NULL));
	
	if (nbOfIntToAdd == 0)
		ite = this->_inventory.begin() + this->_N;
	else
		ite = this->_inventory.begin() + nbOfIntToAdd;
	
	for (it = this->_inventory.begin(); it != ite; it++)
		this->addNumber(std::rand() % randMax);
	
	return ;
}*/