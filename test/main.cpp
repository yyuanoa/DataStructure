# include<iostream>

using namespace std;

template<class t>
struct Node{
    t data;
};

int main()
{
    Node<int> n;

    n.data = 10;

    cout << n.data;
    
    return 0;
}