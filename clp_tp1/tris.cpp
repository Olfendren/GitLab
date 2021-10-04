#include <iostream>
#include <vector>




 double print_tab(std::vector<int> v)
{
    std::cout<<"v=[";
    for (int n :v)
    {
        std::cout<<n<<" ";
    }
    std::cout<<"] \n";
    return 0;
}

double test_11()
{
    std::cout<<"***Test 11*** \n";
    const std::vector< int > tab{ 1, -2, 3, -4, 5, -6 };
    print_tab(tab);

    return 0;
}

int main()
{
    test_11();
}