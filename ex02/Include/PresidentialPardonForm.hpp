/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:37:28 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 18:38:14 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESI_HPP
#define PRESI_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(void);
  PresidentialPardonForm(std::string const target);
  PresidentialPardonForm(PresidentialPardonForm const &form);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &form);
  ~PresidentialPardonForm(void);
  void execute(Bureaucrat const &executor) const;

private:
  std::string _target;
};

#endif
