#!/usr/bin/env bash

DIRPATH="."
PRINT_SEPARATOR=" "

while [[ $# > 0 ]] # because I can use '>' instead of '-gt' inside '[[..]]' expression
do
  case "$1" in
      -p|--path)  DIRPATH="$2"
	      	  shift
		  ;;

      -1)	  PRINT_SEPARATOR="\n"
	          ;;

      --help)
	      	  echo "Usage: ./extensions.sh [OPTION]..."
		  echo "List all unique extensions in the DIR and its subdirectories (the current directory by default)."
		  echo "Sort entries alphabetically."
		  echo
		  echo "Mandatory arguments to long options are mandatory for short options too."
		  echo -e "  -p, --path \t specify directory for listing"
		  echo -e "  -1         \t list one entry per line"
		  echo -e "      --help \t display this help and exit"
		  echo    "      --version  output version information and exit"
		  exit
		  ;;

      --version)  
	      	  echo "extensions.sh 1.1"
		  echo "This is free software: you are free to change and redistribute it."
		  echo "There is NO WARRANTY, to the extent permitted by law."
		  echo
		  echo "Written by Roman Migalev."
		  exit
		  ;;

      *)	  echo "extensions.sh: invalid option '$1'"
		  exit
		  ;;
  esac
shift
done

extract_extension()
{
    echo "$1" | tr "." "\n" | tail -n 1
}

extN=0
extArray=()

while read -r filename
  do
    if [[ $filename == *?"."?* ]]; then
      extArray[extN]="$(extract_extension "$filename")"
      ((extN++))
    fi
  done <<< "$(find "$DIRPATH" -printf "%f\n")" # %f - print only filename

for (( i = 0; i < extN; i++ ))
do
  echo "${extArray[$i]}"
done | sort -u | tr "\n" "$PRINT_SEPARATOR"
[[ $PRINT_SEPARATOR == " " ]] && echo
