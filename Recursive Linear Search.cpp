#include<iostream>
using namespace std;


void linearSearch(int arr[],int size,int i,int x){
	if(arr[i]==x){
		cout<<" Found on arr["<<i<<"] : "<<arr[i]<<endl;
	}
	else if(i<size){
		++i;
		linearSearch(arr,size,i,x);
	}
	else{
		cout<<" Not Found! "<<endl;
	}
}

int main(){
	system("COLOR 0A");
	
	int size=0;
	cout<<" Enter size of array: ";
	cin>>size;
	const int n=size;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cout<<" Enter value in arr["<<i<<"] :";
		cin>>arr[i];
	}

	cout<<"\n\n All Data Entered"<<endl;
	cout<<"------------------------"<<endl;
	system("pause");
	system("cls");
	
	int x=0,i=0;	
	cout<<" Enter number you want to find in array: ";
	cin>>x;
	
	linearSearch(arr,size,i,x);									

	return 0;
}