/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:19:04 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/18 22:59:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
  Intern(void);
  Intern(Intern const &intern);
  Intern &operator=(Intern const &intern);
  ~Intern(void);
  AForm *makeForm(std::string name, std::string target);
};

#endif
