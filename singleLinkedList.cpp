#include<bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

class SV{
	private:
		string ten, msv, gioiTinh, queQuan;
		int ngay, thang, nam;
	public:
		void input(); // phuong thuc nhap du lieu
		friend ostream& operator<<(ostream &os, SV &a); // nap chong toan tu <<
};

void SV::input(){
	cin.ignore(1);
	cout << "MSV: ";
	getline(cin, msv);
	cout << "Ten: ";
	getline(cin, ten);
	cout << "Gioi tinh: ";
	getline(cin, gioiTinh);
	cout << "Que quan: ";
	getline(cin, queQuan);
	cout << "Ngay sinh: ";
	cin >> ngay;
	cout << "Thang sinh: ";
	cin >> thang;
	cout << "Nam sinh: ";
	cin >> nam;
}

ostream& operator<<(ostream &os, SV &a){
	os << setw(10) << a.msv << setw(25) << a.ten << setw(15) << a.gioiTinh << setw(15) << a.queQuan 
	<< setw(15) << a.ngay << setw(15) << a.thang << setw(15) << a.nam << endl;
	return os;
}

class node{
	public:
		SV data;
		node *pNext;
		
		node(){
			pNext = NULL;
		}
		
		node *createNode(SV x){ // khoi tao node moi
			node *nodeNew = new node();
			nodeNew->data = x;		
			nodeNew->pNext = NULL;
			return nodeNew;
		}
};

class linkedList{
 	private:
 		node *pHead;
 		node *pTail;
 	public:
 		linkedList(); // ham tao 1 danh sach lien ket don
		int length(); // phuong thuc tinh so node trong danh sach lien ket
		bool empty(); // phuong thuc kiem tra xem danh sach lien ket co rong hay khong?
		void addHead(node *p); // phuong thuc them node moi vao dau danh sach lien ket
		void addTail(node *p); // phuong thuc them node moi vao cuoi danh sach lien ket
		void addNode(node *p, int x); // phuong thuc them node moi vao 1 vi tri tuy y trong danh sach lien ket
		void removeHead(); // phuong thuc xoa node dau tien trong danh sach lien ket
		void removeTail(); // phuong thuc xoa node cuoi cung trong sanh sach lien ket
		void removeNode(int x); // phuong thuc xoa node tuy y trong danh sach lien ket
		// voi moi bai toan khac nhau, viec xuat du lieu ra man hinh voi formatDisplay va display la khac nhau
		void formatDisplay(); // phuong thuc dinh dang xuat ra man hinh (chi ap dung voi bai nay)
		void display(); // phuong thuc xuat du lieu theo dinh dang co san ra man hinh (chi ap dung voi bai nay)
		void print(); // gom phuong thuc formatDisplay va display => de dang cho viec goi ham de in ra
};

linkedList::linkedList(){
	pHead = NULL;
 	pTail = NULL;
}

void linkedList::addHead(node *p){
	if(pHead == NULL){
		pHead = pTail = p;
	} else {
		p->pNext = pHead;
		pHead = p;
	}
}

void linkedList::addTail(node *p){
	if(pTail == NULL){
		pHead = pTail = p;
	} else {
		pTail->pNext = p;
		pTail = p;
	}
}

int linkedList::length(){
	node *temp = new node();
	temp = pHead;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->pNext;
	}
	delete temp;
	return count;
}

void linkedList::removeHead(){
	pHead = pHead->pNext;
}

void linkedList::removeTail(){
	node *temp = new node;
	temp = pHead;
	while(temp->pNext->pNext != NULL){
		temp = temp->pNext;
	}
	pTail = temp;
	temp->pNext = NULL;
}

bool linkedList::empty(){
	if(pHead == NULL && pTail == NULL){
		return true;
	} else return false;
}

void linkedList::addNode(node *p, int x){
	if(x == 1 || pHead == NULL){ // neu vi tri can them la 1 hoac danh sach dang rong thi them vao dau
		addHead(p);
	}else if(x > length()){ //neu vi tri can them vuot qua so node trong danh sach thi them vao cuoi
		addTail(p);
	} else { // neu khac 2 dieu kien tren thi tien hanh them node vao vi tri can them
		for(node *i = pHead; i != NULL; i = i->pNext){
			x--;
			if(x == 1){
				p->pNext = i->pNext;
				i->pNext = p;
				break;
			}
		}
	}
}

