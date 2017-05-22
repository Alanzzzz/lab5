#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>
using namespace std;

class HugeInt{
	friend ostream &operator << (ostream &out, const HugeInt &n);
	friend istream &operator >> (istream &in, HugeInt &n);
	public:
		HugeInt(int number=0){
			ptr=new int[30];
			for(int i=0;number>0;i++){
				ptr[i]=number%10;
			 	number/=10;
		 	}
		}
		HugeInt(string number){
			ptr=new int[30];
			for(int i=0;i<30;i++)
			 	ptr[i]=0;
			size=number.size();
			string change;
			for(int i=0;i<size;i++){
			 	change=number[size-(1+i)];
			 	istringstream buffer(change);
			 	buffer>>ptr[i];
			}
		}
		HugeInt operator + (const HugeInt &plus){
			HugeInt answer(0);
			int set=0;
			for(int i=0;i<30;i++){
				answer.ptr[i]=ptr[i]+set+plus.ptr[i];
			 	if(answer.ptr[i]>=10){
				 	answer.ptr[i]%=10;
			 		set=1;
			 	}
				else
					set=0;
			}
			return answer;
 		}
		HugeInt operator - (const HugeInt &minus){
			HugeInt answer(0);
			int set=0;
			for(int i=0;i<30;i++){
			 	answer.ptr[i]=ptr[i]-set-minus.ptr[i];
			 	if(answer.ptr[i]<0){
			 		answer.ptr[i]+=10;
			 		set=1;
			 	}
				else
					set=0;
			}
			return answer;
		}
 	private:
		int size, *ptr;
};

ostream &operator << (ostream &out, const HugeInt &n){
	bool start=false;
	for(int i=29;i>=0;i--){
		if(n.ptr[i]!=0 || start==true){
			out<<n.ptr[i];
			start=true;
			}
		}
}
istream &operator >> (istream &in, HugeInt &n){
	string input;
	in>>input;
	HugeInt number(input);
	n=number;
}

int main(){
	HugeInt x;
	HugeInt y(28825252);
	HugeInt z("314159265358979323846");
	HugeInt result;
	cin>>x;
	result=x+y;
	cout<<x<<" + "<<y<<" = "<<result<<endl;
	result=z-x;
	cout<<result<<endl;
	return 0;
}
