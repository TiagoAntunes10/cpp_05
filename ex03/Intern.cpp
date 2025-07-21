/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:29:21 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/21 14:13:31 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/PresidentialPardonForm.hpp"
#include "Include/RobotomyRequestForm.hpp"
#include "Include/ShrubberyCreationForm.hpp"
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

static AForm *createShrub(std::string target) {
  return new ShrubberyCreationForm(target);
}

static AForm *createRobot(std::string target) {
  return new RobotomyRequestForm(target);
}

static AForm *createPardon(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
  AForm *form;
  bool (*fn[])(std::string) = {&isShrub, &isRobot, &isPardon};
  AForm *(*form_fn[])(std::string) = {createShrub, createRobot, createPardon};

  for (int i = 0; i < 3; i++) {
    if (fn[i](name)) {
      form = form_fn[i](target);
      std::cout << "Intern creates " << form->getName() << std::endl;
      return form;
    }
  }
  std::cout << "Error: Form not found!" << std::endl;
  return NULL;
}
