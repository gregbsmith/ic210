/* Gregory Smith
 * 235952
 */

#include "ic210.h"
#include "math.h"

int main(){
	double a = 0;
	double b = 0;
	double c = 0;
	double A = 0;
	double B = 0;
	double C = 0;
	double s = 0;
	double area = 0;
	double lawOfSinesConstant = 0;
	cstring angleCond;
	cstring sideCond;
	
	a = readnum(stdin);
	b = readnum(stdin);
	c = readnum(stdin);
	
	s = .5 * (a + b + c);
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	
	lawOfSinesConstant = 2 * area / (a * b * c);
	
	A = asin(a * lawOfSinesConstant);
	B = asin(b * lawOfSinesConstant);
	C = asin(c * lawOfSinesConstant);
	
	
	if(a+b<=c || a+c<=b || c+b<=a)
	{
		fputs("These lengths violate the triangle inequality!\n", stdout);
		return 0;
	}
	

	if(a == b && b == c)
	{
		fputs("This is an acute equilateral triangle.\n", stdout);
		return 0;
	}
	else if(A < .5 * M_PI && B < .5 * M_PI && C < .5 * M_PI)
	{
		
		if(a!=b && a!=c && b!=c)
		{
			fputs("This is an acute scalene triangle.\n", stdout);
			return 0;
		}
		else
		{
			fputs("This is an acute isosceles triangle.\n", stdout);
			return 0;
		}
	}
	else if(A > .5 * M_PI || B > .5 * M_PI || C > .5 * M_PI)
	{

		if(a!=b && a!=c && b!=c)
		{
			fputs("This is an obtuse scalene triangle.\n", stdout);
			return 0;
		}
		else
		{
			fputs("This is an obtuse isosceles triangle.\n", stdout);
			return 0;
		}
	}
	else if(A == .5 * M_PI || B == .5 * M_PI || C == .5 * M_PI)
	{
		
		if(a!=b && a!=c && b!=c)
		{
			fputs("This is a right scalene triangle.\n", stdout);
			return 0;
		}
		else
		{
			fputs("This is a right isosceles triangle.\n", stdout);
			return 0;
		}
	}
	
	fputs("\n", stdout);
	return 0;
}
