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

std::forward_list< int > map_iter(const std::forward_list<int> &list, std::function<int( int )>sig)
{
    std::forward_list<int>res;

    for (auto const& i : list) 
    {
        res.push_front(sig(i));

    }  
return res;
}




void test_21()
{
    std::cout<<"***Test 2.1*** \n";
    std::forward_list< int > list{ random_list(10) };
    print_list(list);
}
void test_22()
{
    std::forward_list< int > list{ random_list(10) };
    print_list(list);
    auto res=map_iter(list,[](int a) {return a*3; });
    print_list(res);

}

int main ()
{
    std::srand(time(0));
    test_22();
}