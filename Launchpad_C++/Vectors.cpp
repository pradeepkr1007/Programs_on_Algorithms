 //Inbuilt vector
 
 #include<iostream>
 using namespace std;
 
 class Vector
 {
 	public:
 		int *a;///////////dynamic
 		int maxsize;
 		int currentsize;
 		
 		Vector(int n=2)
		{
		 	maxsize=n;
		 	currentsize=0;
		 	a= new int[maxsize];
		}
		 
 		void Push_back(int data)
 		{
 			a[currentsize]=data;
 			
 			currentsize++;
 			if (currentsize==maxsize)
 			{
 				maxsize*=2;
			}
		}
		
		void Pop_back()
		{
			currentsize--;
			
			if (currentsize<=((1/4)*maxsize))
			{
				maxsize/=2;
			}
		}
		
		int Size()
		{
			return currentsize;
		}
		
		int Capacity()
		{
			return maxsize;
		}
		
		int operator [] (int i)
		{
			return (a[i]);
		}
};
 
 int main()
 {
 	Vector V;
 	V.Push_back(2);
 	V.Push_back(5);
 	V.Push_back(6);
 	cout<<V.Size()<<endl;
 	cout<<V.Capacity()<<endl;
 	cout<<V[0];
 	
 	return 0;
 }
