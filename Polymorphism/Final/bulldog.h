#ifndef BULLDOG_H
#define BULLDOG_H
#include "dog.h"

class BullDog : public Dog
{
    public: 
        BullDog();
        virtual ~BullDog();

        // Will throw a complier error
        // virtual void run() const override{
        //     std::cout << "BullDog::run called for : " << m_description << std::endl;
        // }
};


#endif // BULLDOG_H