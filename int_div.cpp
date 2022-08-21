#include<bits/stdc++.h>
using namespace std;
class NonResDiv{
public:
string a;
string q;
string m;
string mc;
int rem;
int quotient;
string bin_add(string s1,string s2){
string ans=(s1.length()>=s2.length())?s1:s2;
int c=0;
int i=s1.length()-1;
int j=s2.length()-1;
int k=ans.size()-1;
//cout<<"Ans: "<<ans<<" "<<endl;
while(i>=0 and j>=0){
// cout<<"a: "<<s1[i]<<" "<<"b: "<<s2[j]<<"c: "<<c<<endl;
if(c==1){
if(s1[i]=='0' and s2[j]=='0')
{
c=0;
ans[k]='1';
}
else if (s1[i]=='1' and s2[j]=='1')
{
c=1;
ans[k]='1';
}
else
{
c=1;
ans[k]='0';
}
}
else{
if(s1[i]=='0' and s2[j]=='0')
{
c=0;
ans[k]='0';
}
else if (s1[i]=='1' and s2[j]=='1')
{
c=1;
ans[k]='0';
}
else
{
c=0;
ans[k]='1';
}
}
i--;
j--;
k--;
//cout<<"Ans: "<<ans<<" "<<endl;
}
while(k!=0 and c!=0){
if(s1[i]=='1'){
ans[k]='0';
c=1;
}
else{
ans[k]='1';
c=0;
}
k--;
i--;
}
return ans;
}
string complement_2(string m)
{
for(int i=0;i<m.size();i++){
m[i]=(m[i]-'0'==0)?'1':'0';
}
string ans=bin_add(m,"1");
return ans;
}
string to_binary(int d){
string bin="";
while(d>0){
bin.insert(0,to_string(d%2));
d/=2;
}
return bin;
}
void shift_left(){
for(int i=0;i<a.size()-1;i++){
a[i]=a[i+1];
}
a[a.size()-1]=q[0];
for(int i=0;i<q.size()-1;i++){
q[i]=q[i+1];
}
q[q.size()-1]='_';
// cout<<" A: "<<a<<" "<<q<<endl;
}
void divide(){
cout<<" A: "<<a<<" "<<q<<endl<<endl;
for(int i=0;i<q.size();i++){
int s=a[0];
shift_left();
if(s=='0'){
cout<<"A-M(since A[0]=0)"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
cout<<"-M: "<<mc<<endl;
a=bin_add(a,mc);
}
else{
cout<<"A+M(since A[1]=1)"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
cout<<"+M: "<<m<<endl;
a=bin_add(a,m);
}
if(a[0]=='1')
{
q[q.size()-1]='0';
}
else{
q[q.size()-1]='1';
}
cout<<"-----------------------"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
cout<<"-----------------------"<<endl;
cout<<endl;
}
if(a[0]=='1'){
a=bin_add(a,m);
cout<<"-----------------------"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
cout<<"-----------------------"<<endl;
}
}
void bin_to_decimal(){
rem=0;
quotient=0;
int n=a.length();
int m=q.length();
int dummy=1;
for(int i=n-1;i>=0;i--){
if(a[i]=='1'){
rem+=dummy;
}
dummy*=2;
}
dummy=1;
for(int i=m-1;i>=0;i--){
if(q[i]=='1'){
quotient+=dummy;
}
dummy*=2;
}
cout<<"\nRemainder: "<<rem<<"(A: "<<a<<")"<<endl;
cout<<"Quotient: "<<quotient<<"(Q: "<<q<<")"<<endl;
}
void perform_division(){
printf("\n\t\t\t```````````````````````````````````````````````````");
printf("\n\t\t\t` ********************************************* `");
printf("\n\t\t\t` * NON-RESTORING DIVISION * `");
printf("\n\t\t\t` ********************************************* `");
printf("\n\t\t\t```````````````````````````````````````````````````");
cout<<"\nSteps involved in Non -Restoring division........"<<endl;
cout<<"\nStep-1: First the registers are initialized with corresponding values (Q = Dividend, M = Divisor, A = 0, n = number of bits in dividend)"<<endl;
cout<<"\nStep-2: Then the most significant bit of the A is checked if it is 0 then Add M else add -M"<<endl;
cout<<"\nStep-3: Then the content of register A and Q is shifted left as if they are a single unit"<<endl;
cout<<"\nStep-4: Then the most significant bit of the A is checked if it is 0 the least significant bit of Q is set to 1 otherwise if it is 1 the least significant bit of Q is set to 0 and value of register A is restored i.e the value of A before the subtraction with M"<<endl;
cout<<"\nStep-5: The value of counter n is decremented"<<endl;
cout<<"\nStep-6: If the value of n becomes zero we get of the loop otherwise we repeat from step 2"<<endl;
cout<<"\nStep-7: Finally, the register Q contain the quotient and A contain remainder"<<endl;
cout<<endl;
int dividend,divisor;
cout<<"Enter the dividend: ";
cin>>dividend;
cout<<"\nEnter the divisor: ";
cin>>divisor;
if(divisor==0){
cout<<"No you can't divide by 0.."<<endl;
return;
}
string divi_d=to_binary(dividend);//covert given to binary format
string divi_r=to_binary(divisor);
//cout<<divi_d<<"\n"<<divi_r<<endl;
divi_r.insert(0,to_string(0));//add sign bit for because a and m should be fo same length
//divi_d.insert(0,to_string(0));
/*cout<<divi_d<<"\n"<<divi_r<<endl;
string a=bin_add(divi_d,divi_r) ;
cout<<a<<endl;*/
a="";
for(int i=0;i<divi_r.size();i++){
a+='0';
}
m=divi_r;
q=divi_d;
mc=complement_2(m);
cout<<"\nBasic Calculations..."<<endl;
cout<<"***********************************"<<endl;
cout<<"* -M : "<<mc<<" "<<endl;
cout<<"* Q : "<<q<<" "<<endl;
cout<<"* M : "<<m<<" "<<endl;
cout<<"* Iterations : "<<q.size()<<" "<<endl; cout<<"***********************************"<<endl;
cout<<"\nSTEP BY STEP EXECUTION.........."<<endl;
divide();
bin_to_decimal();
rem=0;
quotient=0;
}
};
class ResDiv{
public:
string a;
string q;
string m;
string mc;
int rem;
int quotient;
string bin_add(string s1,string s2){
string ans=(s1.length()>=s2.length())?s1:s2;
int c=0;
int i=s1.length()-1;
int j=s2.length()-1;
int k=ans.size()-1;
//cout<<"Ans: "<<ans<<" "<<endl;
while(i>=0 and j>=0){
// cout<<"a: "<<s1[i]<<" "<<"b: "<<s2[j]<<"c: "<<c<<endl;
if(c==1){
if(s1[i]=='0' and s2[j]=='0')
{
c=0;
ans[k]='1';
}
else if (s1[i]=='1' and s2[j]=='1')
{
c=1;
ans[k]='1';
}
else
{
c=1;
ans[k]='0';
}
}
else{
if(s1[i]=='0' and s2[j]=='0')
{
c=0;
ans[k]='0';
}
else if (s1[i]=='1' and s2[j]=='1')
{
c=1;
ans[k]='0';
}
else
{
c=0;
ans[k]='1';
}
}
i--;
j--;
k--;
//cout<<"Ans: "<<ans<<" "<<endl;
}
while(k!=0 and c!=0){
if(s1[i]=='1'){
ans[k]='0';
c=1;
}
else{
ans[k]='1';
c=0;
}
k--;
i--;
}
return ans;
}
string complement_2(string m)
{
for(int i=0;i<m.size();i++){
m[i]=(m[i]-'0'==0)?'1':'0';
}
string ans=bin_add(m,"1");
return ans;
}
string to_binary(int d){
string bin="";
while(d>0){
bin.insert(0,to_string(d%2));
d/=2;
}
return bin;
}
void shift_left(){
for(int i=0;i<a.size()-1;i++){
a[i]=a[i+1];
}
a[a.size()-1]=q[0];
for(int i=0;i<q.size()-1;i++){
q[i]=q[i+1];
}
q[q.size()-1]='_';
// cout<<" A: "<<a<<" "<<q<<endl;
}
void divide(){
cout<<" A: "<<a<<" "<<q<<endl;
for(int i=0;i<q.size();i++){
cout<<"******Iteration: "<<i+1<<"********"<<endl;
int s=a[0];
shift_left();
cout<<"A-M"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
cout<<"-M: "<<mc<<endl;
a=bin_add(a,mc);
cout<<"-----------------------"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
if(a[0]=='1')
{
q[q.size()-1]='0';
cout<<"A+M(since A[0]=1)"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
cout<<"+M: "<<m<<" "<<endl;
a=bin_add(a,m);
}
else{
q[q.size()-1]='1';
}
cout<<"-----------------------"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
cout<<"-----------------------"<<endl;
cout<<endl;
cout<<endl;
}
if(a[0]=='1'){
cout<<"A+M(since A[0]=1)"<<endl;
a=bin_add(a,m);
cout<<"-----------------------"<<endl;
cout<<" A: "<<a<<" "<<q<<endl;
cout<<"-----------------------"<<endl;
}
}
void bin_to_decimal(){
rem=0;
quotient=0;
int n=a.length();
int m=q.length();
int dummy=1;
for(int i=n-1;i>0;i--){
if(a[i]=='1'){
rem+=dummy;
}
dummy*=2;
}
dummy=1;
for(int i=m-1;i>=0;i--){
if(q[i]=='1'){
quotient+=dummy;
}
dummy*=2;
}
cout<<"\nRemainder: "<<rem<<"(A: "<<a<<")"<<endl;
cout<<"Quotient: "<<quotient<<"(Q: "<<q<<")"<<endl;
}
void perform_division(){
printf("\n\t\t\t```````````````````````````````````````````````````");
printf("\n\t\t\t` ********************************************* `");
printf("\n\t\t\t` * RESTORING DIVISION * `");
printf("\n\t\t\t` ********************************************* `");
printf("\n\t\t\t```````````````````````````````````````````````````");
cout<<"\nSteps involved in Restoring division........"<<endl;
cout<<"\nStep-1: First the registers are initialized with corresponding values (Q = Dividend, M = Divisor, A = 0, n = number of bits in dividend)"<<endl;
cout<<"\nStep-2: Then the content of register A and Q is shifted left as if they are a single unit"<<endl;
cout<<"\nStep-3: Then content of register M is subtracted from A and result is stored in A."<<endl;
cout<<"\nStep-4: Then the most significant bit of the A is checked if it is 0 the least significant bit of Q is set to 1 otherwise if it is 1 the least significant bit of Q is set to 0 and value of register A is restored i.e the value of A before the subtraction with M"<<endl;
cout<<"\nStep-5: The value of counter n is decremented"<<endl;
cout<<"\nStep-6: If the value of n becomes zero we get of the loop otherwise we repeat from step 2"<<endl;
cout<<"\nStep-7: Finally, the register Q contain the quotient and A contain remainder"<<endl;
cout<<endl;
int dividend,divisor;
cout<<"Enter the dividend: ";
cin>>dividend;
cout<<"\nEnter the divisor: ";
cin>>divisor;
if(divisor==0){
cout<<"No you can't divide by 0.."<<endl;
return;
}
string divi_d=to_binary(dividend);//covert given to binary format
string divi_r=to_binary(divisor);
//cout<<divi_d<<"\n"<<divi_r<<endl;
divi_r.insert(0,to_string(0));//add sign bit for a because a and m should be of same length
//divi_d.insert(0,to_string(0));
/*cout<<divi_d<<"\n"<<divi_r<<endl;
string a=bin_add(divi_d,divi_r) ;
cout<<a<<endl;*/
a="";
for(int i=0;i<divi_r.size();i++){
a+='0';
}
m=divi_r;
q=divi_d;
mc=complement_2(m);
cout<<"\nBasic Calculations..."<<endl;
cout<<"***********************************"<<endl;
cout<<"* -M : "<<mc<<" "<<endl;
cout<<"* Q : "<<q<<" "<<endl;
cout<<"* M : "<<m<<" "<<endl;
cout<<"* Iterations : "<<q.size()<<" "<<endl;
cout<<"***********************************"<<endl;
cout<<"\nSTEP BY STEP EXECUTION.........."<<endl;
divide();
bin_to_decimal();
rem=0;
quotient=0;
}
};
int main(){
printf("\n\t\t\t```````````````````````````````````````````````````");
printf("\n\t\t\t` ********************************************* `");
printf("\n\t\t\t` * UNSIGNED INTEGER DIVSION SIMULATION * `");
printf("\n\t\t\t` ********************************************* `");
printf("\n\t\t\t```````````````````````````````````````````````````");
printf("\n\t\t\t*****************************************************");
printf("\n\t\t\t* GENERAL INSTRUCTION *");
printf("\n\t\t\t* *");
printf("\n\t\t\t* 1.Enter the only integers. *");
printf("\n\t\t\t* 2.-----represents result *");
printf("\n\t\t\t* 3.Don't give other numbers apart menu. *");
printf("\n\t\t\t* *");
printf("\n\t\t\t*****************************************************");
printf("\n->->A division algorithm provides a quotient and a remainder when we divide two number. They are generally of two type slow algorithm and fast algorithm. Slow division algorithm are restoring, non-restoring, non-performing restoring, SRT algorithm and under fast comes Newton–Raphson and Goldschmidt.");
int c;
ResDiv d;
NonResDiv r;
do{
printf("\n\n\t\t\t~~~~~~~~~~~~~~~~~~~HOME~~~~~~~~~~~~~~~~~~~~~");
printf("\n\t\t\tWhat you are gonna explore ??");
printf("\n\t\t\t********************************************");
printf("\n\t\t\t* *");
printf("\n\t\t\t* 1.Restoring Divsion *");
printf("\n\t\t\t* 2.Non-Restoring Division *");
printf("\n\t\t\t* 3.Both *");
printf("\n\t\t\t* -1.Exit *");
printf("\n\t\t\t* *");
printf("\n\t\t\t********************************************");
cout<<"\nEnter your choice: ";
cin>>c;
switch(c){
case 1:
d.perform_division();
break;
case 2:
r.perform_division();
break;
case 3:
d.perform_division();
r.perform_division();
break;
case -1:
printf("\a");
printf("\n\t\t\t********************************************");
printf("\n\t\t\t* Thank you for visiting\1!! See Again!! *");
printf("\n\t\t\t********************************************");
exit(1);
break;
}}while(c!=-1);
}
