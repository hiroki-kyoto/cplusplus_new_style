#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
class N
{
    public:
        int data;
        N()
        {
            data=0;
        }
        N(int n)
        {
            data=n;
        }
        
        N operator>>(N& a)
        {
            a.data=data;
            return a;
        }
        N operator+(N b)
        {
            N k(b.data+data);
            return k;
        }
        friend ostream& operator <<(ostream& os, const N& a)
        {
            os<<a.data;
            return os;
        }
        
    ~N(){}
};
 
 
int main(int argc, const char** argv)
{
    N a(1);
    N b(2);
    N c;
    N arr[5];
    (a>>c)+b>>a;
    cout<<a<<endl; //3
    cout<<b<<endl; //2
    cout<<c<<endl; //1
    // test for array
    (((arr[0]+1>>arr[1])+1>>arr[2])+1>>arr[3])+1>>arr[4];
    // the same as:
        //arr[4]=((arr[3]=(arr[2]=(arr[1]=arr[0]+1)+1)+1)+1);
    cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4]<<endl;
    
    system("pause");
    return 0;
}
