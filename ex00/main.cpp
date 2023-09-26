/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbet <aherbet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:16 by aherbet           #+#    #+#             */
/*   Updated: 2023/07/03 22:10:28 by aherbet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void ) {
    Bureaucrat  a;
        std::cout << a << std::endl;

    Bureaucrat  b("Tony", 0);
    Bureaucrat  c("Louie", 200);

    Bureaucrat  d("John", 50);
        std::cout << d << std::endl;

    Bureaucrat  e("Mike", 125);
        std::cout << e << std::endl;

    Bureaucrat  f(d);
        std::cout << f << std::endl;

    e = d;
        std::cout << e << std::endl;
    
    Bureaucrat  g("Guy", 1);
        std::cout << g << std::endl;
        g.incrementGrade();
        g.setGrade(5);
        std::cout << g << std::endl;
        g.incrementGrade();
        std::cout << g << std::endl;
    
    Bureaucrat  h("Pete", 150);
        std::cout << h << std::endl;
        h.decrementGrade();
        h.setGrade(125);
        std::cout << h << std::endl;
        h.decrementGrade();
        std::cout << h << std::endl;
    
    return (0);
}