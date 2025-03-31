#ifndef CAT_H
#define CAT_H
#include "feline.h"
class Cat : public Feline
{
public:
    Cat() = default;
    Cat(std::string_view fur_style, std::string_view description);
    ~Cat();
    
    virtual void miaw() const{
        std::cout << "Cat::miaw() called for cat " << m_description << std::endl;
    }
    
    virtual void stream_insert(std::ostream& out)const override{
         out << "Cat [description : " << m_description << ", fur_style : " << 
                m_fur_style << "]";
     }


};

#endif // CAT_H