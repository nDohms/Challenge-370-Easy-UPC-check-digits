#include <iostream>
#include <string>
#include<math.h>

using namespace std;
/*I use the a method where i convert a char into an int,
because char var = "0" becomes int var = 48 i have to subtract
48 from every converted char to int number.*/

/*If the length of the code is smaller than 11
the upc1-function adds zeros in front of the string
to get the length of the code to be equal to 11;*/
int upc1(string code)
{
    while(code.length()<11)
    {
        code = "0" + code;
    }
    int sum = 0;
    int x = 0;
    while(x<2){
      for(unsigned int i = 0+x; i < code.length();i+=2)
    {
        sum += (int)code[i]-48;
    }
    if(x < 1){sum *= 3;}
    x++;
    }
    int mod = sum%10;
    if (mod != 0){
        mod = 10 - mod;
    }
    return mod;
}
/*if the length of the code is smaller than 11,
the upc2 function shifts the start of the for loops to make up
for the missing zeros in front of the code*/
int upc2(string code)
{
    int x = 0;
    if(code.length()%2 == 0)
    {
        x = 1;
    }
    int sum = 0;
    for(unsigned int i=0+x; i < code.length();i+=2)
    {
        sum += (int)code[i]-48;
    }
    sum *= 3;
    for(unsigned int i=1-x; i < code.length();i+=2)
    {
        sum += (int)code[i]-48;
    }
    int mod = sum%10;
    if (mod != 0){
        mod = 10 - mod;
    }
    return mod;
}

int main()
{
    cout << upc2("4210000526") << endl;
    cout << upc2("3600029145") << endl;
    cout << upc2("12345678910") << endl;
    cout << upc2("1234567") << endl;
    return 0;
}
