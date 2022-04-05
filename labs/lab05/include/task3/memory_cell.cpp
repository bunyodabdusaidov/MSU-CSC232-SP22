#include "memory_cell.h"

template<typename T>
lab05::task3::MemoryCell<T>::MemoryCell(T value) : stored_value(value)
{
    // intentionally empty
}

template<typename T>
T lab05::task3::MemoryCell<T>::read( ) const
{
    return stored_value;
}

template<typename T>
void lab05::task3::MemoryCell<T>::write(const T& value)
{
    stored_value = value;
}