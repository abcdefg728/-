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
	void Show_list() {
		Node* p = head->next;
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
			
		}
	}
	void Remove(int val) {
		Node* p = head->next;
		Node* q = head;
		while (p->data!=val&&p!=nullptr) {
			q = p;
			p = p->next;
			
		}
		if (p == nullptr) {
			cout << "Value " << val << " not found.\n";
			return;
		}

		// 情况2: 找到了，进行删除
		q->next = p->next;
		delete p;
		cout << "Removed value: " << val << endl;
	}
	//循环有两种：
	/*1.p!=nullptr,移动结束p是nullptr，一个空指针
	2.p->next=nullptr,移动结束是尾指针*/
	
private:
	Node* head;
};
class Circle_List {
	Circle_List() {
		Node* head = new Node();
		Node* tail = head;
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
private:
	Node* head;
	Node* tail;
};

int main() {
	List test_list1;
	List test_list2;
	for (int i = 0; i < 8; i++) {
		test_list1.InsertTail(i);
		test_list2.InsertHead(i);
	}
	test_list1.Remove(3);
	test_list1.Show_list();
	//test_list2.Show_list();
}