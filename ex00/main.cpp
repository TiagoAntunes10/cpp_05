/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:54:32 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/16 14:45:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Bureaucrat.hpp"
#include "Include/includes.hpp"

int main() {
  Bureaucrat bob("Bob", 20);

  std::cout << "Name: " << bob.get_name() << std::endl;
  std::cout << "Grade: " << bob.get_grade() << std::endl;

  bob.inc_grade(5);
  std::cout << bob;
  bob.dec_grade(2);
  std::cout << bob;

  try {
    try {
      Bureaucrat excep("excep", 160);
    } catch (GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  try {
    try {
      Bureaucrat excep2("excep2", 0);
    } catch (GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }
}
