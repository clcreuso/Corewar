/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_vm.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 16:14:38 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/01 15:48:44 by dguelpa     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "main_vm.h"

int		main(int argc, char const **argv)
{
	if (argc > 1)
	{
		init_vm(argv);
		parse_args(argv);
	}
	else
		print_usage();
	return (0);
}
