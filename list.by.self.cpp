#include<iostream>
using namespace std;

struct Node {
	Node(int n=0):data(n),next(nullptr){}
	int data;
	Node* next;

};

class List {
public:
	List() {
		head = new Node ();

	}
	/*---------------------------------------------链表插入-------------------------------------------------------------*/
	void InsertTail(int val) {
		//1. create node
		Node* node_new = new Node(val);
		//2. find tail
		Node* p = head;
		while (p->next != nullptr) {
			p = p->next;
		}
		//插入3.
		p -> next = node_new;
	}
	void InsertHead(int val){
		//1.生成新节点
		Node* node = new Node(val);
		//2.插入(先后在前)
		node->next = head ->next;
		head->next = node;
	}
	void ShowList() {
		Node* p = head->next;
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
			
		}
	}
	/*-----------------------------------------------链表删除-----------------------------------------------------------*/
	void Remove(int val) {
		Node* p = head->next;
		Node* q = head;
		while (p->data!=val&&p!=nullptr) {
			q = p;
			p = p->next;
			
		}
		if (p == nullptr) {
			cout << "Value " << val << " not found.\n";
			return ;
		}

		// 情况2: 找到了，进行删除
		q->next = p->next;
		delete p;
		cout << "Removed value: " << val << endl;
	}
	//循环有两种：
	/*1.p!=nullptr,移动结束p是nullptr，一个空指针
	2.p->next=nullptr,移动结束是尾指针*/
	/*---------------------------------------------链表删除------------------------------------------------------------*/
	void RemoveAll(int val){
		Node* p;
		Node* q;
		int count = 0;
		while (p != nullptr ) {
			if (p->data == val) {
				q = p;
				p = p->next;
				q->next = p->next;
				delete p;
				p = q->next;
				count++;
			}
			else {
				q = p;
				p = p->next;
			}
		}
		if (count == 0) {
			cout << "hasn't the value in list" << endl;
		}
		else {
			cout << "Remove successfully" << endl;
		}

		

	}
	/*---------------------------------------------链表查找------------------------------------------------------------*/
	bool Find(int val) {
		Node* p;
		p = head;
		while (p != nullptr) {
			if (p->data == val) {
				cout << "find out" << endl;
				return 1;
			}
		}
		cout << "Not find" << endl;
		return 0;
	}




/*--------------------------------------------------链表高阶操作------------------------------------------------------*/


/*--------------------------------------------------取倒数第k个节点----------------------------------------------------*/
	Node* GetLastKNode(int k) {
		Node* p = head;
		Node* q = head;
		for (int i = 0; i < k; i++) {
			p = p->next;
		}
		while (p != nullptr) {
			p = p->next;
			q = q->next;
		}
		return q;

}
	//采用双指针长度对齐的思想

/*------------------------------------------------- 链表合并----------------------------------------------------------*/
	void HasListInsect(List& other) {            
		Node* p = head->next;
		Node* q = other.head->next;
		Node* M = head;
		while (p != nullptr && q != nullptr) {
			if (p->data > q->data) {
				M->next = q;
				q = q->next;
				M=M->next;
				
			}
			else {
				M->next = p;
				p= p->next;
				M = M->next;
			}
		}
		if (p == nullptr || q == nullptr) {
			M->next = p;
		}
		
		
	}
	/*---------------------------------------------判断链表相交-------------------------------------------------------*/
	bool ListIsMerge(List &other) {
		Node* p = head;
		Node* q = other.head;
		int lenp = 0;
		int lenq = 0;
		while (p != nullptr) {
			p=p->next;
			
			lenp++;

		}
		while ( q != nullptr) {
			q = q->next;
			lenq++;

		}
		p = head->next;
		q = other.head->next;
		if (lenp > lenq) {
			int diff = lenp - lenq;
			for (int i = 0; i < diff; i++) {
				p = p->next;
			}
			while (q!=nullptr) {
				if (p == q)
					return 1;
				p = p->next;
				q = q->next;
			}
		}
		else {
			int diff = lenq - lenp;
			for (int i = 0; i < diff; i++) {
				q = q->next;
			}
			while (p!= nullptr) {
				if (p == q)
					return 1;
				p = p->next;
				q = q->next;
			}
		}
		

		return 0;
	}
	bool HasListInsect_Romantic(List& other) {
		Node* p = head;
		Node* q = other.head;
		while (p != q) {
			p = p ? p->next : other.head;
			q = q ? q->next : head;
		}
	}
	/*---------------------------------------------链表翻转-----------------------------------------------------------*/
	void Reverse() {
		Node* q = head->next;
		Node*p = head;
		
		/*while (q != nullptr) {
			Node* next = q->next;
			q->next = p->next;
			p->next = q;
			p->next->next = next;
			q = next;
		}*/
		//神来之笔：因为如果不先将头节点的下一位指控的话，会形成环链 p->next = nullptr;
		while (q != nullptr) {
			Node* next = q->next;
			q->next = p->next;
			p->next = q;
			q = next;
		}
		
	}

private:
	Node* head;
};





class Circle_List {
public:
	
	Circle_List() {
		head = new Node();
		tail = head;
		head->next = head;
	}
	~Circle_List() {
		Node* p;
		Node* q;
		p = head->next;
		q = head;
		while (p != head) {//需要一个记录指针
			Node* cons = p->next;
			delete p;
			p = cons;
		}
		delete head;
		head = nullptr;
		tail = nullptr;

	}
	/*--------------------------------------------------插入-----------------------------------------*/
	void InsertTail(int val) {
		Node* p = new Node(val);
		p->next = head;
		tail->next = p;
		tail = p;
	}
	void InsertHead(int val) {
		Node* p = new Node(val);
		p->next = head->next;
		head->next = p;
	}
	void RemoveHeadNode()
	{
		Node* p = head;
		head = head->next;
		delete p;
		tail->next = head;
	}
	/*---------------------------------------------Joseph_Circle--------------------------------------*/
	//针对没有哨兵的
	void Joseph( int k) {
		int m = k;
		Node* p = head;
		Node* q = tail;
		while (p != q) {
			while (k--) {
				p = p->next;
				q = q->next;
			}
			q->next = p->next;
			cout << "第" << p->data << "号出列" << endl;
			delete p;
			p = q->next;
			k = m;
		}
		cout << "第" << p->data << "号出列" << endl;
	}
public:
	Node* head;
	Node* tail;
};

int main() {
	/*List test_list1;
	List test_list2;
	int arr[8] = { 5,9,11,21,26,28,31,41 };
	for (int i = 0; i < 8; i++) {
		test_list1.InsertTail(i);
		test_list2.InsertTail(arr[i]);
	}
	test_list1.ShowList();
	cout << endl;
	test_list2.ShowList();
	cout << endl;
	test_list1.Reverse();
	test_list1.ShowList();
	cout << endl;*/
	//test_list2.Show_list();

	Circle_List test;
	for (int i = 1; i < 31; i++) {
		test.InsertTail(i);
	}
	test.RemoveHeadNode();
	test.Joseph(3);
}