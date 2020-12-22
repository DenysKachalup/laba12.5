#include <iostream>
#include <fstream>

using namespace std;
typedef char* buk;
struct stek
{
	stek* link;
	buk inf;
};

char* read(const char* fname,char* w,char *x)
{
	
	ifstream t(fname);
	if (!t)
	{
		cerr << "file \"f.txt\" not found" << endl;
		return 0;
	}
	while (t>>x)
	{
		ifstream f(fname);
		while (f>>w)
		{
			int n = strlen(w);
			if (x[0] == w[n - 1])
				return x, w;
		}
		f.close();
	}

}

void add(stek*& p ,int i,char *w,char* x)
{
	
	
    stek* tmp = new stek;
	if(i==0)
		tmp->inf = w;
	if (i == 1)
		tmp->inf = x;
	tmp->link = p;
	p = tmp;;

}
buk qwe(stek*& p)
{
	stek* tmp = p->link;
	buk val = p->inf;
	delete p;
	p = tmp;
	return val;
}
int main()
{
	stek* p = NULL;
	char* x = new char[10];
	char* w = new char [10];
	read("1234.txt",w,x);
	for (int i = 0; i < 2; i++)
		add(p ,i,w,x);
	while (p != NULL) {
		cout << qwe(p) << "   ";

	}
	cout << endl;
	if (sizeof(x) > sizeof(w))
		cout<<"Naidovshe:  " << x << endl;
	else
		cout << "Naidovshe:  " << w << endl;
}