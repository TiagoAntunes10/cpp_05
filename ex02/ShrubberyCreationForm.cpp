/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:27:10 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 18:38:35 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery Creation Form", 145, 137) {
  _target = "Target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
    : AForm("Shrubbery Creation Form", 145, 137) {
  _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form)
    : AForm(form) {
  return;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &form) {
  AForm::operator=(form);

  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { return; }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  std::ofstream file;
  const char *file_name = (_target + "_shrubbery").c_str();

  if (!this->getSignStatus())
    throw this->not_signed_except;

  if (this->getExecGrade() >= executor.getGrade()) {
    file.open(file_name);
    if (!file.is_open()) {
      std::cout << "Error creating the file." << std::endl;
      return;
    }
    file << "    o\n \
  dOo\n \
 oC8Po\n \
 C8UvCO\n \
 c\\|88b\n \
   ||/\n \
   ||\n" << std::endl;

    file << "    o\n \
  dOo\n \
 oC8Po\n \
 C8UvCO\n \
 c\\|88b\n \
   ||/\n \
   ||\n" << std::endl;
    file.close();
  } else
    throw this->low_except;
}
