#include<bits/stdc++.h>
using namespace std;

template<class T>
void Swap(T &a, T&b){
	T tg = a;
	a = b;
	b = tg;
}

template<class T>
class Vector{
	private:
		int N;
		T *V;
		int n;
		
	public:
		Vector();
		~Vector();
		T& operator[](int i);
		int getAtRank(int r,T &o);
		int replaceAtRank(int r,T o);
		void insertAtRank(T o);
		int removeAtRank(int r,T &o);
		int size();
		int isEmpty();
		void pushdown(T *A,int i,int n);
		void HeapSort(T *A,int n);
		T BinarySearch(T *A,int bsize,T x);
};

template<class T>
Vector<T>::Vector(){
	V = new T[1];
	N = 1;
	n = 0;
}

template<class T>
Vector<T>::~Vector(){
	delete V;
}

template<class T>
T& Vector<T>::operator[](int i){
	return V[i];
}
template<class T>
void Vector<T>::insertAtRank(T o){
	if(n==N){
		T *A;
		N = 2*N;
		A = new T[N+1];
		for(int i=0;i<n;i++){
			A[i] = V[i];
		}
		delete []V;
		V = A;
	}
	V[n] = o;
	n++;
}

template<class T>
int Vector<T>::getAtRank(int r,T &o){
	if(r<0||r>n-1){
		return 0;
	}
	o = V[r];
	return 1;
}

template<class T>
int Vector<T>::replaceAtRank(int r,T o){
	if(r<0||r>n-1){
		return 0;
	}
	V[r] = o;
	return 1;
}

template<class T>
int Vector<T>::removeAtRank(int r,T &o){
	if(r<0||r>n-1){
		return 0;
	}
	o = V[r];
	int k = r;
	while(k<n-1){
		V[k] = V[k+1];
		k++;
	}
	n--;
	return 1;
}

template<class T>
int Vector<T>::size(){
	return n;
}

template<class T>
int Vector<T>::isEmpty(){
	return n==0;
}

template<class T>
void Vector<T>::pushdown(T *A,int i,int n){
	int j = i;
	int kt = 0;
	int max;
	while(j<=n/2&&kt==0){
		if(2*j==n){
			max = 2*j;
		}
		else
			if(A[2*j]<=A[2*j+1]){
				max = 2*j+1;
			}
			else{
				max = 2*j;
			}
		if(A[j]<A[max]){
			Swap(A[j],A[max]);
			j = max;
		}
		else{
			kt = 1;
		}	
	}	
}

template<class T>
void Vector<T>::HeapSort(T *A,int n){
	int i;
	for(i=(n-1)/2;i>=0;i--){
		pushdown(A,i,n-1);
	}
	for(i=n-1;i>=2;i--){
		Swap(A[0],A[i]);
		pushdown(A,0,i-1);
	}
}

template <class T>
T Vector<T>::BinarySearch(T *A,int bsize,T x){
	int low = 0;
    int high = bsize -1;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(x < A[mid])
        	high = mid - 1;

        else if(x > A[mid])
        	low = mid + 1;
       	else
       		return A[mid];
    }
   	return -1;	
}
		
template<class T>
class VectorItr{
	private:
		Vector<T> *TheVector;
		int cur_Index;
	public:
		VectorItr(Vector<T> *V1){
			TheVector = V1;
			cur_Index = 0;
		}
		int hasNext(){
			if(cur_Index<TheVector->size()){
				return 1;
			}
			else{
				return 0;
			}
		}
		T next(){
			T o;
			TheVector->getAtRank(cur_Index,o);
			cur_Index++;
			return o;
		}
};

class Student{
	private:
		string ht, ns, gt, lop, msv;
	public:
		friend istream& operator >>(istream &is,Student &s);
		friend ostream& operator <<(ostream &os,Student &s);
		
		void xuat(){
			cout<<ht<<" "<<msv<<" "<<gt<<" "<<ns<<" "<<lop<<" "<<"\n";
		}
		string getName(){
			return ht;
		}
		Student operator <(Student a){
			Student c;
			if(a.getName() < c.getName())
				return a;
			else	
				return c;
		}
		
};

istream& operator >>(istream &is,Student &s){
	cout<<"\nNhap ho va ten:";
	is.ignore(1);
	getline(is, s.ht);
	cout<<"Nhap ma sinh vien:";
	is.ignore(0);
	getline(is, s.msv);
	cout<<"Nhap gioi tinh:";
	is.ignore(0);
	getline(is, s.gt);
	cout<<"Nhap nam sinh:";
	is.ignore(0);
	getline(is, s.ns);
	cout<<"Nhap lop:";
	is.ignore(0);
	getline(is, s.lop);
	return is;
}

