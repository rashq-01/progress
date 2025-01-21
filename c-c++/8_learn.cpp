#include <iostream>
#include <math.h>
using namespace std;

// Pattern 1
// 12345
// 12345
// 12345
// 12345
// 12345
// 12345

// solution

// #include<iostream>
// using namespace std;
// int main(){
//     int row;
//     int column;
//     cout<< "Enter row";
//     cin>> row;
//     cout << "Enter column";
//     cin>> column;
//     int i = 1;
//     while (i<=column)
//     {
//         int j = 1;
//         while (j<=row)
//         {
//             cout<<j;
//             j = j+1;
//         }
//         cout<<endl;
//         i++;
//     }

// }

// Pattern 2
// 123
// 456
// 789

// int main(){
//     int n;
//     cout<<"Enter number"<<endl;
//     cin>>n;
//     int i =1;
//     int count=1;

//     while (i<=n)
//     {
//         int j =1;
//         while (j<=n)
//         {
//             cout<< count<<"";
//             count++;
//             j++;
//         }
//         i++;
//         cout<<endl;

//     }

// }

// Pattern 3
//        *
//        * *
//        * * *
//        * * * *
//        * * * * *
//        * * * * * *

// int main(){
//     int n;
//     cout<< "Enter number"<<endl;
//     cin>>n;
//     int i=1;
//     while (i<=n)
//     {
//         int j =1;
//         while (j<=i)
//         {
//             cout<<"* ";
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }

// }

// Pattern 4

//        * * * * *
//        * * * *
//        * * *
//        * *
//        *

// int main(){
//     int n;
//     cout<< "Enter number"<<endl;
//     cin>>n;
//     int i =n;
//     while (i>=1)
//     {
//         int j=i;
//         while (j>=1)
//         {
//             cout<<"* ";
//             j=j-1;
//         }
//         cout<<endl;
//         i=i-1;
//     }

// }

// Pattern 4

//      1
//      22
//      333
//      4444
//      55555

// int main(){
//     int n;
//     cout<<"Enter number";
//     cin>>n;
//     int i =1;
//     while (i<=n)
//     {
//         int j = 1;
//         while (j<=i)
//         {
//             cout<<i;
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }

// }

// Pattern 5
//        55555
//        4444
//        333
//        22
//        1

// int main(){
//     int n;
//     cout<<"Enter number";
//     cin>>n;
//     int i =n;
//     while (i>=1)
//     {
//         int j = i;
//         while (j>=1)
//         {
//             cout<<i;
//             j=j-1;
//         }
//         cout<<endl;
//         i=i-1;
//     }

// }

// Pattern 6

//          1
//          2 3
//          4 5 6
//          7 8 9 10
//          11 12 13 14 15

// int main(){
//     int n;
//     cout<<"Enter number";
//     cin>>n;
//     int i=1;
//     int count =1;
//     while (i<=n)
//     {
//         int j =1;
//         while (j<=i)
//         {
//             cout<<count <<" ";
//             count++;
//             j++;
//         }
//         cout<<endl;
//         i++;

//     }

// }

// Patttern 7
//        1
//        2 1
//        3 2 1
//        4 3 2 1
//        5 4 3 2 1

// int main(){
//     int n;
//     cout<< "Enter number: ";
//     cin>>n;
//     int i=1;
//     int count =1;
//     while (i<=n)
//     {
//         int j = i;
//         while (j>=1)
//         {
//             cout<<" "<<j;
//             j=j-1;

//         }
//         i++;
//         cout<<endl;

//     }

// }

// Pattern 8
//   also A= 65 in integer value

//       A A A A A
//       B B B B B
//       C C C C C
//       D D D D D
//       E E E E E

// int main(){
//     int n;
//     int row;
//     cout<<"Enter number: ";
//     cin>>n;
//     cout<<"Enter row: ";
//     cin>>row;
//     int i =1;
//     while (i<=n)
//     {
//         int j =1;
//         while (j<=row)
//         {
//             char letter = 'A' + i -1 ;
//             cout<< " "<<letter;
//             j++;
//         }
//         i++;
//         cout<<endl;

//     }

// }

// Pattern 9

