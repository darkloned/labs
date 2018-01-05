#!/usr/bin/env bash
echo Be a man, man!
# man man
echo Hello, $(uname) user, $(whoami)@$(hostname)!
echo Here is your uptime:
uptime
ln=$(who | wc -l)
rn=$(rwho | wc -l)
tn=$(echo $ln+$rn-1 | bc)
echo At this very moment you have $tn neighbours.
echo Local login users:
who
if [ $rn -gt 0 ];
then
	echo Remote login users:
	rwho
fi
echo More information about you and your neighbours:
finger
while true;
do
	read -p "Enter 'bye' to exit: " ans
	case $ans in
		bye ) echo Bye! && exit;;
		* ) echo Sorry, I can\'t understand you.
	esac
done
