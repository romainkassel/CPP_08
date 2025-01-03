/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/12/12 09:38:56 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

// start colors

#define BOLD "\033[1;"
#define NORMAL "\033[0;"

#define MAGENTA "35m"
#define GREEN "32m"

#define END "\033[0m"

// end colors

// Test functions

void	displayContainer( std::vector<int> container );
void	testBigSpan( void );
void	testSubjectMain( void );
void	testSpanCopyByAffectationIncrease( void );
void	testSpanCopyByAffectationDecrease( void );
void	testConstructorByCopy(Span span1);
void	testSpanCopyByConstructor( void );

int	main( void )
{	
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Creation of a span instance (vector, N = 5)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	////////////////////////////////////
	
	Span	span1(5);

	std::cout << std::endl;

	std::cout << "Capacity: " << span1.getInventory().capacity() << "\t";
	std::cout << "Size: " << span1.getInventory().size() << "\t" << "\t";
	std::cout << "N: " << span1.getN() << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "addNumber" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	try
	{
		std::cout << std::endl;
		std::cout << NORMAL << MAGENTA;
		std::cout << "addNumber(42)" << std::endl;
		std::cout << END;
		std::cout << std::endl;
		span1.addNumber(42);
		displayContainer(span1.getInventory());

		std::cout << std::endl;
		std::cout << NORMAL << MAGENTA;
		std::cout << "addNumber(21)" << std::endl;
		std::cout << END;
		std::cout << std::endl;
		span1.addNumber(21);
		displayContainer(span1.getInventory());

		std::cout << std::endl;
		std::cout << NORMAL << MAGENTA;
		std::cout << "addNumber(84)" << std::endl;
		std::cout << END;
		std::cout << std::endl;
		span1.addNumber(84);
		displayContainer(span1.getInventory());

		std::cout << std::endl;
		std::cout << NORMAL << MAGENTA;
		std::cout << "addNumber(7)" << std::endl;
		std::cout << END;
		std::cout << std::endl;
		span1.addNumber(7);
		displayContainer(span1.getInventory());

		std::cout << std::endl;
		std::cout << NORMAL << MAGENTA;
		std::cout << "addNumber(7)" << std::endl;
		std::cout << END;
		std::cout << std::endl;
		span1.addNumber(7);
		displayContainer(span1.getInventory());

		std::cout << std::endl;
		std::cout << NORMAL << MAGENTA;
		std::cout << "addNumber(168) -> MUST throw an exception" << std::endl;
		std::cout << END;
		std::cout << std::endl;
		span1.addNumber(168);
		displayContainer(span1.getInventory());
	}
	catch (std::exception & e)
	{
		std::cout << "Can't add another number because " << e.what() << std::endl;
	}

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Creation of span instances in order to prepare shortestSpan & longestSpan tests" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	std::cout << std::endl;

	Span	span2(0);

	std::cout << std::endl;

	Span	span3(1);

	std::cout << std::endl;

	span3.addNumber(42);

	Span	span4(2);

	std::cout << std::endl;

	span4.addNumber(84);
	span4.addNumber(42);

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "shortestSpan" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Container content before shortestSpan call" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span1.getInventory());

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "shortestSpan call, should return 0" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	try
	{
		std::cout << "shortestSpan span is: " << span1.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Can't call shortestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Container content after shortestSpan call" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span1.getInventory());

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Replacing one 7 by 8" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "BEFORE ";
	displayContainer(span1.getInventory());
	
	span1.getInventory().pop_back();
	span1.addNumber(8);
	
	std::cout << "AFTER ";
	displayContainer(span1.getInventory());

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "shortestSpan call, should return 1" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span1.getInventory());

	try
	{
		std::cout << "shortestSpan span is: " << span1.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Can't call shortestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "shortestSpan call on an empty container -> should throw an exception" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span2.getInventory());

	std::cout << std::endl;

	try
	{
		std::cout << "shortestSpan span is: " << span2.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << std::endl;
		std::cout << "Can't call shortestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "shortestSpan call on a container with only one int -> should throw an exception" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span3.getInventory());

	std::cout << std::endl;

	try
	{
		std::cout << "shortestSpan span is: " << span3.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << std::endl;
		std::cout << "Can't call shortestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "shortestSpan call on a container with 2 int -> should NOT throw an exception" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span4.getInventory());

	std::cout << std::endl;

	try
	{
		std::cout << "shortestSpan span is: " << span4.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << std::endl;
		std::cout << "Can't call shortestSpan because " << e.what() << std::endl;
	}

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "longestSpan" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Container content before longestSpan call" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span1.getInventory());

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "longestSpan call, should return 77" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	try
	{
		std::cout << "longestSpan span is: " << span1.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Can't call longestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Container content after longestSpan call" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span1.getInventory());

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "longestSpan call on an empty container -> should throw an exception" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span2.getInventory());

	std::cout << std::endl;

	try
	{
		std::cout << "longestSpan span is: " << span2.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << std::endl;
		std::cout << "Can't call longestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "longestSpan call on a container with only one int -> should throw an exception" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span3.getInventory());

	std::cout << std::endl;

	try
	{
		std::cout << "longestSpan span is: " << span3.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << std::endl;
		std::cout << "Can't call longestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "longestSpan call on a container with 2 int -> should NOT throw an exception" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	displayContainer(span4.getInventory());

	std::cout << std::endl;

	try
	{
		std::cout << "longestSpan span is: " << span4.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << std::endl;
		std::cout << "Can't call longestSpan because " << e.what() << std::endl;
	}
	
	//testBigSpan();
	testSubjectMain();
	testSpanCopyByAffectationIncrease();
	testSpanCopyByAffectationDecrease();
	testSpanCopyByConstructor();

	std::cout << std::endl;
	
	return (0);
}

void	testBigSpan( void )
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Adding numbers in bulk" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creating a spawn instance with N = 10" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	Span	span5(10);

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "addNumberBulk(0, 100)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "BEFORE ";
	displayContainer(span5.getInventory());
	
	span5.addNumberBulk(0, 100);
	
	std::cout << "AFTER ";
	displayContainer(span5.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creating a spawn instance with N = 10" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	Span	span6(10);

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "addNumberBulk(5, 1000)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "BEFORE ";
	displayContainer(span6.getInventory());
	
	span6.addNumberBulk(5, 1000);
	
	std::cout << "AFTER ";
	displayContainer(span6.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Span with 15 000 numbers" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creating a spawn instance with N = 15000" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	Span	span1(15000);

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "addNumberBulk(0, 15000)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "span1 -> Capacity: " << span1.getInventory().capacity() << "\t";
	std::cout << "span1-> Size: " << span1.getInventory().size() << "\t";
	std::cout << "span1 -> N: " << span1.getN() << std::endl;

	std::cout << std::endl;

	std::cout << "BEFORE ";
	displayContainer(span1.getInventory());
	std::cout << std::endl;
	
	span1.addNumberBulk(0, 15000);
	
	std::cout << "AFTER " << std::endl;
	std::cout << std::endl;
	displayContainer(span1.getInventory());

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "shortestSpan call" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	try
	{
		std::cout << "shortestSpan span is: " << span1.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Can't call shortestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "longestSpan call" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	try
	{
		std::cout << "longestSpan span is: " << span1.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Can't call longestSpan because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	return ;
}

void	testSubjectMain( void )
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Subject main" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;
	
	Span sp = Span(5);

	std::cout << std::endl;
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	return ;
}

void	displayContainer( std::vector<int> container )
{
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	ite = container.end();
	
	std::cout << "Container: ";
	
	for (it = container.begin(); it != ite; it++)
	{
		if (it != container.begin())
			std::cout << ", ";
		std::cout << *it;
	}

	std::cout << std::endl;

	return ;
}

void    testSpanCopyByAffectationDecrease()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test span copy by affectation (from span2 with N = 15 to span1 with N = 10)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a span instance (that will be copied with N = 10)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	Span	span1(10);

	std::cout << std::endl;

	std::cout << "span1 -> Capacity: " << span1.getInventory().capacity() << "\t";
	std::cout << "span1-> Size: " << span1.getInventory().size() << "\t";
	std::cout << "span1 -> N: " << span1.getN() << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this span with 10 random numbers" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	span1.addNumberBulk(0, 100);

	displayContainer(span1.getInventory());

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a span instance (copy with N = 15)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	Span	span2(15);

	std::cout << std::endl;

	std::cout << "span2 -> Capacity: " << span2.getInventory().capacity() << "\t";
	std::cout << "span2-> Size: " << span2.getInventory().size() << "\t";
	std::cout << "span2 -> N: " << span2.getN() << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this span with 15 random numbers" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	span2.addNumberBulk(0, 100);

	displayContainer(span2.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Affecting span1 to span2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	span2 = span1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Span2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "span2 -> Capacity: " << span2.getInventory().capacity() << "\t";
	std::cout << "span2-> Size: " << span2.getInventory().size() << "\t";
	std::cout << "span2 -> N: " << span2.getN() << std::endl;
	std::cout << std::endl;
	displayContainer(span2.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Span1 original after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "span1 -> Capacity: " << span1.getInventory().capacity() << "\t";
	std::cout << "span1-> Size: " << span1.getInventory().size() << "\t";
	std::cout << "span1 -> N: " << span1.getN() << std::endl;
	std::cout << std::endl;
	displayContainer(span1.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Replacing last number from span2 (should not affect span1)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	span2.getInventory().pop_back();
	span2.addNumber(42);
	
	std::cout << "span2 copy after: ";
	displayContainer(span2.getInventory());
	
	std::cout << "span1 orig after: ";
	displayContainer(span1.getInventory());

	std::cout << std::endl;
    
    return ;
}

void    testSpanCopyByAffectationIncrease()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test span copy by affectation (from empty span2 to span1 with N = 10)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a span instance (that will be copied with N = 10)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	Span	span1(10);

	std::cout << std::endl;

	std::cout << "span1 -> Capacity: " << span1.getInventory().capacity() << "\t";
	std::cout << "span1-> Size: " << span1.getInventory().size() << "\t";
	std::cout << "span1 -> N: " << span1.getN() << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this span with 10 random numbers" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	span1.addNumberBulk(0, 100);

	displayContainer(span1.getInventory());

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a span instance (empty)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	Span	span2(0);

	std::cout << std::endl;

	std::cout << "span2 -> Capacity: " << span2.getInventory().capacity() << "\t";
	std::cout << "span2-> Size: " << span2.getInventory().size() << "\t";
	std::cout << "span2 -> N: " << span2.getN() << std::endl;

	std::cout << std::endl;

	displayContainer(span2.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Affecting span1 to span2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	span2 = span1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Span2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "span2 -> Capacity: " << span2.getInventory().capacity() << "\t";
	std::cout << "span2-> Size: " << span2.getInventory().size() << "\t";
	std::cout << "span2 -> N: " << span2.getN() << std::endl;
	std::cout << std::endl;
	displayContainer(span2.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Span1 original after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "span1 -> Capacity: " << span1.getInventory().capacity() << "\t";
	std::cout << "span1-> Size: " << span1.getInventory().size() << "\t";
	std::cout << "span1 -> N: " << span1.getN() << std::endl;
	std::cout << std::endl;
	displayContainer(span1.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Replacing last number from span2 (should not affect span1)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	span2.getInventory().pop_back();
	span2.addNumber(42);
	
	std::cout << "span2 copy after: ";
	displayContainer(span2.getInventory());
	
	std::cout << "span1 orig after: ";
	displayContainer(span1.getInventory());

	std::cout << std::endl;
    
    return ;
}

void    testSpanCopyByConstructor()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test copy by constructor" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a span instance (that will be copied with N = 10)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	Span	span1(10);

	std::cout << std::endl;

	std::cout << "span1 -> Capacity: " << span1.getInventory().capacity() << "\t";
	std::cout << "span1-> Size: " << span1.getInventory().size() << "\t";
	std::cout << "span1 -> N: " << span1.getN() << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this span with 10 random numbers" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	span1.addNumberBulk(0, 100);

	displayContainer(span1.getInventory());

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Calling copy by constructor operator" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	testConstructorByCopy(span1);

	std::cout << std::endl;
    
    return ;
}

void	testConstructorByCopy(Span span1)
{
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Copy after" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << "span1 -> Capacity: " << span1.getInventory().capacity() << "\t";
	std::cout << "span1-> Size: " << span1.getInventory().size() << "\t";
	std::cout << "span1 -> N: " << span1.getN() << std::endl;

	std::cout << std::endl;
	
	displayContainer(span1.getInventory());

	std::cout << std::endl;
	
	return ;
}
