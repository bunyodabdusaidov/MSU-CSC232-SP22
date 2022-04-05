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

#ifndef CSC232_LAB05_TASK1__
#define CSC232_LAB05_TASK1__

namespace lab05
{
    namespace task1
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
                explicit MemoryCell(T value = T{}) : stored_value{ value }
                {
                    // explicitly empty
                }

                /**
                 * @brief 
                 * 
                 * @return T 
                 */
                T read() const
                {
                    return stored_value;
                }

                void write(const T& value)
                {
                    stored_value = value;
                }

            private:
                T stored_value;
        };
    }
}

#endif // CSC232_LAB05_TASK1__

