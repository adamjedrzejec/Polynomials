#include <iostream>
#include <math.h>
#include "Poly.h"
#include <map>

Poly::Poly(){ }

Poly::Poly(double value){
	polyMap[0] = value; 
}

double & Poly::operator[] (unsigned int key){
	return polyMap[key];
}


ostream & operator<< (ostream& os, const Poly& polynomial)
{  
	os << "y = ";

	for(map<int, double >::const_iterator it = polynomial.polyMap.begin(); it != polynomial.polyMap.end();)
	{
		if (it == polynomial.polyMap.begin() && it->second < 0)
			cout << "- ";

		if(it->second != 0){

			if ((it->second == 1 || it->second == -1) && it->first == 0)
				os << abs(it->second);

			if (it->second != 1 && it->second != -1)
				os << abs(it->second);

			if (it->first == 1)
				os << "x";
			else if (it->first > 1)
				os << "x^" << it->first;
		}

		if (++it != polynomial.polyMap.end()){				// it iterates to the next map pair
			if (it->second > 0)
				os << " + ";
			else if (it->second < 0)
				os << " - ";
		}
	}
    return os;  
}

Poly operator+ (const Poly & p1, const Poly & p2){
	Poly result;

	for(map<int, double >::const_iterator it = p1.polyMap.begin(); it != p1.polyMap.end(); it++)
	{
		result.polyMap[it->first] = it->second;
	}

	for(map<int, double >::const_iterator it = p2.polyMap.begin(); it != p2.polyMap.end(); it++)
	{
		result.polyMap[it->first] += it->second;
	}

	return result;
}

Poly operator- (const Poly & p1, const Poly & p2){
	Poly result;

	for(map<int, double >::const_iterator it = p1.polyMap.begin(); it != p1.polyMap.end(); it++)
	{
		result.polyMap[it->first] = it->second;
	}

	for(map<int, double >::const_iterator it = p2.polyMap.begin(); it != p2.polyMap.end(); it++)
	{
		result.polyMap[it->first] -= it->second;
	}

	return result;
}

Poly operator* (const Poly & p1, const Poly & p2){
	Poly result;

	for(map<int, double >::const_iterator it1 = p1.polyMap.begin(); it1 != p1.polyMap.end(); it1++)
	{
		for(map<int, double >::const_iterator it2 = p2.polyMap.begin(); it2 != p2.polyMap.end(); it2++)
		{
			result.polyMap[it1->first + it2->first] += it1->second * it2->second;
		}
	}

	return result;
}

Poly Poly::operator- () const{
	Poly result;
	for(map<int, double >::const_iterator it = polyMap.begin(); it != polyMap.end(); it++){
		result.polyMap[it->first] = -it->second;
	}
	return result;
}

double Poly::operator() (double argument){
	double value = 0;
	for(map<int, double >::const_iterator it = polyMap.begin(); it != polyMap.end(); it++){
		value += pow(argument, it->first) * it->second;
	}
	return value;
}