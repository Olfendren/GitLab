#include <forward_list>
#include <iostream>
#include <vector>
#include <functional>
#include <list>



std::forward_list< int > random_list(size_t n)
{
    std::forward_list< int > list;
    for (int i = 0; i < n; i++)
    {
        list.push_front( rand()%100+0 );
    }
    
return list;
}

void print_list(const std::forward_list<int> &list)
{
    std::cout<<"( ";
    for (auto const &i: list) 
    {
        std::cout << i << " ";
    }
    std::cout<<") \n";
}

void test_11()
{
    std::cout<<"***Test 2.1*** \n";
    std::forward_list< int > list{ random_list(10) };
    print_list(list);
}


int main ()
{
    std::srand(time(0));
    test_11();
}