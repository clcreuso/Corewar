#!/bin/sh ******************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    script_test_vm.sh                                .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/12 19:03:24 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2018/07/12 19:03:24 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
FILES=$(ls -1 ./Champs)

if [ ! -d ./MCOREWAR_OUTPUT ]; then
	mkdir ./MCOREWAR_OUTPUT
fi

if [ ! -d ./RCOREWAR_OUTPUT ]; then
	mkdir ./RCOREWAR_OUTPUT
fi

if [[ $1 = "clear" ]]; then
	rm -rf ./RCOREWAR_OUTPUT
	rm -rf ./MCOREWAR_OUTPUT
	printf "The directory are clear.\n"
	exit 1
fi

if [[ -z $1 ]] || ! echo $1 | egrep -q '^[0-9]+$' ; then
    printf "usage: sh $0 \"nb >= 0\" || \"clear\"\n"
    exit 0
fi

for P1 in $FILES
do

	NAME1=$(echo $P1 | rev | cut -c5- | rev)

	for P2 in $FILES
	do

		if [ $NAME1 != "Explosive_Kitty" ]; then
			break 
		fi

		NAME2=$(echo $P2 | rev | cut -c5- | rev)

		OUTPUT="${NAME1}_vs_${NAME2}.output"

		./corewar ./Champs/$P1 ./Champs/$P2 -d $1 > ./MCOREWAR_OUTPUT/$OUTPUT
		./r_corewar ./Champs/$P1 ./Champs/$P2 -d $1 > ./RCOREWAR_OUTPUT/$OUTPUT

		DIFF=$(diff ./RCOREWAR_OUTPUT/$OUTPUT ./MCOREWAR_OUTPUT/$OUTPUT)

		if [ "$DIFF" = "" ]; then
			printf "${GREEN}$NAME1 VS $NAME2 ✔ ${NC}\n"
		else
			printf "${RED}$NAME1 VS $NAME2 ✘ (REAL COREWAR IN FIRST)${NC}\n"
			diff -d ./RCOREWAR_OUTPUT/$OUTPUT ./MCOREWAR_OUTPUT/$OUTPUT
			read -p "Press any key to continue... " -n1 -s
			printf "\n"
		fi

	done

done
