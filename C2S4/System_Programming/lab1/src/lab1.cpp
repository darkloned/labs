/*
 * Created by darkloned.
 * Task:
 *  Rewrite Lisp program even-odd.ss to C++ using TranslationRules.doc 
 *
 * See log file for demonstration of working.
 */

// even-odd

#include "mlisp.h"

double dd = 12;
double mm = 02;
double yyyy = 1998;

double even__bits(double n);
double odd__bits(double n);
double display__bin(double n);
double report__results(double n);

double even__bits(double n)
{
	return (n == 0 ? 1 :
			_remainder(n, 2) == 0 ? even__bits(quotient(n, 2)) :
			odd__bits(quotient(n, 2))
			);
}

double odd__bits(double n)
{
	return (n == 0 ? 0 :
			_remainder(n, 2) == 0 ? odd__bits(quotient(n, 2)) :
			true ? even__bits(quotient(n, 2)) :
			_infinity
			);
}

double display__bin(double n)
{
	display(_remainder(n, 2));

	return (n == 0 ? 0 : display__bin(quotient(n, 2)));
}

double report__results(double n)
{
	display("Happy birthday to you!\n\t");
	display(n);
	display(" (decimal)\n\t");

	display__bin(n);
	display(" (reversed binary)\n\t");
	newline();

	display("\teven?\t");
	display(even__bits(n) == 1 ? "yes" : "no");
	newline();

	display("\todd?\t");
	display(odd__bits(n) == 1 ? "yes" : "no");
	newline();

	return 0;
}

int main(int argc, char const *argv[])
{
	display(report__results(dd * 1e6 + mm * 1e4 + yyyy));
	newline();

	return 0;
}
