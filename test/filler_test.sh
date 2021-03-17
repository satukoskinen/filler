#!/bin/bash

### CONFIG ###

player="./skoskine.filler"
opponent_dir="resources/players/*"
#opponent_dir="resources/players/ksuomala.filler"
map_dir="resources/maps/*"
vm="resources/filler_vm_old"
logfile="test_log"

##############

play () {
	local map=$1
	local p1=$2
	local p2=$3

	for i in {1..10}
	do
		./$vm -f $map -p1 $p1 -p2 $p2 > output
		grep "Segfault" output > error
		if [ -s error ]
		then
			filename="log_${i}"
			cat output > $filename
			printf "\nsegfault: see $filename\n"
			printf "map $map p1 $p1 p2 $p2\n" >> $logfile
			cat filler.trace >> $logfile
		fi
		grep "fin" output > result
		p1_result=$(grep "O" result | cut -d " " -f 4)
		p2_result=$(grep "X" result | cut -d " " -f 4)
		if [ $p1 == $player ]
		then
			player_result=$p1_result
			opponent_result=$p2_result
		else
			player_result=$p2_result
			opponent_result=$p1_result
		fi
		if [ $player_result -gt $opponent_result ]
		then
			printf "1"
		else
			printf "."
			printf "\n./$vm -f $map -p1 $p1 -p2 $p2\n" >> $logfile
			cat filler.trace >> $logfile
		fi
	done
	rm output error result
}

##############

## Test with maps provided in resources:

rm -f $logfile
printf "testing $player...\n"

# Multi-player: as p1 and p2 against all other players,
# each repeated 10 times

read -n 1 -p "test multiplayer? [y/n] " ret
if [ $ret != "n" ]
then
	printf "\n\nmultiplayer:\n"
	for map in $map_dir
	do
		printf "\nmap $map:\n"
		for opponent in $opponent_dir
		do
		printf "\nagainst $opponent:"
			printf "\nas p1: "
			play $map $player $opponent
			printf "\nas p2: "
			play $map $opponent $player
			printf "\n"
		done
	done
fi

# Single player: each map 10 times

printf "\n"
read -n 1 -p "test single player? [y/n] " ret
if [ $ret != "n" ]
then
	printf "\n\nsingle player:\n"
	for map in $map_dir
	do
		printf "\nmap $map:\n"
		for i in {1..10}
		do
			./$vm -f $map -p1 $player > output
			grep "Segfault" output > error
			if [ -s error ]
			then
				filename="log_${i}"
				cat output > $filename
				printf "\nsegfault: see $filename\n"
				printf "\n./$vm -f $map -p1 $player\n" >> $logfile
				cat filler.trace >> $logfile
			fi
			grep "fin" output
		done
	done
fi

rm -f output result error

# Generate maps of different sizes with random starting points,
# otherwise as above