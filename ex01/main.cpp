/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:16 by aherbet           #+#    #+#             */
/*   Updated: 2023/07/05 19:46:13 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
    std::cout << "/*----------Form tests----------*/" << std::endl;
    std::cout << std::endl;

    Form    f1;
    std::cout << f1 << std::endl;
    std::cout << std::endl;
    
    Form    f2("27B-6", 0, 1);
    std::cout << f2 << std::endl;
    std::cout << std::endl;

    Form    f3("28C-5", 1, 0);
    std::cout << f3 << std::endl;
    std::cout << std::endl;

    Form    f4("29A-2", 1, 151);
    std::cout << f4 << std::endl;
    std::cout << std::endl;

    Form    f5("30D-8", 151, 1);
    std::cout << f5 << std::endl;
    std::cout << std::endl;

    std::cout << "/*----------Signature tests----------*/" << std::endl;
    std::cout << std::endl;

    Bureaucrat  pete = Bureaucrat("Pete", 15);
    std::cout << pete << std::endl;
    Form    f6("31F-4", 100, 50);
    std::cout << f6 << std::endl;
    pete.signForm(f6);
    std::cout << f6 << std::endl;
    std::cout << std::endl;

    Bureaucrat  mike = Bureaucrat("Mike", 15);
    std::cout << mike << std::endl;
    Form    f7("32G-9", 10, 5);
    std::cout << f7 << std::endl;
    mike.signForm(f7);
    std::cout << f7 << std::endl;
    std::cout << std::endl;

    Bureaucrat  john = Bureaucrat("John", 15);
    std::cout << john << std::endl;
    Form    f8("32G-9", 15, 15);
    std::cout << f8 << std::endl;
    john.signForm(f8);
    std::cout << f8 << std::endl;
    std::cout << std::endl;
    
    return (0);
}