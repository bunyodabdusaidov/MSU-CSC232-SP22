/**
 * @file box.h
 * @author Bunyod Abdusaidov (baa823s@missouristate.edu)
 * @brief Base class of Box hierarchy
 * @version 0.1
 * @date 2022-03-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SCS232_BOX_INTERFACE_H__
#define SCS232_BOX_INTERFACE_H__

template<typename T>
class BoxInterface
{
    public:
        virtual T GetItem() const = 0;
        virtual void SetItem(const T& item) = 0;
        virtual ~BoxInterface() = default;
};

#endif //SCS232_BOX_INTERFACE_H__
