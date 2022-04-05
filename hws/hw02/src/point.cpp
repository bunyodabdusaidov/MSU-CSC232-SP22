#include "point.h"

csc232::Point::Point(double initial_x, double initial_y):x{initial_x}, y{initial_y} {};

void csc232::Point::shift(double x_amount, double y_amount)
{
	x += x_amount;
	y += y_amount;
}
void csc232::Point::rotate90()
{
	int temp = x;
	x = y;
	y = -1 * temp;
}
double csc232::Point::get_x() const
{
	return x;
}
double csc232::Point::get_y() const
{
	return y;
}
		
