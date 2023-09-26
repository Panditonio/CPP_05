/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:16 by aherbet           #+#    #+#             */
/*   Updated: 2023/07/06 03:12:41 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
    ShrubberyCreationForm   shrub("backyard");
    RobotomyRequestForm     robot("Trainee");
    PresidentialPardonForm  prezy("Ford Prefect");
    Bureaucrat              john("John", 1);
    Bureaucrat              mike("Mike", 70);
    Bureaucrat              pete("Pete", 150);

    std::cout << std::endl;
    std::cout << "/*----------Execution tests----------*/" << std::endl;
    std::cout << std::endl;

    std::cout << john << std::endl;
    std::cout << mike << std::endl;
    std::cout << pete << std::endl;
    std::cout << std::endl;

    std::cout << "// shrubbery creation" << std::endl;
    std::cout << std::endl;
    john.signForm(shrub);
    john.executeForm(shrub);
    mike.signForm(shrub);
    mike.executeForm(shrub);
    pete.signForm(shrub);
    pete.executeForm(shrub);

    std::cout << std::endl;
    std::cout << "// robotomy request" << std::endl;
    std::cout << std::endl;
    john.signForm(robot);
    john.executeForm(robot);
    john.executeForm(robot);
    john.executeForm(robot);
    john.executeForm(robot);
    john.executeForm(robot);
    john.executeForm(robot);
    john.executeForm(robot);
    mike.signForm(robot);
    mike.executeForm(robot);
    pete.signForm(robot);
    pete.executeForm(robot);
    
    std::cout << std::endl;
    std::cout << "// presidential pardon" << std::endl;
    std::cout << std::endl;
    john.signForm(prezy);
    john.executeForm(prezy);
    mike.signForm(prezy);
    mike.executeForm(prezy);
    pete.signForm(prezy);
    pete.executeForm(prezy);

    return (0);
}