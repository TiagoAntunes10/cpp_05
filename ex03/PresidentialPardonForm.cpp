/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:38:56 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 18:42:02 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential Pardon Form", 25, 5) {
  _target = "Target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
    : AForm("Presidential Pardon Form", 25, 5) {
  _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &form)
    : AForm(form) {
  return;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &form) {
  AForm::operator=(form);

  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { return; }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  std::ofstream file;

  if (!this->getSignStatus())
    throw this->not_signed_except;

  if (this->getExecGrade() >= executor.getGrade()) {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
  } else
    throw this->low_except;
}
