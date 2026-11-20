#include <memory>
#include <iostream>
#include <string> 


void observe(std::weak_ptr<int>& weak)
{
    std::cout << "weak count = " << weak.use_count() << "\n";

    // we need to convert the weak ptr passed to a shared ptr 
    std::shared_ptr<int> p = weak.lock();
    // What should be done here be to create a p that is a shared_ptr?

    if (p)
        std::cout << "\tobserve() is able to lock weak_ptr<>, value=" << *p << " with count = " << p.use_count() << " weak_count = " << weak.use_count() << '\n';
    else
        std::cout << "\tobserve() is unable to lock weak_ptr<>\n";
}

int main()
{
    std::weak_ptr<int> weak;
    std::cout << "weak_ptr<> is not yet initialized\n";
    observe(weak);

    /* would this work? why? */
    // std::unique_ptr<int> p1 = std::make_unique<int>(42);
    // weak = p1;
 
    // what do the curly braces imply? what is their use in this case?
    {
        auto shared = std::make_shared<int>(42);
        weak = shared;
        std::cout << "weak_ptr<> is initialized with shared_ptr\n";
        observe(weak);
    }
 
    std::cout << "shared_ptr<> has been destructed due to scope exit\n";
    observe(weak);

    return 0;
}



// BELOW THIS IS AN EXAMPLE OF MEM LEAK
 
// #include <memory>
// #include <iostream>

// struct B;

// struct A
// {
//     std::shared_ptr<B> b;
//     int data;
//     ~A()
//     {
//         std::cout << "A dtor was called\n";
//     }
// };

// struct B
// {
//     std::shared_ptr<A> a;
//     int data;
//     ~B()
//     {
//         std::cout << "B dtor was called\n";
//     }
// };

// using namespace std;
// int main()
// {
//     // int* d;
//     // {
//         std::shared_ptr<A> a_ptr = std::make_shared<A>();
//         std::shared_ptr<B> b_ptr = std::make_shared<B>();
//         // a_ptr.get()->data = 5;
//         // d = &(a_ptr.get()->data);
//         a_ptr->b = b_ptr;
//         b_ptr->a = a_ptr;

//     // }
//     // try{

//     //     // cout << *d <<endl;
//     // }catch(exception e){
//     //     cout << "d isn't available" <<endl;
//     // }



//     return 0;
// }