//           A B C D E
//           A B C D E
//           A B C D E
//           A B C D E
//           A B C D E

// int main(){
//     int n,row;
//     cout<<"Enter number: ";
//     cin>>n;
//     cout<<"Enter row: ";
//     cin>>row;
//     int column = 1;
//     while (column<=n)
//     {
//         int j =1;
//         char letter = 'A' + j - 1;
//         while (j<=row)
//         {
//             cout<<" "<<letter;
//             letter++;
//             j++;
//         }
//         column++;
//         cout<<endl;

//     }

// }

// Pattern 10

//       A B C
//       D E F
//       G H I
//       J K L
//       M N O

// int main(){
//     int n;
//     int column;
//     cout<<"Enter number";
//     cin>>n;
//     cout<<"Enter column";
//     cin>>column;
//     char letter = 'A';
//     int i =1;
//     while (i<=n)
//     {
//         int j =1;
//         while (j<=column)
//         {
//             cout<<" "<<letter;
//             j++;
//             letter++;
//         }
//         i++;
//         cout<<endl;

//     }

// }

// Pattern 11

//    E D C B A
//    E D C B
//    E D C
//    E D
//    E

// int main(){
//     int num;
//     cout<<"Enter number";
//     cin>>num;
//     int i =num;
//     while (i>=1)
//     {
//         int j = i;
//         char result = 'A' + num-1;
//         while (j>=1)
//         {
//             cout<<" "<<result;
//             result=result-1;;
//             j=j-1;

//         }
//         i=i-1;
//         cout<<endl;

//     }

// }

// Pattern 12

//   E
//   D E
//   C D E
//   B C D E
//   A B C D E

// int main(){
//     int num;
//     cout<<"Enter number: ";
//     cin>>num;
//     int row = 1;
//     while (row<=num)
//     {
//         int col = 1;
//         char start = 'A' + num - row;
//         while (col<=row)
//         {
//             cout<<" "<<start;
//             start++;
//             col++;
//         }
//         row++;
//         cout<<endl;

//     }

// }

// Pattern 13

//            *
//           **
//          ***
//         ****
//        *****

// int main(){
//     int num;
//     cout<<"Enter number";
//     cin>>num;
//     int row =1;
//     while (row<=num)
//     {
//         int space = num - row;
//         while (space>0)
//         {
//             cout<<" ";
//             space= space-1;
//         }
//         int column = 1;
//         while (column<=row)
//         {
//             cout<<"*";
//             column++;
//         }
//         row++;
//         cout<<endl;

//     }

// }

// Pattern 14

//           *****
//            ****
//             ***
//              **
//               *

// int main(){
//     int num;
//     cout<<"Enter number: ";
//     cin>>num;
//     int row = num;
//     while (row>=1)
//     {
//         int space = num - row;
//         while (space>=1)
//         {
//             cout<<" ";
//             space=space-1;
//         }
//         int column = row;
//         while (column>=1)
//         {
//             cout<<"*";
//             column = column - 1;
//         }
//         row = row -1;
//         cout<<endl;

//     }

// }

// Pattern 15

//            1
//           121
//          12321
//         1234321
//        123454321

// int main(){
//     int num;
//     cout<<"Enter number";
//     cin>>num;
//     int row =1;
//     while (row<=num)
//     {
//         int space = num - row;
//         while (space>=1)
//         {
//             cout<<" ";
//             space = space-1;
//         }
//         int column = 1;
//         while (column<=row)
//         {
//             cout<<column;
//             column++;
//         }
//         int column2 = row-1;
//         while (column2)
//         {
//             cout<<column2;
//             column2 = column2-1;
//         }
//         int space2 = num-row;
//         while (space2>=1)
//         {
//             cout<<" ";
//             space2 =space2-1;

//         }

//         row++;
//         cout<<endl;

//     }

// }

// Pattern 16

//           1234554321
//           1234**4321
//           123****321
//           12******21
//           1********1

