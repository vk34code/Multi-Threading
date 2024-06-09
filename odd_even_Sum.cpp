//Multithreading to find odd and evensum

#include<bits/stdc++.h>
#include<mutex>
#include<thread>

using namespace std;

typedef long long ull ;

ull oddsum=0;
ull evensum=0;

 void odd(int start, int end)
{
    for(int i=start;i<end;i++)
    {
        if(i%2==1)
        oddsum+=i;
    }

    cout<<"Sum of odd numbers: "<<oddsum<<endl;
}

void even(int start, int end)
{
    for(int i=start;i<end;i++)
    {
        if(i%2==0)
        evensum+=i;

    }
    cout<<"sum of even numbers: "<<evensum<<endl;
}

int main()
{   int start,end;
    cout<<"Enter the start & end:  "<<endl;
    cin>>start>>end;
    std::thread T1(odd,start,end);
    std::thread T2(even,start,end);
    T1.join();
    T2.join();
    return 0;
}
