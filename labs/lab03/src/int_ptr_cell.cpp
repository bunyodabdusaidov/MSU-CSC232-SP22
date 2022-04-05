#include "int_ptr_cell.h"

namespace csc232
{
	IntPtrCell::IntPtrCell(int init_value) : ptr_stored_value{ new int(init_value) }
	{
		 // intentionally empty
		 std::cout << "Default/Initializing Constructor invoked! (init_value: " << init_value << ")\n";
	}
	 
	IntPtrCell::IntPtrCell(const IntPtrCell & rhs) : ptr_stored_value{ new int{ *rhs.ptr_stored_value } }
	{
		 // intentionally empty
		 std::cout << "Copy Constructor invoked! (rhs value: " << *rhs.ptr_stored_value << ")\n";
		 ptr_stored_value = new int{ *rhs.ptr_stored_value };
	}
	 
	IntPtrCell::IntPtrCell(IntPtrCell&& rhs) : ptr_stored_value{ rhs.ptr_stored_value }
	{
		 std::cout << "Move Constructor invoked! (rhs value: " << *rhs.ptr_stored_value << ")\n";
		 rhs.ptr_stored_value = nullptr;
	}
	 
	IntPtrCell& IntPtrCell::operator=(const IntPtrCell & rhs)
	{
		 std::cout << "Copy assignment operator invoked! (rhs value: " << *rhs.ptr_stored_value << ")\n";
		 if ( this != &rhs)
		 {
			 *ptr_stored_value = *rhs.ptr_stored_value;
		 }
		 return *this;
	}
	 
	IntPtrCell& IntPtrCell::operator=(IntPtrCell&& rhs)
	{
		 std::cout << "Move assignment operator invoked! (rhs value: " << *rhs.ptr_stored_value << ")\n";
		 std::swap( ptr_stored_value, rhs.ptr_stored_value );
		 return *this;
        }
	 
	IntPtrCell::~IntPtrCell()
	{
		 if (ptr_stored_value != nullptr)
			 std::cout << "Destructor invoked on ptr_stored_value pointing to " << *ptr_stored_value << "\n";
		 else
			 std::cout << "Destructor invoked; ptr_stored_value was moved and thus set to the nullptr\n";
		 delete ptr_stored_value;
	}

	int IntPtrCell::read() const
	{
		return *ptr_stored_value;
	}

	void IntPtrCell::write(int value)
	{
		*ptr_stored_value = value;
	}
}
