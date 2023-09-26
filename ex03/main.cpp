/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbet <aherbet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:16 by aherbet           #+#    #+#             */
/*   Updated: 2023/09/06 19:55:17 by aherbet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void     intro(void) {
    std::cout << std::endl;
    std::cout << "I am your intern ! Welcome to my print desk !" << std::endl;
    std::cout << "Please select one of the following type of forms : " << std::endl;
    std::cout << "presidential pardon, robotomy request or shrubbery creation" <<std::endl;
    std::cout << "type EXIT to exit" <<std::endl;
    std::cout << std::endl;
}

int main( void ) {
    Bureaucrat      john("John", 1);
    Bureaucrat      mike("Mike", 70);
    Intern          slave;
    std::string     target;
    std::string     input1;
    std::string     input2;
    Form*           form; 

    intro();
    while(42) {
        while (!std::cin.eof()) {
            std::cout << "Please define the target of your form application :" << std::endl;
            std::getline(std::cin, target, '\n');
            if (target.empty() == true)
                continue;
            else if (target.compare("EXIT") == 0)
                break;
            std::cin.clear();
            std::cout << "Which type of form would you like to print ?" << std::endl;
            std::getline(std::cin, input1, '\n');
            if (input1.empty() == true)
                continue;
            else if (input1.compare("EXIT") == 0)
                break;
            else
                form = slave.makeForm(input1,target);
            std::cin.clear();
            std::cout << std::endl;
            if (form) {
                std::cout << "Would you like John or Mike to sign and execute your form ? (yes/no) :" << std::endl;
                std::getline(std::cin, input2, '\n');
                if (input2.empty() == true)
                    continue;
                else if (input2.compare("EXIT") == 0 || input2.compare("no") == 0)
                    break;
                else if (input2.compare("yes") == 0) {
                    john.signForm(*form);
                    john.executeForm(*form);
                    mike.signForm(*form);
                    mike.executeForm(*form);
                    std::cout << std::endl;
                }
                else {
                    std::cout << "Improper response" << std::endl;
                    continue;
                }
            }
            else
                continue;
        }
        delete form;
        std::cout << "So long... and thanks for all the fish !" << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

// int main(void) {
//     Intern  someRandomIntern;
//     Form*   rrf;
//     rrf = someRandomIntern.makeForm("robotomy request", "Bender");
//     return(0);
// }