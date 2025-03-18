#include <iostream>

int main(){

    //Declare point and reference
    double double_value {12.34};

    double &ref_double_value {double_value}; // Reference to double_value

    double *p_double_value {&double_value}; // Pointer to double_value

    //Reading
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;


    //Writing through pointer
    std::cout << std::endl;
    std::cout << "Writing through pointer" << std::endl;

    *p_double_value = 15.44;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;


    //Writing through reference
    std::cout << std::endl;
    std::cout << "Writing through reference" << std::endl;

    ref_double_value = 18.44;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    // Once the reference initialized, it cannot be changed to refer to a different object.
    std::cout << std::endl;
    std::cout << "Once the reference initialized, it cannot be changed to refer to a different object." << std::endl;
    double other_double_value {22.44};

    //This works, but it doesn't make ref_double_value refer to other_double_value
    //Itmerely changes the value referenced by ref_double_value to 22.44
    ref_double_value = other_double_value;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    //If you change ref_double_value now, other_double_value stays the same
    //proving that ref_double_value is not a reference to other_double_value
    std::cout << std::endl;
    std::cout << "If you change ref_double_value now, other_double_value stays the same" << std::endl;
    ref_double_value = 233.333;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    std::cout << "other_double_value : " << other_double_value << std::endl;


    // A pointer can point somewhere else
    std::cout << std::endl;
    std::cout << "A pointer can point somewhere else : " << std::endl;

    p_double_value = &other_double_value;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    std::cout << "other_double_value : " << other_double_value << std::endl;

    std::cout << std::endl;
    std::cout << "Changing the value pointed by p_double_value" << std::endl;
    *p_double_value = 555.66;

    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    std::cout << "other_double_value : " << other_double_value << std::endl;

    //We can translate that a reference behaves like a constant pointer
    //but they have a much friendlier syntax as they don't require dereferencing
    //to read and write throught referenced data

    double *const const_p_double_value {&double_value}; // Constant pointer to double_value
    // const_p_double_value = &other_double_value; // Error



	return 0;
}
