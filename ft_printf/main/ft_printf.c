/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:31:29 by jabt              #+#    #+#             */
/*   Updated: 2018/02/20 11:06:09 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int main(int argc, char **argv)
{
	char *str;

	str = NULL;
	//long test;
	//test = 21474
//	unsigned int test = -2147483689;
	int pre = 2;
	int ret;
	int retmy;

	/*ret = printf("1vraie printf test : %1.1d et apres\n", atoi(argv[1]));
	retmy = ft_printf("1monie printf test : %1.1d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("2vraie printf test : %65.32d et apres\n", atoi(argv[1]));
	retmy = ft_printf("2monie printf test : %65.32d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("3vraie printf test : %65d et apres\n", atoi(argv[1]));
	retmy = ft_printf("3monie printf test : %65d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("4vraie printf test : %065d et apres\n", atoi(argv[1]));
	retmy = ft_printf("4monie printf test : %065d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("5vraie printf test : %.32d et apres\n", atoi(argv[1]));
	retmy = ft_printf("5monie printf test : %.32d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("6vraie printf test : %-65.32d et apres\n", atoi(argv[1]));
	retmy = ft_printf("6monie printf test : %-65.32d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("7vraie printf test : %-65d et apres\n", atoi(argv[1]));
	retmy = ft_printf("7monie printf test : %-65d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("8vraie printf test : %-.32d et apres\n", atoi(argv[1]));
	retmy = ft_printf("8monie printf test : %-.32d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("9vraie printf test : %-8.5d et apres\n", atoi(argv[1]));
	retmy = ft_printf("9monie printf test : %-8.5d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");

	ret = printf("10vraie printf test : %-8d et apres\n", atoi(argv[1]));
	retmy = ft_printf("10monie printf test : %-8d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("11vraie printf test : %-.5d et apres\n", atoi(argv[1]));
	retmy = ft_printf("11monie printf test : %-.5d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("12vraie printf test : %-08.5d et apres\n", atoi(argv[1]));
	retmy = ft_printf("12monie printf test : %-08.5d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("13vraie printf test : %16.8d et apres\n", atoi(argv[1]));
	retmy = ft_printf("13monie printf test : %16.8d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("14vraie printf test : %16d et apres\n", atoi(argv[1]));
	retmy = ft_printf("14monie printf test : %16d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("15vraie printf test : %.8d et apres\n", atoi(argv[1]));
	retmy = ft_printf("15monie printf test : %.8d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("16vraie printf test : %016.8d et apres\n", atoi(argv[1]));
	retmy = ft_printf("16monie printf test : %016.8d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("17vraie printf test : %016d et apres\n", atoi(argv[1]));
	retmy = ft_printf("17monie printf test : %016d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("18vraie printf test : %015.5d et apres\n", atoi(argv[1]));
	retmy = ft_printf("18monie printf test : %015.5d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("19vraie printf test : %-015d et apres\n", atoi(argv[1]));
	retmy = ft_printf("19monie printf test : %-015d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("20vraie printf test : %-0.8d et apres\n", atoi(argv[1]));
	retmy = ft_printf("20monie printf test : %-0.8d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("21vraie printf test : %+15.8d et apres\n", atoi(argv[1]));
	retmy = ft_printf("21monie printf test : %+15.8d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("22vraie printf test : %+15d et apres\n", atoi(argv[1]));
	retmy = ft_printf("22monie printf test : %+15d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("23vraie printf test : %+.8d et apres\n", atoi(argv[1]));
	retmy = ft_printf("23monie printf test : %+.8d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("24vraie printf test : %+-15.8d et apres\n", atoi(argv[1]));
	retmy = ft_printf("24monie printf test : %+-15.8d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("25vraie printf test : %+-15d et apres\n", atoi(argv[1]));
	retmy = ft_printf("25monie printf test : %+-15d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");

	ret = printf("26vraie printf test : %+08d et apres\n", atoi(argv[1]));
	retmy = ft_printf("26monie printf test : %+08d et apres\n", atoi(argv[1]));
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("27vraie printf test : % d et apres\n", atoi(argv[1]));
	retmy = ft_printf("27monie printf test : % d et apres\n", atoi(argv[1]));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	printf("\n\n\nGO FAIRE DS PETITS TESTS DE SIZE\n\n\n");

	ret = printf("28vraie printf test : % hhd le pourcentage hh(char)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("28monie printf test : % hhd le pourcentage hh(char)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("29vraie printf test : %+8hhd le pourcentage hh(char)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("29monie printf test : %+8hhd le pourcentage hh(char)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("30vraie printf test : %+.8hhd le pourcentage hh(char)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("30monie printf test : %+.8hhd le pourcentage hh(char)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("31vraie printf test : % hd le pourcentage h(short)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("31monie printf test : % hd le pourcentage h(short)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("32vraie printf test : %+8hd le pourcentage h(short)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("32monie printf test : %+8hd le pourcentage h(short)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("33vraie printf test : %+.8hd le pourcentage h(short)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("33monie printf test : %+.8hd le pourcentage h(short)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("34vraie printf test : % ld le pourcentage l(long)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("34monie printf test : % ld le pourcentage l(long)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("35vraie printf test : %+15ld le pourcentage l(long)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("35monie printf test : %+15ld le pourcentage l(long)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("36vraie printf test : %+.15ld le pourcentage l(long)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("36monie printf test : %+.15ld le pourcentage l(long)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");

	ret = printf("37vraie printf test : % lld le pourcentage ll(longlong)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("37monie printf test : % lld le pourcentage ll(longlong)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("38vraie printf test : %+15lld le pourcentage ll(longlong)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("38monie printf test : %+15lld le pourcentage ll(longlong)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("39vraie printf test : %+.15lld le pourcentage ll(longlong)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("39monie printf test : %+.15lld le pourcentage ll(longlong)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");

	ret = printf("40vraie printf test : % jd le pourcentage j(intmax)\n", 9223372036854775807);
	retmy = ft_printf("40monie printf test : % jd le pourcentage j(intmax)\n", 9223372036854775807);	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("41vraie printf test : %+15jd le pourcentage j(intmax)\n", 9223372036854775807);
	retmy = ft_printf("41monie printf test : %+15jd le pourcentage j(intmax)\n", 9223372036854775807);	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("42vraie printf test : %+.15jd le pourcentage j(intmax)\n", 9223372036854775807);
	retmy = ft_printf("42monie printf test : %+.15jd le pourcentage j(intmax)\n", 9223372036854775807);	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");

	ret = printf("43vraie printf test : % jd le pourcentage j(intmax)\n", 9223372036854775807);
	retmy = ft_printf("43monie printf test : % jd le pourcentage j(intmax)\n", 9223372036854775807);	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("44vraie printf test : %+35jd le pourcentage j(intmax)\n", 9223372036854775807);
	retmy = ft_printf("44monie printf test : %+35jd le pourcentage j(intmax)\n", 9223372036854775807);	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("45vraie printf test : %+.35jd le pourcentage j(intmax)\n", 9223372036854775807);
	retmy = ft_printf("45monie printf test : %+.35jd le pourcentage j(intmax)\n", 9223372036854775807);	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");

	ret = printf("46vraie printf test : % zd le pourcentage z(undefined)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("46monie printf test : % zd le pourcentage z(undefined)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("47vraie printf test : %+15zd le pourcentage z(undefined)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("47monie printf test : %+15zd le pourcentage z(undefined)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
	
	ret = printf("48vraie printf test : %+.15zd le pourcentage z(undefined)\n", strtoimax(argv[1], &str, 10));
	retmy = ft_printf("48monie printf test : %+.15zd le pourcentage z(undefined)\n", strtoimax(argv[1], &str, 10));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");
*/
	ret = printf("vraie : %5.u\n", atoi(argv[1]));
	retmy = ft_printf("monie : %5.u\n", atoi(argv[1]));	
	if (ret != retmy)
	{
		printf("retour vrai printf : %d\n", ret);
		printf("retour mon printf : %d\n", retmy);
	}
	printf("\n");

	
	/*
	printf("le vraie : %s et apres\n", argv[1]);
	ft_printf("le miens : %s et apres\n", argv[1]);*/

	//printf("le vraie : %#015b et apres\n", atoi(argv[1]));
	//ft_printf("le miens : %#015b et apres\n", atoi(argv[1]));

	/*ret = printf("bonjour : %8.6D\n", atoi(argv[1]));
	printf("le resultat du vraie : %D\n", ret);
	ret = ft_printf("bonjour : %8.6D\n", atoi(argv[1]));
	printf("le resultat du mien : %D\n", ret);*/

	//printf("lol %54?\n");  attention a ca !!
	//ft_printf("mdrr t'es un boloos %54?\n");

	//printf("hop : %.**d", 8, 150, 15);
	return (0);
}
