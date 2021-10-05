#include <iostream>
#include <vector>




 double print_tab(std::vector<double> v)
{
    std::cout<<"v=[";
    for (int n :v)
    {
        std::cout<<n<<" ";
    }
    std::cout<<"] \n";
    return 0;
}

std::vector<double> random_tab(std::vector<double> v)
{
    for (int i = 0; i < v.size(); i++)
    {         
    v[i] = rand()%21 + (-10);         
    }
    return v;
}

double test_11()
{
    std::cout<<"***Test 11*** \n";
    const std::vector< double > tab{ 1, -2, 3, -4, 5, -6 };
    print_tab(tab);

    return 0;
}

double test_12()
{
    std::vector< double > tab( 10 );
    std::vector< double > tabr= random_tab(tab);
    print_tab(tabr);
    return 0;
}

int main()
{
   std::srand(time(0));
   test_12();
}