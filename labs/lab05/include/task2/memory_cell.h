/**
 * @file memory_cell.h
 * @author Bunyod Abdusaidov (bunyodabdusaidov0@gmail.com)
 * @brief An abstraction of a memory cell.
 * @version 0.1
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CSC232_LAB05_TASK2__
#define CSC232_LAB05_TASK2__

namespace lab05
{
    namespace task2
    {
        /**
         * @brief The abstraction.
         * 
         * @param T type of the value stored in this MemoryCell.
         * @pre T has a default constructor.
         */
        template<typename T>
        class MemoryCell
        {
            public:
                /**
                 * @brief Construct a new Memory Cell object
                 * 
                 * @param value 
                 */
                explicit MemoryCell(T value = T{});

                /**
                 * @brief 
                 * 
                 * @return T 
                 */
                T read() const;

                void write(const T& value);

            private:
                T stored_value;
        };
    }
}

#include "memory_cell.cpp"
#endif // CSC232_LAB05_TASK2__