void linkedList::removeNode(int x){
	if(x == 1 || length() == 1){ // neu x la 1 hoac so node hien tai trong danh sach la 1 thi xoa dau
		removeHead();
	} else if(x >= length()){ // neu x lon hon so node co trong danh sach hien tai thi xoa cuoi
		removeTail();
	} else { // neu khac 2 dieu kien thi tien hanh xoa node o x
		for(node *i = pHead; i != NULL; i = i->pNext){
			x--;
			if(x == 1){
				i->pNext = i->pNext->pNext;
				break;
			}
		}
	}
}

void linkedList::display(){
	node *temp = new node;
	temp = pHead;
	while(temp != NULL){
		cout << temp->data;
		temp = temp->pNext;
	}
	cout << endl;
	delete temp;
}

void linkedList::formatDisplay(){
	cout << setw(10) << "MSV" << setw(25) << "Ho va ten" << setw(15) << "Gioi tinh" << setw(15) << "Que quan" << setw(15) 
		 << "Ngay sinh" << setw(15) << "Thang sinh" << setw(15) << "Nam sinh" << endl;
}

void linkedList::print(){
	//in ra du lieu theo format
	linkedList::formatDisplay();
	linkedList::display();
}

int main(){
	linkedList A; //khoi tao danh sach lien ket
	
	cout << "Kiem tra linked list hien tai co rong khong?\n";
	if(A.empty()){
		cout << "Co\n";
	} else {
		cout << "No\n";
	}
	
	cout << "---------------------------------------------------------------------------\n";
	
	cout << "Nhap so node: ";
	int n; cin >> n;
	for(int i=0; i<n; i++){
		cout << "Nhap du lieu node thu " << i+1 << ":\n";
		SV x;
		x.input();
		node *p = new node();
		p = p->createNode(x);
		A.addTail(p);
	}
	cout << "Linked list:\n";
	A.print();
	cout << "Do dai cua linked list: " << A.length() << endl;
	
	cout << "---------------------------------------------------------------------------\n";
	
	int soNodeCanThem;
	cout << "Nhap so node can them vao dau vao dau linked list: "; cin >> soNodeCanThem;
	cout << "Them " << soNodeCanThem << " node vao dau linked list\n";
	for(int i=1; i<=soNodeCanThem; i++){
		cout << "Nhap du lieu node can them thu " << i << ":\n";
		SV x;
		x.input();
		node *p = new node();
		p = p->createNode(x);
		A.addHead(p);
	}
	cout << "Linked list:\n";
	A.print();
	cout << "Do dai cua linked list sau khi them 2 node: " << A.length() << endl;
	
	cout << "---------------------------------------------------------------------------\n";
	
	cout << "Xoa 1 node dau tien:\n";
	A.removeHead();
	cout << "Linked list:\n";
	A.print();
	cout << "Do dai cua linked list sau khi xoa node dau tien: " << A.length() << endl;
	
	cout << "---------------\n";
	
	cout << "Xoa 1 node cuoi cung:\n";
	A.removeTail();
	cout << "Linked list:\n";
	A.print();
	cout << "Do dai cua linked list sau khi xoa node cuoi cung: " << A.length() << endl;
	
	cout << "---------------------------------------------------------------------------\n";

	cout << "Them 1 node o vi tri tuy y:\n";
	int viTriCanThem;
	cout << "Nhap vi tri can them: ";
	cin >> viTriCanThem;
	cout << "Nhap du lieu can them: ";
	SV duLieuCanThem;
	duLieuCanThem.input();
	node *p = new node();
	p = p->createNode(duLieuCanThem);
	A.addNode(p, viTriCanThem);
	cout << "Linked list:\n";
	A.print();
	cout << "Do dai cua linked list sau khi them node bat ky: " << A.length() << endl;
	
	cout << "---------------------------------------------------------------------------\n";
	
	cout << "Xoa 1 node o vi tri tuy y:\n";
	int viTriXoa;
	cout << "Nhap vi tri can xoa: ";
	cin >> viTriXoa;
	A.removeNode(viTriXoa);
	cout << "Linked list:\n";
	A.print();
	cout << "Do dai cua linked list sau khi xoa node bat ky: " << A.length() << endl;
	
	cout << "---------------------------------------------------------------------------\n";
	
	cout << "Kiem tra linked list hien tai co rong khong?\n";
	if(A.empty()){
		cout << "Co\n";
	} else {
		cout << "No\n";
	}
	return 0;
}
