#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Product {
	string name;
	unsigned int amount;
	double cost;
public:
	Product() {
		name = "";
		amount = 0;
		cost = 0;
	}
	Product(string name, unsigned int amount,double cost) {
		this->name = name;
		this->amount = amount;
		this->cost = cost;
	}
	void Print()
	{
		cout << "\nName: " << name << endl;
		cout << "Amount: " << amount << endl;
		cout << "Cost: " << cost << endl;
	}
	double Summary(Product *array, unsigned int n){
		double sum = 0;
		for (unsigned int i = 0; i < n; ++i)
			sum += array[i].Get_Amount() * array[i].Get_Cost();

		return sum;
	}
	Product & operator =(Product& v2)
	{
		name = v2.name;
		amount = v2.amount;
		cost = v2.cost;
		return *this;
	}
	double Get_Cost()
	{
		return cost;
	}
	unsigned int Get_Amount()
	{
		return amount;
	}
	~Product()
	{
		delete &name;
		delete &amount;
		delete &cost;
	}
};
int main()
{
	unsigned int n;
	cout << "Amount of products:" << endl;
	cin >> n;
	Product *array = new Product[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		string name;
		unsigned int amount;
		double cost;
		double buf;
		cout << "Product " << i + 1 << endl;
		
		cout << "Name:" << endl;
		if(cin) cin >> name;
		else name = " ";
		
		cout << "Amount:" << endl;
		if (cin) {
			cin >> buf;
			amount = abs(round(buf));
		}
		else amount = 0;
		
		cout << "Cost:" << endl;
		if(cin) cin >> cost;
		else cost = 0;;
		
		Product buff(name, amount, cost);
		array[i] = buff;
	}
	cout << "/////////////////////////////////////" << endl;
	for (unsigned int i = 0; i < n; ++i)
	{
		array[i].Print();
	}
	cout << "\nSummary: " << array[0].Summary(array, n) << endl;
	delete[] array;
	system("pause");
	return 0;
}
