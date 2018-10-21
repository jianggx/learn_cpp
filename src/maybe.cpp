#include <iostream>
// the Maybe Monad.

class Adress{
    public:
    std::string* house=nullptr;
};

class Person{
    public:
    Adress* address=nullptr;    
};

template<typename T> class Maybe;
template<typename T> 
Maybe<T> maybe(T* context){
    return Maybe<T>(context);
}

template<typename T> 
class Maybe{
    T* context;
    public :
    Maybe(T* context): context(context){}
    template<typename Func> auto with(Func evaluator){
        return  context!=nullptr ? maybe(evaluator(context)) : nullptr;
    }

    template<typename Func> auto Do(Func action){
        if(context!=nullptr){
            action(context);
        }
        else{
            std::cout<< "do nothing as context is nullptr" << std::endl;
        }
        return *this;
    }
};


int main()
{
    Person p;
    p.address = new Adress();
    p.address->house = new std::string("adb");
    maybe(&p).with([](auto x){return x->address;})
            .with([](auto x){return x->house;})
            .Do([](auto x){std::cout<< *x <<std::endl;});
}