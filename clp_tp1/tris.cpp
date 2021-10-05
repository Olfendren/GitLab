#include <iostream>
#include <vector>




 void print_tab( const std::vector<double> &tab)
{
    std::cout<<"tab=[";
    for (int n :tab)
    {
        std::cout<<n<<" ";
    }
    std::cout<<"] \n";
}

void random_tab(std::vector<double> &tab)
{
    for (int i = 0; i < tab.size(); i++)
    {         
    tab[i] = rand()%21 + (-10);         
    }
}

void sort_tab_1(std::vector<double> &tab)
{
    for (int i = 0; i <= tab.size()-2; i++)
    {         
        double mini=i;
    
        for (int j=i+1;j<=tab.size();j++)
            {
                if (tab[j]<tab[mini])
                {
                    mini=j;
                }
            }
        if (mini!=i)
            {
                std::swap(tab[i],tab[mini]);
            }
    }
}
bool less(double a, double b)
{
    if (a<b)
    {
        return true;
    }
    else 
    {
        return false; 
    }
}
bool greater(double a, double b)
{
    if (a>b)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void sort_tab_2(std::vector<double>&tab,bool (*comp)(double, double))
{
    std::sort(tab.begin(),tab.end(),*comp);
}

void test_11()
{
    std::cout<<"***Test 11*** \n";
    const std::vector< double > tab{ 1, -2, 3, -4, 5, -6 };
    print_tab(tab);
}

void test_12()
{
    std::vector< double > tab( 10 );
    random_tab(tab);
    print_tab(tab);
}

void test_13()
{
std::vector< double > tab( 10 );
random_tab(tab);
print_tab(tab);
sort_tab_1(tab);
print_tab(tab);
}
void test_14()
{
    std::vector< double > tab( 10 );
    random_tab(tab);
    print_tab(tab);
    sort_tab_2(tab,less);
    print_tab(tab);
    sort_tab_2(tab,greater);
    print_tab(tab);

}

int main()
{
   std::srand(time(0));
   test_14();
}