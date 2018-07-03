/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dump.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 19:47:07 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 15:32:54 by dguelpa     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/main_vm.h"

int		is_pc(int i)
{
	t_process	*tmp;

	tmp = g_vm->list_process;
	while (tmp)
	{
		if (i == tmp->registers[0])
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		print_color(int i, int *p, int pc)
{
	if (!(p[0] == g_vm->p_map[i] || p[1] == g_vm->p_map[i] || p[2] == g_vm->p_map[i] || p[3] == g_vm->p_map[i]))
	{
		if (p[0] == -2)
			p[0] = g_vm->p_map[i];
		else if (p[1] == -2)
			p[1] = g_vm->p_map[i];
		else if (p[2] == -2)
			p[2] = g_vm->p_map[i];
		else if (p[3] == -2)
			p[3] = g_vm->p_map[i];
	}
	if (g_vm->p_map[i] == p[0])
		ft_printf((pc ? "{n_white}{black}%02x{eoc}{eoc}" :
					"{cyan}%02x{eoc}"), g_vm->map[i]);
	if (g_vm->p_map[i] == p[1])
		ft_printf((pc ? "{n_white}{black}%02x{eoc}{eoc}" :
					"{yellow}%02x{eoc}"), g_vm->map[i]);
	if (g_vm->p_map[i] == p[2])
		ft_printf((pc ? "{n_white}{black}%02x{eoc}{eoc}" :
					"{magenta}%02x{eoc}"), g_vm->map[i]);
	if (g_vm->p_map[i] == p[3])
		ft_printf((pc ? "{n_white}{black}%02x{eoc}{eoc}" :
					"{green}%02x{eoc}"), g_vm->map[i]);
	return (0);
}

int		ft_dump(void)
{
	int i;
	int p[4];

	p[0] = -2;
	p[1] = -2;
	p[2] = -2;
	p[3] = -2;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i == 0)
			ft_printf("%-#5.4x : ", i);
		else if (i % 32 == 0)
			ft_printf("\n%-#5.4x : ", i);
		if (g_vm->p_map[i] < 0)
			ft_printf("%02x", g_vm->map[i]);
		else
			print_color(i, p, is_pc(i));
		if ((i + 1) % 32 != 0)
			ft_printf(" ");
	}
	ft_printf("\n");
	return (0);
}