//	Singleton design pattern is a software design principle that is used to restrict the instantiation of a 
//	class to one object. This is useful when exactly one object is needed to coordinate actions across the system. 
//	For example, if you are using a logger, that writes logs to a file, you can use a singleton class to create such a logger.
//	You can create a singleton class using the following code -


#include<iostream>

using namespace std;


class Singleton{
	public:
		Singleton(const Singleton&) = delete; 		//deleting copy constructer
		
		static Singleton& Get(){
			return s_Instance;
		} 
	
		void function(){
			cout<<"\t"<<"function() called "<<endl;
		}
	private:
		Singleton()	{	}
		
		static Singleton s_Instance;
};


Singleton Singleton::s_Instance;

int main(){
	system("COLOR 0A");
	
//	Singleton instance =Singleton::Get();
	
	Singleton::Get().function();

    return 0;
}

