#include <memory>
#include <iostream>
#include <concepts>
#include <ranges>

template <typename T>
T add (T a, T b) requires std::integral<T>{
    return a+b;
}

template <typename T>
concept is_incrementable = requires(T t) {
    {++t} -> std::convertible_to<T>;
};

auto increment(is_incrementable auto a, std::integral auto increment) {
    return a+increment;
}

int main(int argc, char *argv[])
{
    {
        char a_char{10};
        char b_char{10};

        int a_int{10};
        int b_int{20};

        double a_double{10};
        double b_double{10};

        // auto result = add(...,...);
        //std::cout<<"The result is "<<result;

        // TODO try to invoke the functions using
        // the three couple of arguments

        auto result = add(a_char,b_char);
        std::cout<<"The result is "<<result<<std::endl; // prints the char corresponding to 20 -> ASCII: \024
        std::cout<<"The result is "<<+result<<std::endl; // prints 20 ("+" promotes to a type printable as a number, regardless of type)

        auto result_2 = add(a_int,b_int);
        std::cout<<"The result is "<<result_2<<std::endl;

        // auto result = add(a_double,b_double);
        // std::cout<<"The result is "<<result;

        // auto result = add(a_double,b_int); // obviously wrong
        // std::cout<<"The result is "<<result;
    }

    {
        // TODO write an "is_incrementable" concept
        // and use it
        int num{5};
        int incr{2};
        auto result = increment(num,incr);
        std::cout<<"The result is "<<result;
    }

    {
        // TODO generate a series of numbers from 0 to 20
        // and print it only the even. You must use views
        auto is_even = [](int n){return n%2==0;};
        auto even_numbers = std::views::iota(0,20) | std::views::filter(is_even);

        std::cout << std::endl;
        for (auto i : even_numbers){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }   

    return 0;

}