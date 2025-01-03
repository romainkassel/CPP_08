/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/12/12 03:33:37 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Sources:

o stack header: https://en.cppreference.com/w/cpp/header/stack
o deque header: https://en.cppreference.com/w/cpp/header/deque
o typedef, kezako? https://www.geeksforgeeks.org/typedef-in-cpp/

*/

#include "MutantStack.hpp"

// start colors

#define BOLD "\033[1;"
#define NORMAL "\033[0;"

#define MAGENTA "35m"
#define GREEN "32m"

#define END "\033[0m"

// end colors

// Test functions

void	testSubjectMain( void );
void	testMutantStackCopyByAffectationFilled( void );
void	testMutantStackCopyByAffectationEmpty( void );
void	testConstructorByCopy(MutantStack <int>mstack);
void	testMutantStackCopyByConstructor( void );

int main()
{	
	testSubjectMain();
	testMutantStackCopyByAffectationFilled();
	testMutantStackCopyByAffectationEmpty();
	testMutantStackCopyByConstructor();
	
	return 0;
}

void	testSubjectMain( void )
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test subject main" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////

	std::cout << std::endl;
	MutantStack<int>	mstack;
	std::cout << std::endl;
	std::deque<int>		deque;	// custom 
	
	/////////////////////////////////////////
	
	mstack.push(5);
	mstack.push(17);

	deque.push_back(5); // custom
	deque.push_back(17); // custom
	
	/////////////////////////////////////////
	
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	std::cout << "deque.back(): " << deque.back() << std::endl; // custom
	std::cout << std::endl;
	
	mstack.pop();
	deque.pop_back();	// custom
	
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << "deque.size(): " << deque.size() << std::endl;	// custom
	std::cout << std::endl;

	/////////////////////////////////////////
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	deque.push_back(3);	// custom
	deque.push_back(5);	// custom
	deque.push_back(737);	// custom
	deque.push_back(0);	// custom

	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << "deque.size(): " << deque.size() << std::endl;	// custom
	std::cout << std::endl;

	/////////////////////////////////////////
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::deque<int>::iterator itDeque = deque.begin();	// custom
	std::deque<int>::iterator iteDeque = deque.end();	// custom

	/////////////////////////////////////////
	
	++it;
	--it;
	std::cout << "Looping mstack: ";
	while (it != ite)
	{
		if (it != mstack.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	std::cout << "Looping deque: ";
	++itDeque;	// custom
	--itDeque;	// custom
	while (itDeque != iteDeque)	// custom
	{	// custom
		if (itDeque != deque.begin()) // custom
			std::cout << ", "; // custom
		std::cout << *itDeque;	// custom
		++itDeque;	// custom
	}
	std::cout << std::endl;
	
	std::cout << std::endl;

	/////////////////////////////////////////
	
	std::stack<int> s(mstack);
	std::deque<int> w(deque);	// custom

	/////////////////////////////////////////
	
	s.push(5);
	s.push(17);

	w.push_back(5); // custom
	w.push_back(17); // custom
	
	/////////////////////////////////////////
	
	std::cout << "s.top(): " << s.top() << std::endl;
	std::cout << "w.back(): " << w.back() << std::endl; // custom
	std::cout << std::endl;
	
	s.pop();
	w.pop_back();	// custom
	
	std::cout << "s.size(): " << s.size() << std::endl;
	std::cout << "w.size(): " << w.size() << std::endl;	// custom
	std::cout << std::endl;

	/////////////////////////////////////////
	
	s.push(3);
	s.push(5);
	s.push(737);
	s.push(0);

	w.push_back(3);	// custom
	w.push_back(5);	// custom
	w.push_back(737);	// custom
	w.push_back(0);	// custom

	std::cout << "s.size(): " << s.size() << std::endl;
	std::cout << "w.size(): " << w.size() << std::endl;	// custom
	std::cout << std::endl;

	return ;
}

void    testMutantStackCopyByAffectationFilled()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test MutantStack copy by affectation (from filled to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a MutantStack instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	MutantStack<int>	mstack1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this stack with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	mstack1.push(45);
	mstack1.push(87);
	mstack1.push(43);
	mstack1.push(90);
	mstack1.push(654);

	MutantStack<int>::iterator it = mstack1.begin();
	MutantStack<int>::iterator ite = mstack1.end();

	while (it != ite)
	{
		if (it != mstack1.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a MutantStack instance (copy)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	MutantStack<int>	mstack2;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this stack with 10 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	mstack2.push(765);
	mstack2.push(9);
	mstack2.push(432);
	mstack2.push(98);
	mstack2.push(43);
	mstack2.push(765);
	mstack2.push(9);
	mstack2.push(432);
	mstack2.push(98);
	mstack2.push(43);

	it = mstack2.begin();
	ite = mstack2.end();

	while (it != ite)
	{
		if (it != mstack2.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Affecting mstack1 to mstack2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	mstack2 = mstack1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "mstack2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	it = mstack2.begin();
	ite = mstack2.end();

	while (it != ite)
	{
		if (it != mstack2.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Replacing last number from mstack2 (should not affect mstack1)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	mstack2.pop();
	mstack2.push(789);
	
	std::cout << "mstack2 copy after: ";
	it = mstack2.begin();
	ite = mstack2.end();

	while (it != ite)
	{
		if (it != mstack2.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
	
	std::cout << "mstack1 orig after: ";
	it = mstack1.begin();
	ite = mstack1.end();

	while (it != ite)
	{
		if (it != mstack1.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Replacing last number from mstack1 (should not affect mstack2)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	mstack1.pop();
	mstack1.push(23);
	
	std::cout << "mstack2 copy after: ";
	it = mstack2.begin();
	ite = mstack2.end();

	while (it != ite)
	{
		if (it != mstack2.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
	
	std::cout << "mstack1 orig after: ";
	it = mstack1.begin();
	ite = mstack1.end();

	while (it != ite)
	{
		if (it != mstack1.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	std::cout << std::endl;
    
    return ;
}

void    testMutantStackCopyByAffectationEmpty()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test MutantStack copy by affectation (from empty to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a MutantStack instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	MutantStack<int>	mstack1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this stack with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	mstack1.push(45);
	mstack1.push(87);
	mstack1.push(43);
	mstack1.push(90);
	mstack1.push(654);

	MutantStack<int>::iterator it = mstack1.begin();
	MutantStack<int>::iterator ite = mstack1.end();

	while (it != ite)
	{
		if (it != mstack1.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a MutantStack instance (empty copy)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	MutantStack<int>	mstack2;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Affecting mstack1 to mstack2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	mstack2 = mstack1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "mstack2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	it = mstack2.begin();
	ite = mstack2.end();

	while (it != ite)
	{
		if (it != mstack2.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Replacing last number from mstack2 (should not affect mstack1)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	mstack2.pop();
	mstack2.push(789);
	
	std::cout << "mstack2 copy after: ";
	it = mstack2.begin();
	ite = mstack2.end();

	while (it != ite)
	{
		if (it != mstack2.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
	
	std::cout << "mstack1 orig after: ";
	it = mstack1.begin();
	ite = mstack1.end();

	while (it != ite)
	{
		if (it != mstack1.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Replacing last number from mstack1 (should not affect mstack2)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	mstack1.pop();
	mstack1.push(23);
	
	std::cout << "mstack2 copy after: ";
	it = mstack2.begin();
	ite = mstack2.end();

	while (it != ite)
	{
		if (it != mstack2.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
	
	std::cout << "mstack1 orig after: ";
	it = mstack1.begin();
	ite = mstack1.end();

	while (it != ite)
	{
		if (it != mstack1.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
    
    return ;
}

void    testMutantStackCopyByConstructor()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test MutantStack copy by constructor" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a MutantStack instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	MutantStack<int>	mstack1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this stack with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	mstack1.push(45);
	mstack1.push(87);
	mstack1.push(43);
	mstack1.push(90);
	mstack1.push(654);

	MutantStack<int>::iterator it = mstack1.begin();
	MutantStack<int>::iterator ite = mstack1.end();

	while (it != ite)
	{
		if (it != mstack1.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Call to copy constructor" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	testConstructorByCopy(mstack1);

	std::cout << std::endl;
    
    return ;
}

void	testConstructorByCopy(MutantStack	<int>mstack)
{
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Copy after" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		if (it != mstack.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
	
	return ;
}