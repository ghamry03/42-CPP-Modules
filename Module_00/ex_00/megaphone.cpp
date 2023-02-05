/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:30:36 by ommohame          #+#    #+#             */
/*   Updated: 2023/01/10 02:48:09 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (size_t i = 1; av[i]; i++) {
			for (size_t j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
			if (av[i + 1])
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
