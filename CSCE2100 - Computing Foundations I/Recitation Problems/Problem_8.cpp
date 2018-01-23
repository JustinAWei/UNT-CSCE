#include<iostream>

using namespace std;

void print_data(int *s, int k)
{
   for(int j = 0; j < k; j++)
     cout << s[j] << " ";
   cout << endl;
}


void print_data_reverse(int *s, int j)
{
  if(j < 0)
    return;
  else { cout << s[j] << " "; print_data_reverse(s, j-1);}
}

int main()
{

  int stack[100];
  int n;
  int data;

  cout << "Enter the size of your stack: ";
  cin >> n;
  cout << "Enter possible data for your stack: ";

  for(int i = 0; i < n; i++)
  {
     cin >> data;
     stack[i] = data;
  }

  print_data_reverse(stack, n-1);
  return 0;
}
