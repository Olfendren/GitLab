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

std::forward_list< int > map_iter(const std::forward_list<int> &list, std::function<int( int )>sign)
{
    std::forward_list<int>res;

    for (auto const& i : list) 
    {
        res.push_front(sign(i));

    }  
return res;
}

std::forward_list< int > filter_iter(const std::forward_list<int> &list, std::function<bool( int )>sign)
{
    std::forward_list<int>res2;

    for (auto const& i : list) 
    {
        if (sign(i))
        {
            res2.push_front(i);
        }

    }  
return res2;

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
void test_23()
{
    std::forward_list< int > list{ random_list(10) };
    print_list(list);
    auto res=map_iter(list,[](int a) {return a*3; });
    print_list(res);
    auto res2=filter_iter(res,[](int a){if (a % 2==0){return true;}else{return false;}});
    print_list(res2);

}
void test_24()
{
    std::forward_list< int > list{ random_list(10) };
    print_list(list);
    int coeff=rand()%5+1;
    std::cout<<"Valeur du coefficient aléatoire: "<<coeff<<"\n";

    auto res=map_iter(list,[coeff](int a) {return a*coeff; });
    print_list(res);
    auto res2=filter_iter(res,[](int a){if (a % 2==0){return true;}else{return false;}});
    print_list(res2);
}

int main ()
{
    std::srand(time(0));
    test_24();
}