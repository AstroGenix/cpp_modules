/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <dberehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:28:15 by dberehov          #+#    #+#             */
/*   Updated: 2024/09/27 13:45:12 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		std::string ideas[100];

		// Constructor & Desctructor
		Brain(void);
		Brain(const Brain& copy);
		~Brain(void);

		// Operator
		Brain& operator=(const Brain& copy);
};

#endif 