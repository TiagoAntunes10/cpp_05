/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:23:40 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 21:16:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Robotomy Request Form", 72, 45) {
  _target = "Target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("Robotomy Request Form", 72, 45) {
  _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form)
    : AForm(form) {
  return;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &form) {
  AForm::operator=(form);

  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { return; }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  int rand;

  if (!this->getSignStatus())
    throw this->not_signed_except;

  if (this->getExecGrade() >= executor.getGrade()) {
    std::cout << "*drilling noises* *drilling noises*" << std::endl;
    rand = std::rand() % 10 + 1;
    if (rand % 2 == 0)
      std::cout << _target << " has been successfully robotomised" << std::endl;
    else
      std::cout << "Robotomy failed" << std::endl;
  } else
    throw this->low_except;
}
