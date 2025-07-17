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

#include "Include/includes.hpp"

int main() {
  Bureaucrat bob("Bob", 20);

  std::cout << "Name: " << bob.getName() << std::endl;
  std::cout << "Grade: " << bob.getGrade() << std::endl;

  std::cout << RED << "Increasing grade by 5 test: " << END;
  bob.incGrade(5);
  std::cout << bob;

  std::cout << RED << "Decrease grade by 2 test: " << END;
  bob.decGrade(2);
  std::cout << bob;

  std::cout << std::endl;
  std::cout << GREEN << "Bureaucrat Grade Limit Tests" << END << std::endl
            << END;
  std::cout << std::endl;

  std::cout << RED
            << "Create bureaucrat with a grade that is too low test: " << END;
  // Bureaucrat has grade too low
  try {
    try {
      Bureaucrat excep("excep", 160);
    } catch (Bureaucrat::GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (Bureaucrat::GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << RED << "Decrease bureaucrat's grade too much test: " << END;
  // Bureaucrat decreases grade too much
  try {
    try {
      bob.decGrade(150);
    } catch (Bureaucrat::GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (Bureaucrat::GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << RED
            << "Create bureaucrat with a grade that is too high test: " << END;
  // Bureaucrat has grade too high
  try {
    try {
      Bureaucrat excep2("excep2", 0);
    } catch (Bureaucrat::GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (Bureaucrat::GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << RED << "Increase bureaucrat's grade too much test: " << END;
  // Bureaucrat increases grade too much
  try {
    try {
      bob.incGrade(160);
    } catch (Bureaucrat::GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (Bureaucrat::GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << GREEN << "Form Grade Limit Tests" << END << std::endl << END;
  std::cout << std::endl;

  std::cout << RED
            << "Create form with a sign grade that is too low test: " << END;
  // Form has sign grade too low
  try {
    try {
      Form form("form", 160, 10);
    } catch (Form::GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (Form::GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << RED
            << "Create form with a sign grade that is too high test: " << END;
  // Form has sign grade too high
  try {
    try {
      Form form2("form2", 0, 5);
    } catch (Form::GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (Form::GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << RED
            << "Create form with a execution grade that is too low test: "
            << END;
  // Form has execution grade too low
  try {
    try {
      Form form("form", 20, 200);
    } catch (Form::GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (Form::GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << RED
            << "Create form with a execution grade that is too high test: "
            << END;
  // Form has execution grade too high
  try {
    try {
      Form form2("form2", 4, 0);
    } catch (Form::GradeTooLowException &l_g) {
      std::cout << l_g.what() << std::endl;
    }
  } catch (Form::GradeTooHighException &h_g) {
    std::cout << h_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << GREEN << "Signing a Form Tests" << END << std::endl << END;
  std::cout << std::endl;

  Form bill("Bill", 10, 5);
  std::cout << BLUE << bob << END;
  std::cout << BLUE << bill << END;
  std::cout << std::endl;

  // Bob tries to sign a form and fails
  std::cout << RED << "Signing fails test: " << END;
  try {
    bob.signForm(bill);
  } catch (Form::GradeTooLowException &l_g) {
    std::cout << l_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << BLUE << bill << END;
  std::cout << std::endl;

  std::cout << "Increasing Bob's power levels... ";
  bob.incGrade(10);
  std::cout << BLUE << bob << END;
  std::cout << std::endl;

  // Bob tries to sign a form and succeeds
  std::cout << RED << "Signing succeeds test: " << END;
  try {
    bob.signForm(bill);
  } catch (Form::GradeTooLowException &l_g) {
    std::cout << l_g.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << BLUE << bill << END;
}
