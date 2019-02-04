#include <iostream>
 
struct Mammalia {};
struct Aves {};
 
struct Cat {
    using biological_class = Mammalia;
};
struct Eagle {
    using biological_class = Aves;
};
struct Dog {
    using biological_class = Mammalia;
};
 
template <typename T>
/* we got rid of the m variable here as we dont need it */
void give_information(T t, Mammalia) {
    std::cout << "This animal belongs to the biological"
        << " class Mammalia" << std::endl;
}
 
template <typename T>
void give_information(T t, Aves) {
    std::cout << "This animal belongs to the biological"
        << " class Aves" << std::endl;
}
 
template <typename T>
void give_information(T t) {
    // let's just use this function to extract bio. class
    give_information(t, typename T::biological_class{});
}
 

int main() {
    Cat cat;
    Eagle eagle;
    Dog dog;
    /* We dont need to add to the call Cat::biological_class()*/);
    give_information(cat);
    give_information(eagle);
    give_information(dog);
}
