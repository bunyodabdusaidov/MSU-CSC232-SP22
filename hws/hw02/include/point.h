#ifndef CSC232_POINT_H
#define CSC232_POINT_H

namespace csc232
{
	class Point
	{
		private:
			double x;
			double y;
		public:
			explicit Point(double initial_x=0.0, double initial_y=0.0);
			void shift(double x_amount, double y_amount);
			void rotate90();
			double get_x() const;
			double get_y() const;
	};	
};

#endif