ostream& operator <<(ostream &os,Student &s){
	os<<s.ht<<" "<<s.msv<<" "<<s.gt<<" "<<s.ns<<" "<<s.lop<<"\n";
	return os;
}


class VectorApp{
	private:
		Vector<Student> v;
	public:
		int menu();
		void run();
		void getElem();
		void InsertElem();
		void RemoveElem();
		void ReplaceElem();
		void ListElem();
		void findElem();
		void sortElem();
};

int VectorApp::menu(){
	cout<<"\n1.Them mot sinh vien moi";
	cout<<"\n2.Xoa mot sinh vien";
	cout<<"\n3.Sua doi thong tin mot sinh vien";
	cout<<"\n4.Lay thong tinh mot sinh vien";
	cout<<"\n5.Sap xep danh sach sinh vien theo bang chu cai";
	cout<<"\n6.In danh sach sinh vien";
	cout<<"\n7.Tim kiem sinh vien";
	cout<<"\n8.Ket thuc chuong trinh";
	cout<<"\nChon chuc nang tu 1-8: ";
	int n;
	cin>>n;
	return n;
}

void VectorApp::run(){
	int check;
	char c;
	do{
		check = menu();
		switch(check)
		{
			case 1:
				do{
					InsertElem();
					cout<<"Ban co muon nhap nua khong(c/k): ";
					cin>>c;
				}while(c!='k');
				break;
			case 2:
				RemoveElem();
				break;
			case 3:
				ReplaceElem();
				break;
			case 4:
				getElem();
				break;
			case 5:
				sortElem();
				break;
			case 6:
				ListElem();
				break;
			case 7:
				findElem();
				break;
			case 8:
				cout<<"Ket thuc chuong trinh!";
				break;
			default:{
				cout<<"\nNhap tu 1-8";
				break;
			}
		}
	}while(check!=8);
}
void VectorApp::InsertElem(){
	Student x;
	cout<<"Nhap thong tin cua sinh vien:";
	cin>>x;
	v.insertAtRank(x);	
}

void VectorApp::RemoveElem(){
	Student x;
	int r;
	cout<<"Nhap vi tri cua sinh vien can xoa bo:";
	cin>>r;
	if(v.removeAtRank(r,x)==1)
		cout<<"Phan tu bi xoa di :"<<x<<"\n";
	else
		cout<<"Xoa phan tu khong thanh cong. Loi do vi tri xoa\n";
}

void VectorApp::ReplaceElem(){
	Student x,y;
	int r;
	cout<<"Nhap vi tri can sua doi: ";
	cin>>r;
	if(v.getAtRank(r,x)==1){
		cout<<"Thong tin sinh vien:"<<x<<"\n";
		cout<<"Sua doi thong tin sinh vien:";
		cin>>y;
		if(v.replaceAtRank(r,y)==1)
			cout<<"Sua doi phan tu thanh cong\n";
		else
			cout<<"Sua doi phan tu khong thanh cong\n";
	}
	else{
		cout<<"khong tim thay sinh vien"<<"\n";
	}	
}

void VectorApp::getElem(){
	Student x;
	int r;
	cout<<"Nhap vi tri can lay phan tu:";
	cin>>r;
	if(v.getAtRank(r,x)==1)
		cout<<"Phan tu lay duoc:"<<x<<"\n";
	else
		cout<<"Lay phan tu khong thanh cong. Loi do vi tri lay\n";	
}

void VectorApp::ListElem(){
	VectorItr<Student> Itr(&v);
	cout<<"Danh sach cac sinh vien:\n";
	while(Itr.hasNext()){
		Itr.next().xuat();
	}
}

void VectorApp::sortElem(){
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[i].getName()>v[j].getName()){
				Swap(v[i], v[j]);
			}
		}
	}
}

void VectorApp::findElem(){
	string name;
	cout<<"Nhap ten sinh vien can tim:";
	cin.ignore(1);
	getline(cin,name);
	int dem=0;
	for(int i=0;i<v.size();i++){
		if(v[i].getName()==name){
			cout<<"Tim thay sinh vien co ten : "<<name<<"\n";
			cout<<"Thong tin sinh vien : "<<v[i]<<"\n";
			dem++;
			break;
		}
	}
	if(dem==0)
		cout<<"\nKhong tim thay sinh vien ten : "<<name;
}
int main()
{
    VectorApp x;
	x.run();
	return 0;
}