// int main(){
//     int num;
//     cout<<"Enter number: ";
//     cin>>num;
//     int row = 1;
//     while (row<=num)
//     {
//         int num1 = 1;
//         int temp1 = num - row + 1;
//         while (num1<=temp1)
//         {
//             cout<<num1;
//             num1++;
//         }
//         int star1 = row-1;
//         while (star1)
//         {
//             cout<<"*";
//             star1 = star1 -1;
//         }
//         int star2 = row-1;
//         while (star2)
//         {
//             cout<<"*";
//             star2 = star2 -1;
//         }
//         int num2 = num - row +1;
//         while (num2>=1)
//         {
//             cout<<num2;
//             num2 = num2-1;
//         }
//         cout<<endl;
//         row++;

//     }

// }
// int main(){
//     int A;
//     int B;
//     cout<<"Enter two numbers A and B: ";
//     cin>>A;
//     cin>>B;
//     cout<<"A|B = "<<(A|B)<<endl;
//     cout<<"A&B = "<<(A&B)<<endl;
//     cout<<"A^B = "<<(A^B)<<endl;
//     cout<<"~B = "<<(~B)<<endl;
//     cout<<"~A = "<<(~A)<<endl;
// }

// int main(){
//     int i = 3;
//     cout<<i<<endl;
//     int a = i++;
//     cout<<i<<endl;
//     cout<<a<<endl;
// }

//                        Fibonacci series

// int main(){
//     int num;
//     int first;
//     cout<<"Enter number: ";
//     cin>>num;
//     cout<<"Enter fist number: ";
//     cin>>first;
//     int second = first + 1;
//     cout<<first<<" "<<second<<" ";
//     for (int i = 1; i <= num; i++)
//     {
//         int sum = first + second;
//         cout<<sum<<" ";
//         first = second;
//         second = sum;
//     }

// }

//   Checking prime number?

// int main(){
//     int num;
//     cout<<"Enter number";
//     cin>>num;

//     bool result = 1;
//     for (int i = 2; i < num; i++)
//     {
//         if (num%i == 0)
//         {
//             result =0;
//             break;
//         }

//     }
//     if (result == 0)
//     {
//         cout<<"Not a prime Number";
//     }
//     else{
//         cout<<"Prime Number";
//     }

// }

// int main(){
//     int num;
//     cout<<"Enter number: ";
//     cin>>num;
//     int result = 0;
//     int i = 0;
//     while (num != 0)
//     {
//         int bits = num & 1;
//         result = (bits * pow(10,i)) + result;
//         i++;
//         num = num>>1;

//     }
//     cout<<result;

// }







                     //Complement of base 10

// #include <iostream>
// #include <cmath>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter number: ";
//     cin>>n;
//     int m = n;
//     int bits = ~n;
//     int temp = 0;
//     while (m != 0)
//     {
//         temp = (temp << 1) | 1;
//         m = m>>1;
//     }
//     int result = temp & bits;
//     cout<<result;
    
// }






// #include <iostream>
// #include<math.h>

// int main(){
//     int num;
//     std::cout<<"Enter number: ";
//     std::cin>>num;
//     int result = 0;
//     int i = 0;
//     while (num != 0)
//     {
//         int bits = num & 1;
//         result = (bits * pow(10,i)) + result;
//         i++;
//         num = num>>1;

//     }

//     std::cout<<"The number in binary is: "<<result<<std::endl;

//     int result1 = 0;
//     while (result>0){
//         int bits = result %10;
//         if(bits=0){
//             result1 = result1 * 10 + 1;
//         }
//         else{
//             result1 = result1 * 10 + 0;
//         }
//         result = result/10;
//     }
    
//     std::cout<<"The reverse binary is "<<result1<<std::endl;
//     int k=0;
//     int result2 = 0;
//     while(result1 != 0){
//         int bit1 = result1%10;
//         if(bit1=1){
//             result2 = result2 + pow(2,k);
//         }
//         k++;
//         result1 = result1/10;
//     }
//     std::cout<<"The number is reverse binary is "<<result2<<std::endl;
    
    
    
    
// }


// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//     int x;
//     cout<<"Enter number";
//     cin>>x;
//     int m = abs(x);
//     int result = 0;
//         int i = 0;
//         while( m != 0){
//             int digit = m%10;
//             result = (digit * pow(10,i)) + result;
//             i++;
//             m = m/10;
//         }
//         if(result == abs(x)){
//             cout<<"True";
//         }
//         else{
//             cout<<"False";
//         }
// }