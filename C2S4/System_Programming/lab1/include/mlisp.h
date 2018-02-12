#ifndef MLISP_H
#define MLISP_H

#include <iostream>
#include <cmath>
#include <limits>

using std::sin; using std::cos;
using std::tan; using std::atan;
using std::log; using std::exp;

  const double _infinity=
     std::numeric_limits<double>::infinity();
  const double pi= 4.*std::atan(1.);
  const double e = std::exp(1.);
  
  inline double display(double x){
     std::cout.precision(16);
     std::cout<<x;return 0;}
  inline double display(int x){
     std::cout<<x;return 0;}
  inline double display(char x){
     std::cout<<x;return 0;}
  inline double display(const char* x){
     std::cout<<x;return 0;}
  inline double display(bool x){
     std::cout<<'#'<<(x ? 't' : 'f');return 0;}
  inline double newline(){
    std::cout<< std::endl;return 0;}
  inline double _remainder(double x, double y){ 
    return std::fmod(x, y);}
  inline double quotient(double x, double y)
    { return std::floor(x / y);}
  inline double expt(double x, double y)
    { return std::pow(x, y);}
  inline double abs(double x){ return std::fabs(x);}

#endif
