# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random_list.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marykman <marykman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 23:49:43 by marykman          #+#    #+#              #
#    Updated: 2024/08/30 23:58:35 by marykman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import random

def	generate_random_list(n: int):
	l = [str(n) for n in range(n)]
	random.shuffle(l)
	return " ".join(l)


if __name__ == '__main__':
	if (len(sys.argv) != 2 or not sys.argv[1].isdigit()):
		print("Usage: python3 random_list.py <size>")
		sys.exit()
	print(generate_random_list(int(sys.argv[1])))