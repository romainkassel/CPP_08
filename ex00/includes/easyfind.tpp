/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:30:10 by debian            #+#    #+#             */
/*   Updated: 2024/12/10 03:45:47 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::const_iterator  easyfind( T const & container, int const & value )
{
    typename T::const_iterator  it;
    typename T::const_iterator  ite = container.end();
    
    for (it = container.begin(); it != ite; it++)
        if (*it == value)
            return (it);

    return (ite);
}

template<typename T>
void	printContainer( T const & container )
{
    typename    T::const_iterator   it;
    
    for (it = container.begin(); it != container.end(); it++)
	{
		if (it != container.begin())
			std::cout << ", ";
		std::cout << *it;
	}

    return ;
}

template<typename T>
void	printRvalue( T const & rvalue, T const & last)
{
    std::cout << "rvalue: ";
    
    if (rvalue == last)
        std::cout << "not found";
    else
        std::cout << *rvalue;

    std::cout << std::endl;
    
    return ;
}
