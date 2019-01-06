#pragma once
#include <map>

using namespace std;

class Poly{
private:
	map <int, double, greater<int>> polyMap;
public:
	Poly();
	Poly(double);
	double &operator[] (unsigned int);
	friend ostream & operator<<(ostream&, const Poly&);
	friend Poly operator+ (const Poly&, const Poly&);
	friend Poly operator- (const Poly&, const Poly&);
	friend Poly operator* (const Poly&, const Poly&);
	Poly operator- () const;
	double operator() (double);
};