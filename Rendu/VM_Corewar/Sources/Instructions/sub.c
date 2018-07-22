/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 15:10:14 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 15:12:11 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/main_vm.h"

void		debug_sub(t_process **proc)
{
	dprintf(1, "1st param (%d) + 2nd param (%d) = %d\n",
			(*proc)->registers[(*proc)->fetchqueue[0][1]],
			(*proc)->registers[(*proc)->fetchqueue[1][1]],
			(*proc)->registers[(*proc)->fetchqueue[2][1]]);
}

void		ft_sub(t_process **proc)
{
	(*proc)->registers[(*proc)->fetchqueue[2][1]] =
		(*proc)->registers[(*proc)->fetchqueue[0][1]] -
		(*proc)->registers[(*proc)->fetchqueue[1][1]];
	(*proc)->carry = (!(*proc)->registers[(*proc)->fetchqueue[2][1]] ? 1 : 0);
	debug_sub(proc);
}
