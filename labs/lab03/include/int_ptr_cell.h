#ifndef CSC232_INT_PTR_CELL_H
#define CSC232_INT_PTR_CELL_H

#include <algorithm>
#include <iostream>

namespace csc232
{
	class IntPtrCell
	{
		public:
			explicit IntPtrCell(int value=0);
			IntPtrCell(const IntPtrCell & src);
			IntPtrCell(IntPtrCell&& src);
			IntPtrCell& operator=(const IntPtrCell & rhs);
			IntPtrCell& operator=(IntPtrCell&& rhs);
			~IntPtrCell();
			int read() const;
			void write(int value);
		private:
			int *ptr_stored_value;
	};
}

#endif // CSC232_INT_PTR_CELL_H
