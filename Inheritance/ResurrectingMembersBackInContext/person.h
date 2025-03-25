#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>
class Person
{
    friend std::ostream& operator<<(std::ostream& , const Person& person);
    public:
        Person() = default;
        Person(std::string_view fullname,int age,
        const std::string address);
        ~Person();
        
        //Getters
        std::string get_full_name()const;
        
        int get_age()const;
        
        std::string get_address()const;

        int add( int a, int b);

        int add( int a, int b, int c);
        
        void do_something() const;

    public:
        std::string m_full_name{"None"};
    protected: 
        int m_age{0};
    private : 
        std::string m_address{"None"};
};


#endif // PERSON_H