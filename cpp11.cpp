#include <iostream>
#include <vector>
#include "add.h"


// 1, initialize list
class MyVector{
    std::vector<int> m_vec;
    public:
        MyVector(const std::initializer_list<int>& list){ // initialize list constructor
            for(auto x : list){
                m_vec.push_back(x);
            }
        }
};

void test_initializerList(){
    int arr[3] = {1,2,3}; // c++ 03
    std::vector<int> b = {1,2,3}; // initializer list
    MyVector myvec = {1,2,3}; // // initializer list
}

// 2, uniform initializer
class AggregateIntializer{
    public:
    int age;
    std::string name;
};

class RegularConstructor{
    public:
    RegularConstructor (int age, std::string name){

    }
};

void test_uniformInitializer(){
    AggregateIntializer a = {1, "leo"}; // c++ 03, aggregate initalizer
    AggregateIntializer a2{1, "leo"}; // c++ 03, aggregate initalizer

    RegularConstructor b = {1, "leo"}; // regular constructor
    RegularConstructor b2 {1, "leo"}; // regular constructor
   
    MyVector myvec = {1,2,3};  // initializer list
    MyVector myvec2{1,2,3};  // initializer list

    // priority: initializer list > regular constructor > aggregate initalizer
}

// 3, auto type
int test_auto(){
    auto a = 3; // type inferece
    auto b = "abc";
    auto c = 0.4;
    auto d = c;

    std::vector<int> v = {1,2,3}; // initializer list

    // c++ 03
    for(std::vector<int>::iterator it = v.begin(); it !=v.end(); ++it){
        std::cout << *it << std::endl;
    }

    // auto type
    for(auto it = v.begin(); it !=v.end(); ++it){
        std::cout << *it << std::endl;
    }
    return 0;
}

// 4, foreach
void test_foreach()
{
    std::vector<int> v = {1,2,3}; // initializer list
    // foreach works on class that has begin() and end()
    for(auto i : v){
        std::cout << i << std::endl;
    }

    for(auto &i : v){
        ++i; // change value in v
    }
}

// 5, nullptr
// NULL is just defined as 0, nullptr specify to pointer to avoid ambiguty
void foo(int i) { std::cout << i << std::endl; }
void foo(char* pc) { std::cout << R"(foo(char* pc) )" << std::endl; }
void test_nullptr()
{
    // foo(NULL); // not compile
    foo(nullptr); // call foo(char* pc)
}

// 6, enum class
// c++ 03
enum Apple {green, red};
enum Orange {big, small};
enum class Apple_C {green, red};
enum class Orange_C {big, small};

void test_enumClass(){
    Apple a = Apple::green;
    Orange b = Orange::big;
    // can compare! not make sense
    if(a == b){ 
        std::cout << "can compare! not make sense" << std::endl;
    }

    Apple_C a2 = Apple_C::green;
    Orange_C b2 = Orange_C::big;
    // not compile, that make sense
    /*
    if(a2 == b2){ 
        std::cout << "can compare! not make sense" << std::endl;
    }
    */
}

// 7, static assert
void test_staticAssert(){
    // compile time assert, faster
    static_assert(sizeof(int)==4);
}

// 8, delegate constructor
class DelegateConstructor{
    public:
    DelegateConstructor(){
        std::cout<< "some base construction" << std::endl; 
    }

    // delegate constructor
    DelegateConstructor(int x): DelegateConstructor(){
        std::cout<< "do some other things" << std::endl;
    }

};

void test_delegateConstructor(){
    DelegateConstructor d(2);
}

// 9, override
class Dog{
    public:
    virtual void foo(int x) const { std::cout<< "Dog foo" << std::endl; };
};

class YellowDog : public Dog{
    public:
    void foo(int x) const override { std::cout<< "YellowDog foo" << std::endl; };
};

// 10, final
// final class  : no subclass
// final virtual : no override in subclass
class BlackDog final : public Dog {
    void foo(int x) const override final { std::cout<< "YellowDog foo" << std::endl; };
};

// 11, compile generate default constructor
class DefConstructor{
    public:
    DefConstructor(int x){
        std::cout<< "no default constructor will be generated as already has this" << std::endl;
    }
    DefConstructor() = default; // force to generate a default constructor
};

// 12, delete
class Delete{
    public:
    Delete(int x){};
    Delete(double d) = delete; // delete this constructor explicitly 
    Delete& operator=(const Delete& other) = delete; // delete the assign operator
};

void test_delete()
{
    Delete d(1); // works
    //Delete e(1.5); // not compile, as the Delete(double d) is deleted 
    //d = e; // not compile, as the operator= function is deleted 
}

// 13, constexpr
constexpr int A(int x){return x*3;}
void test_constexpr(){
    int arr[A(1)+2]; // this works
    int y = A(2) + 3;  // computer at comile time
}

// 14, new string literal
void test_string_literals(){
    // c++ 03 way
    const char* cpp03 = "abc";

    // c++ 11
    const char* a = u8"abc"; // utf8 string
    const char16_t* b = u"abc"; // utf16 string
    const char32_t* c = U"abc"; // utf32 string

    const char* d = R"(abc)"; // raw string, note that the () is the row string delimeter
}

// 15, lambda
int test_lambda(int x){
    int y =5;
    auto func = [](int x){return x - 5;}; 
    auto func2 = [&](int x){return x - y;}; // & for variable capture
    return func(x)+func2(x);
}

int main() {
    test_initializerList();
    test_uniformInitializer();
    test_auto();
    test_foreach();
    test_nullptr();
    test_enumClass();
    test_staticAssert();
    test_delegateConstructor();
    test_delete();
    test_constexpr();
    test_string_literals();
    test_lambda(3);

    return 0;
}