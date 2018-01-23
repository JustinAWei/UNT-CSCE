#include "doubly_linked_list.h"
#include <iostream>

using namespace std;


int main()
{
 int n;
 string w;
 doubly_linked_list d;
 cin>>n;
 while(n>0)
   {
    cin >> w;
    d.insert(w);
    n--;
   }

 d.print_forward();
 d.print_backward();

 return 0;
}
