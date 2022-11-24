#include<iostream>
using namespace std;

int main(){
    cout << (0xff & 0x7 || 0x9) << endl; /// 1
    ///
    
    int a = 0x1234;
    char *p = (char*) &a;
    printf("*p=0x%x\n", (int)*p);
    printf("*(p+1)=0x%x\n",(int)*(p+1));
    printf("*(p+2)=0x%x\n",(int)*(p+2));
    return 0;
}
