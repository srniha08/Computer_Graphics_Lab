#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    //cout is used to provide output,output=<<
    //cin means user input
    cout << "Hello." << endl;//\n=endl=end line/new line, ""=<<
    //std::cout << "Hello." << endl;  = if using namespace is not used
    cout << "Hello." << a <<" world." << endl;
    cin >> a;//for input=>>
    cout << a << endl;
    return 0;
}
