/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:54:32 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 21:50:20 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

static void write_title(std::string const &str, std::string const &col) {
  std::cout << std::endl;
  std::cout << col << "############### " << str << " ###############" << END
            << std::endl;
  std::cout << std::endl;
}

static void test_form(AForm &form, Bureaucrat &bur) {

  std::cout << CLEAR;
  write_title(form.getName() + " Tests", GREEN);
  // Bob tries to execute form without signature
  std::cout << BLUE << bur << END << std::endl;
  std::cout << BLUE << form << END << std::endl;
  std::cout << RED << form.getName() << " is not signed and " << bur.getName()
            << " doesn't have permission: " << END;
  try {
    bur.executeForm(form);
  } catch (AForm::FormNotSignedException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooHighException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooLowException &exc) {
    std::cout << exc.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << BLUE << form << END << std::endl << std::flush;
  std::cout << YELLOW << "Press Enter to continue..." << END;
  std::cin.get();

  std::cout << CLEAR;
  write_title(form.getName() + " Tests", GREEN);
  // Bob tries to sign form without high enough grade
  std::cout << BLUE << bur << END << std::endl;
  std::cout << BLUE << form << END << std::endl;
  std::cout << RED << bur.getName() << " does not have permission to sign "
            << form.getName() << ": " << END;
  try {
    bur.signForm(form);
  } catch (AForm::FormNotSignedException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooHighException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooLowException &exc) {
    std::cout << exc.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << BLUE << form << END << std::endl << std::flush;
  std::cout << YELLOW << "Press Enter to continue..." << END;
  std::cin.get();

  std::cout << CLEAR;
  write_title(form.getName() + " Tests", GREEN);
  // Bob tries to execute form again without signature but with permission
  std::cout << "Increasing " << bur.getName() << "'s power levels... ";
  bur.incGrade(bur.getGrade() - form.getExecGrade());
  std::cout << BLUE << bur << END << std::endl;
  std::cout << BLUE << form << END << std::endl;
  std::cout << RED << form.getName() << " is not signed and " << bur.getName()
            << " has permission: " << END;
  try {
    bur.executeForm(form);
  } catch (AForm::FormNotSignedException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooHighException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooLowException &exc) {
    std::cout << exc.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << BLUE << form << END << std::endl << std::flush;
  std::cout << YELLOW << "Press Enter to continue..." << END;
  std::cin.get();

  std::cout << CLEAR;
  write_title(form.getName() + " Tests", GREEN);
  // Bob signs form
  std::cout << "Decreasing " << bur.getName() << "'s power levels... ";
  bur.decGrade(form.getSignGrade() - form.getExecGrade());
  std::cout << BLUE << bur << END << std::endl;
  std::cout << BLUE << form << END << std::endl;
  std::cout << RED << bur.getName() << " signs " << form.getName() << ": "
            << END;
  try {
    bur.signForm(form);
  } catch (AForm::FormNotSignedException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooHighException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooLowException &exc) {
    std::cout << exc.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << BLUE << form << END << std::endl << std::flush;
  std::cout << YELLOW << "Press Enter to continue..." << END;
  std::cin.get();

  std::cout << CLEAR;
  write_title(form.getName() + " Tests", GREEN);
  // Bob tries to execute form without permission
  std::cout << BLUE << bur << END << std::endl;
  std::cout << BLUE << form << END << std::endl;
  std::cout << RED << bur.getName() << " doesn't have permission to execute "
            << form.getName() << ": " << END;
  try {
    bur.executeForm(form);
  } catch (AForm::FormNotSignedException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooHighException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooLowException &exc) {
    std::cout << exc.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << BLUE << form << END << std::endl << std::flush;
  std::cout << YELLOW << "Press Enter to continue..." << END;
  std::cin.get();

  std::cout << CLEAR;
  write_title(form.getName() + " Tests", GREEN);
  // Bob executes form
  std::cout << "Increasing " << bur.getName() << "'s power levels... ";
  bur.incGrade(form.getSignGrade() - form.getExecGrade());
  std::cout << BLUE << bur << END << std::endl;
  std::cout << BLUE << form << END << std::endl;
  std::cout << RED << form.getName() << " is executed: " << END;
  try {
    bur.executeForm(form);
  } catch (AForm::FormNotSignedException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooHighException &exc) {
    std::cout << exc.what() << std::endl;
  } catch (AForm::GradeTooLowException &exc) {
    std::cout << exc.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << BLUE << form << END << std::endl << std::flush;
  std::cout << YELLOW << "Press Enter to continue..." << END;
  std::cin.get();
}

int main() {
  Bureaucrat bob("Bob", 150);
  ShrubberyCreationForm shrub("home");
  RobotomyRequestForm robot("Bender");
  PresidentialPardonForm pardon("Fry");

  /*=================== Shrubbery Creation Form Tests =======================*/
  write_title(shrub.getName() + " Tests", GREEN);

  std::cout << std::endl;
  test_form(shrub, bob);
  std::cout << std::endl;

  /*===================== Robotomy Request Form Tests =======================*/
  write_title(robot.getName() + " Tests", GREEN);

  std::cout << std::endl;
  test_form(robot, bob);
  std::cout << std::endl;

  /*=================== Presidential Pardon Form Tests ======================*/
  write_title(pardon.getName() + " Tests", GREEN);

  std::cout << std::endl;
  test_form(pardon, bob);
}
