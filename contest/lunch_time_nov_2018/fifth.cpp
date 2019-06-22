#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
namespace mp = boost::multiprecision;
using namespace std;
const int lim = 1001;
int main()
{
    
    mp::cpp_int u = 1;
    for(int i = 1; i <= 100; i++)
        u *= i;
 
    cout << "100! = " << u << '\n';
 
    mp::cpp_int v = u / 100;
 
    cout << "99! = " << v << '\n';
 
 
}