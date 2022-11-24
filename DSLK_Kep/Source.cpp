#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* pre;
};

typedef node* NODEPTR;
struct Dlist
{
	NODEPTR head;
	NODEPTR last;
};

void khoiTao(Dlist& list)
{
	list.head = NULL;
	list.last = NULL;
}

NODEPTR khoiTaoNode(int x)
{
	NODEPTR p = new node;
	p->data = x;
	p->next = NULL;
	p->pre = NULL;
	return p;
}

void themDau(Dlist& list, int x)
{
	NODEPTR p = khoiTaoNode(x);
	if (list.head == NULL)
	{
		list.head = list.head = p;
	}
	else {
		p->next = list.head;
		list.head->pre = p;
		list.head = p;
	}
}




void themCuoi(Dlist& list, int x)
{
	NODEPTR p = khoiTaoNode(x);
	if (list.head == NULL)
	{
		list.head = list.last = p;
	}
	else {
		p->pre = list.last;
		list.last->next = p;
		list.last = p;
	}
}

void nhap(Dlist& list)
{
	int x;
	do {
		cout << "\n Nhap Gia Tri So Nguyen: (-99 De Thoat )"; cin >> x;
		if (x == -99) break;
		themCuoi(list, x);
	} while (1);
}

void xuatThuan(Dlist list)
{
	NODEPTR p = list.head;
	while (p != NULL)
	{
		cout << " " << p->data;
		p = p->next;
	}
}

void xuatNguoc(Dlist list)
{
	NODEPTR p = list.last;
	while (p != NULL)
	{
		cout << " " << p->data;
		p = p->pre;
	}
}

void xoaDauThuan(Dlist& list)
{
	NODEPTR p = list.head;
	if (list.head == NULL)
	{
		list.head = list.last = p;
	}
	else {
		list.head = list.head->next;
		list.head->pre = p;
		delete p;
	}
}

void xoaDauNguoc(Dlist& list)
{
	NODEPTR p = list.last;
	if (list.head == NULL)
	{
		list.head = list.last = p;
	}
	else {
		list.last = list.last->pre;
		list.last->next = NULL;
		delete p;
	}
}

void xoaCuoiThuan(Dlist& list)
{
	NODEPTR p;
	if (list.head == NULL)
	{
		cout << "\n Danh Sach Rong ";
	}
	else if (list.head == list.last) 
	{	
		delete list.head;
		list.head = list.last = NULL;
		cout << "\n Da Xoa Het ";
	}
	else {
		NODEPTR p = list.last;
			list.last = list.last->pre;
			list.last->next = NULL;
			delete p;
	}
}
void xoaCuoiNguoc(Dlist& list)
{
	NODEPTR p;
	if (list.head == NULL)
	{
		cout << "\n Danh Sach Rong ";
	}
	else if (list.head == list.last)
	{
		delete list.head;
		list.head = list.last = NULL;
		cout << "\n Da Xoa Het ";
	}
	else {
		NODEPTR p = list.head;
		list.head = list.head->next;
		list.head->pre = NULL;
		delete p;
	}
}

void themNodePSauNodeQThuan(Dlist& list, int v, int x)
{
	NODEPTR q = list.head;
	while (q != NULL && q->data != v)
		q = q->next;
	if (q != NULL)
	{
		if (q==list.last)
		{
			themCuoi(list, x);
		}
		else 
		{
			NODEPTR p = khoiTaoNode(x);
			p->next = q->next;
			q->next->pre = p;
			q->next = p;
			p->pre = q;
		}
	}
}

void themNODEPSauNODEQNghich(Dlist& list, int v, int x)
{
	NODEPTR q = list.last;
	while (q != NULL && q->data != v)
		q = q->pre;
	if (q != NULL)
	{
		if (q == list.head)
		{
			themDau(list, x);
		}
		else 
		{
			NODEPTR p = khoiTaoNode(x);
			p->pre = q->pre;
			q->pre->next = p;
			q->pre = p;
			p->next = q;
		}
	}
}

NODEPTR timNodeX(Dlist list, int x)
{
	NODEPTR p = list.head;
	if (list.head == NULL)
	{
		list.head = list.last = p;
	}
	else {
		while (p != NULL)
		{
			if (p->data == x)
			{
				return p;
			}
			p = p->next;
		}
	}
	return p;
}

