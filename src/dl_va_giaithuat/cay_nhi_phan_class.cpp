#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
class Node{
	private:
		int data;
		Node* Right;
		Node* Left;
	public:
		Node();
		~Node();
		friend class Caynhiphan;
};
Node::Node() {
	
	this->Left = NULL;
	this->Right = NULL;
}
Node::~Node() {
}
class Caynhiphan{
	public:
		Node *themvaoCay(Node *temp, const int value){
			if (temp == NULL) {
				Node* node = new Node;
				node->data = value;
				node->Left = NULL;
				node->Right = NULL;
			}		
			else {
				if (temp->data > value) {
					themvaoCay(temp->Left, value);
				}
				else {
					themvaoCay(temp->Right, value);
				}
			}
		}
		bool Search(Node* temp, int value) {
			if (temp == NULL)
				return false;
			if (temp->data == value)
				return true;
			else if (temp->data > value)
				Search(temp->Left, value);
			else if (temp->data < value)
				Search(temp->Right, value);
		}
		void Duyet_NLR(Node* temp) {
			if (temp != NULL) {
				cout << "\t" << temp->data;
				Duyet_NLR(temp->Left);
				Duyet_NLR(temp->Right);
			}
		}
		void Duyet_LNR(Node* temp) {
			if (temp != NULL) {
				Duyet_LNR(temp->Left);
				cout << "\t" << temp->data;
				Duyet_NLR(temp->Right);
			}
		}
		void Duyet_RNL(Node* temp) {
			if (temp != NULL) {
				Duyet_RNL(temp->Right);
				cout << "\t" << temp->data;
				Duyet_RNL(temp->Left);
		}
};
int Menu(Caynhiphan tree, Node* temp, int t){
	system("cls");
	int k;
	cout << "CHUONG TRINH LOP UNG DUNG CAY NHI PHAN" << endl;
	cout << "1.Them phan tu vao cay nhi phan" << endl;
	cout << "2.Duyet NLR" << endl;
	cout << "3.Duyet LNR" << endl;
	cout << "4.Duyet RNL" << endl;
	cout << "5.Tim kiem"  << endl;
	cout << "6.Thoat"     << endl;
	cout << "----------------------------------------" << endl;
	cout << "Nhap lua chon: ";
	cin >> k;
	switch (k) {
	case 1:
		int n, a;
		cout << "Nhap vao so phan tu them vao:";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Nhap gia tri nut thu" << i + 1 << "vao:";
			cin >> a;
			temp = tree.themvaoCay(temp, a);
		}
		t = 1;
		getch();
		return Menu(tree, temp, t);
	case 2:	
		if(t==1)
			Duyet_NLR();
		else{
			cout<<"HAY THEM PHAN TU VAO CAY TRUOC!"<<endl;
			return Menu(tree,temp,t);
		}
	case 3:
		if(t==1)
			Duyet_LNR();
		else{
			cout<<"HAY THEM PHAN TU VAO CAY TRUOC!"<<endl;
			return Menu(tree,temp,t);
		}
	case 4:
		if(t==1)
			Duyet RNL();
		esle{
			cout<<"HAY THEM PHAN TU VAO CAY TRUOC!"<<endl;
			return Menu(tree,temp,t);
		}
	case 5:
		~Node();
		exit(1);
	default:
		cout<<"Nhap lai!!!"<<endl;	
	}
}
int main() {
	Caynhiphan tree;
	Node *node;	
	int t=0;
	Menu(tree,node,t);
}
