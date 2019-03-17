#include <iostream>
using namespace std;

class Resource
{
public:
	Resource() :resourse(0) { cout << "CTOR\n"; };
	Resource(int b): resourse(b)
	{
		cout << "CTOR\n";
	}

	Resource(Resource&& A)
	{
		resourse = A.resourse;
		A.resourse = 0;
	}

	~Resource()
	{
		cout << "DTOR\n";
	}

	void incrementResourse()
	{
		++resourse;
	}

	int getRes () const
	{
		return resourse;
	}

	void show () const
	{
		cout << resourse;
	}

private:
	int resourse;
};

int main1()
{
	Resource A = Resource();
	Resource* pA = new Resource();
	unique_ptr<Resource> uA;
	unique_ptr<Resource> uB;
	uA.release();
	uA.reset(pA);
	cout << uA.get()->getRes();
	//uA.reset(new int(2));

	//unique_ptr<Resource> uA(A);
	//Resource* pA = new Resource();
	return 0;
}

int simpleTest1()
{
	Resource* pA = new Resource(1);
	Resource* pB = new Resource(2);

	unique_ptr<Resource> uptrA(pA);
	uptrA.get()->show();

	unique_ptr<Resource>uptrB;
	uptrB.reset(pB);
	uptrB.get()->show();

	Resource* npB = uptrB.release();
	npB->show();

	//dont broke
	uptrB.release();
	uptrB.reset();

	uptrA.reset(npB);
	return 0;
}

void Base(unique_ptr<const Resource> &n)
{
	const Resource* pA = n.get();
	unique_ptr<const Resource> uptrB(pA);
}

int simpleTest2()
{
	Resource* pA = new Resource(1);
	//Resource* pB = new Resource(2);
	//unique_ptr<Resource> uptrA(pA);
	//unique_ptr<Resource> uptrB(uptrA.get());
	unique_ptr<const Resource> uptrC(pA);
	//uptrB = move(uptrA);

	Base(uptrC);
	//uptrA.release();

	return 0;
}

int simpleTest3()
{
	shared_ptr<Resource> shptrA(new Resource(1));
	shared_ptr<Resource> shptrB = shptrA;
	return 0;
}

int main()
{
	simpleTest3();
	simpleTest2();
	main1();
	return 0;
}