void hienThiMenu()
{
	cout << "\n\n\t\t1. Nhap Danh Sach Lien Ket Kep ";
	cout << "\n\n\t\t2. Xuat Danh Sach Lien Ket Kep Theo Chieu Thuan ";
	cout << "\n\n\t\t3. Xuat Danh Sach Lien Ket Kep Theo Chieu Nguoc ";
	cout << "\n\n\t\t4. Tim NODE X Co Trong Danh Sach: ";
	cout << "\n\n\t\t5. Xoa NODE Dau Tien TRong Danh Sach Theo Chieu Thuan: ";
	cout << "\n\n\t\t6. Xoa NODE Dau Tien TRong Danh Sach Theo Chieu Nguoc: ";
	cout << "\n\n\t\t7. Xoa NODE Cuoi Cung TRong Danh Sach Theo Chieu Thuan: ";
	cout << "\n\n\t\t8. Xoa NODE Cuoi Cung TRong Danh Sach Theo Chieu Nguoc: ";
	cout << "\n\n\t\t9. Them NODE P Vao Sau NODE Q Trong Danh Sach Theo Chieu Thuan ";
	cout << "\n\n\t\t10. Them NODE P Vao Sau NODE Q Trong Danh Sach Theo Chieu Nghich ";
	cout << "\n\n\t\t0. Dung ";
}

void chonMenu(Dlist list)
{
	int chon = 0;
	do 
	{
		cout << "\n Chon 1 So Nguyen De Thuc Hien: "; cin >> chon;
		switch (chon)
		{
		case 1: 
			system("cls");
			nhap(list);
			hienThiMenu();
			break;
		case 2:
			system("cls");
			xuatThuan(list);
			hienThiMenu();
			break;
		case 3:
			system("cls");
			xuatNguoc(list);
			hienThiMenu();
			break;
		case 4:
			system("cls");
			int x;
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			NODEPTR kq;
			kq = timNodeX(list, x);
			if (kq == NULL)
			{
				cout << "\n Khong Tim Thay X Trong Danh Sach ";
			}
			else {
				cout << "\n Tim Thay X La So " << kq->data << " Trong Danh Sach ";
			}
		case 5:
			system("cls");
			cout << "\n Xoa NODE Dau Tien Trong Danh Sach Theo Chieu Thuan: ";
			xoaDauThuan(list);
			xuatThuan(list);
			hienThiMenu();
			break;
		case 6:
			system("cls");
			cout << "\n Xoa NODE Dau Tien Trong Danh Sach Nguoc: ";
			xoaDauNguoc(list);
			xuatNguoc(list);
			hienThiMenu();
			break;
		case 7:
			system("cls");
			cout << "\n Xoa NODE Cuoi Cung Trong Danh Sach Theo Chieu Thuan: ";
			xoaCuoiThuan(list);
			xuatThuan(list);
			hienThiMenu();
			break;
		case 8:
			system("cls");
			cout << "\n Xoa NODE Cuoi Cung Trong Danh Sach Theo Chieu Nguoc: ";
			xoaCuoiNguoc(list);
			xuatNguoc(list);
			hienThiMenu();
			break;
		case 9:
			system("cls");
			int v;
			cout << "\n Nhap Gia Tri NODE Q MUON THEM SAU: "; cin >> v;
			cout << "\n Nhap Gia Tri NODE X Sap Them Vao: "; cin >> x;
			cout << "\n Them NODE P Vao Sau NODE Q ";
			themNodePSauNodeQThuan(list, v, x);
			xuatThuan(list);
			hienThiMenu();
			break;
		case 10:
			system("cls");
			cout << "\n Nhap Gia Tri NODE Q MUON THEM SAU: "; cin >> v;
			cout << "\n Nhap Gia Tri NODE X Sap Them Vao: "; cin >> x;
			cout << "\n Them NODE P Vao Sau NODE Q ";
			themNODEPSauNODEQNghich(list, v, x);
			xuatNguoc(list);
			hienThiMenu();
			break;
		default:
			break;
		}

	} while (chon != 0);
}


int main()
{
	Dlist list;
	khoiTao(list);
	hienThiMenu();
	chonMenu(list);
	hienThiMenu();
	return 0;
}
