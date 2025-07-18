/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:29:21 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/18 23:07:20 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

static bool isShrub(std::string const name) {
  std::string options[3] = {"Shrubbery Creation", "shrubbery creation",
                            "Shrubbery creation"};

  for (int i = 0; i < 3; i++) {
    if (!name.compare(options[i]))
      return true;
  }
  return false;
}

static bool isRobot(std::string const name) {
  std::string options[3] = {"Robotomy Request", "robotomy request",
                            "Robotomy request"};

  for (int i = 0; i < 3; i++) {
    if (!name.compare(options[i]))
      return true;
  }
  return false;
}

static bool isPardon(std::string const name) {
  std::string options[3] = {"Presidential Pardon", "presidential pardon",
                            "Presidential pardon"};

  for (int i = 0; i < 3; i++) {
    if (!name.compare(options[i]))
      return true;
  }
  return false;
}

Intern::Intern(void) { return; }

Intern::Intern(Intern const &intern) {
  (void)intern;

  return;
}

Intern &Intern::operator=(Intern const &intern) {
  (void)intern;

  return *this;
}

Intern::~Intern(void) { return; }

AForm *Intern::makeForm(std::string name, std::string target) {
  AForm *form;

  if (isShrub(name))
    form = new ShrubberyCreationForm(target);
  else if (isRobot(name))
    form = new RobotomyRequestForm(target);
  else if (isPardon(name))
    form = new PresidentialPardonForm(target);
  else {
    std::cout << "Error: Form not found!" << std::endl;
    return NULL;
  }
  std::cout << "Intern creates " << form->getName() << std::endl;
  return form;
}
