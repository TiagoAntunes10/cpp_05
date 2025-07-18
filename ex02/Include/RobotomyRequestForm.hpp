/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:22:44 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 18:28:40 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(void);
  RobotomyRequestForm(std::string const &target);
  RobotomyRequestForm(RobotomyRequestForm const &form);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &form);
  ~RobotomyRequestForm(void);
  void execute(Bureaucrat const &executor) const;

private:
  std::string _target;
};

#endif
