#include<iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <limits>
using namespace std;
int login();

struct item {
	int id;             
	string type;     
	int quantity;  
	double price;
	bool isForSale; 

	item(int id) {
		this->id = id;
		type = "";
		quantity = 0;
		price = 0;
		isForSale = false;
	}
	item() {
		id = 0;
		type = "";
		quantity = 0;
		price = 0;
		isForSale = false;
	}
	//Parameterized Constructor
	item(int id, string type, int quantity, double price, bool sale) {
		this->id = id;
		this->type = type;
		this->quantity = quantity;
		this->price = price;
		isForSale = sale;
	}
	//Operator Overloaded To Use In Other Classes
	item operator = (item const& items)
	{
		this->id = items.id;
		this->type = items.type;
		this->quantity = items.quantity;
		this->price = items.price;
		this->isForSale = items.isForSale;
		return *this;
	}
	bool operator > (item const& items) {
		return (this->price > items.price) ? true : false;
	}
	bool operator < (item const& items) {
		return (this->price < items.price) ? true : false;
	}
	friend ostream& operator << (ostream& out, const item& c);
};
ostream& operator << (ostream& out, const item& c)
{
	out << "Item With ID: " << c.id << " are as :" << endl;
	out << "Type: " << c.type << endl;
	out << "Quantity: " << c.quantity << endl;
	out << "Price: " << c.price << endl;
	return out;
}

template <class T>
struct Node {
	T data;
	struct Node* next;
	struct Node* prev;
};

template <class T>
class DoublyLinkedList {
public:
	Node<T>* root;
	DoublyLinkedList() {
		root = NULL;
	}
	DoublyLinkedList(T data) {
		root = new Node<T>();
		root->data = data;
	}
	void push(Node<T>** head_ref, T& new_data)
	{
		Node<T>* new_node = new Node<T>();
		new_node->data = new_data;
		new_node->next = (*head_ref);
		new_node->prev = NULL;
		if ((*head_ref) != NULL)
			(*head_ref)->prev = new_node;
		(*head_ref) = new_node;
	}
	void insertAfter(Node<T>* prev_node, T& new_data)
	{
		if (prev_node == NULL) {
			printf("Previous Node Should Not Be Null");
			return;
		}
		Node<T>* new_node = new Node<T>();
		new_node->data = new_data;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
		new_node->prev = prev_node;
		if (new_node->next != NULL)
			new_node->next->prev = new_node;
	}
	void append(Node<T>** head_ref, T& new_data)
	{
		struct Node<T>* new_node = new Node<T>();
		struct Node<T>* last = *head_ref;
		new_node->data = new_data;
		new_node->next = NULL;
		if (*head_ref == NULL) {
			new_node->prev = NULL;
			*head_ref = new_node;
			return;
		}
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
		return;
	}
	//Bubble Sort for prices
	void bubbleSort(Node<T>* start) {
		int swapped;
		Node<T>* ptr1;
		Node<T>* lptr = NULL;
		if (start == NULL)
			return;
		do {
			swapped = 0;
			ptr1 = start;
			while (ptr1->next != lptr) {
				if (ptr1->data > ptr1->next->data) {
					swap(ptr1->data, ptr1->next->data);
					swapped = 1;
				}
				ptr1 = ptr1->next;
			}
			lptr = ptr1;
		} while (swapped);
	}

	// Method to find middle element
	Node<T>* middle(Node<T>* start, Node<T>* last)
	{
		if (start == NULL)
			return NULL;

		struct Node<T>* slow = start;
		struct Node<T>* fast = start->next;

		while (fast != last) {
			fast = fast->next;
			if (fast != last) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		return slow;
	}
	//Binary Search
	Node<T>* find(Node<T>* head, int value)
	{
		struct Node<T>* start = head;
		struct Node<T>* last = NULL;
		do
		{
			Node<T>* mid = middle(start, last);
			if (mid == NULL)
				return NULL;
			if (mid->data == value)
				return mid;
			else if (mid->data < value)
				start = mid->next;
			else
				last = mid;

		} while (last == NULL ||
			last != start);
		return NULL;
	}
	Node<T>* searchNode(string id) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.id == id) {
				return current;
			}
			current = current->next;
		}
		return NULL;
	}
	bool alreadyExist(int id) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.id == id) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
	bool alreadyExist(string id) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.id == id) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
	Node<T>* searchNode(int id) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.id == id) {
				return current;
			}
			current = current->next;
		}
		return NULL;
	}
	void ViewAllItemTypes(string type) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.type == type) {
				cout << (current->data) << endl;
			}
			current = current->next;
		}
	}
	void deleteNode(Node<T>** head_ref, Node<T>* del)
	{
		if (*head_ref == NULL || del == NULL)
			return;
		if (*head_ref == del)
			*head_ref = del->next;
		if (del->next != NULL) {
			del->next->prev = del->prev;
		}
		if (del->prev != NULL) {
			del->prev->next = del->next;
		}
		free(del);
		return;
	}
	void remove(string id) {
		deleteNode(&root, searchNode(id));
	}
	void remove(int id) {
		deleteNode(&root, searchNode(id));
	}
	void printListForward(Node<T>* node)
	{
		Node<T>* last = new Node<T>();
		while (node != NULL) {
			cout << node->data << endl;
			last = node;
			node = node->next;
		}
	}
	void printListBackward(Node<T>* node)
	{
		Node<T>* last = new Node<T>();
		while (last != NULL) {
			cout << last->data;
			last = last->prev;
		}
	}
	double getTotal(Node<T>* node) {
		double totalPrice = 0;
		Node<T>* last = new Node<T>();
		while (node != NULL) {
			totalPrice = node->data.price;
			last = node;
			node = node->next;
		}
		return totalPrice;
	}
	void printAllPromotionItems(Node<T>* node) {
		bubbleSort(root);
		Node<T>* last = new Node<T>();
		while (node != NULL) {
			if (node->data.isForSale == true) {
				cout << node->data << endl;
			}
			last = node;
			node = node->next;
		}
	}
	void addNewItem() {
		int id = 0;
		cout << "Item ID: "; cin >> id;

		string type = "";
		cout << "Item Type: "; cin >> type;

		int quantity = 0;
		cout << "Item Quantity: ";
		cin >> quantity;

		double price = 0;
		cout << "Item Price: ";
		cin >> price;

		item item1(id, type, quantity, price, false);
		append(&root, item1);
	}




};
//Class That represents Order Entity
class Order {
private:
	string client_address;
	string client_name;
	string client_contact;
	double totalPrice;
	bool isCheckedOut;
	DoublyLinkedList<item*> stock;
	DoublyLinkedList<item>* iteem;

public:
	bool isDeliveryRequired;
	string id;
	Order() {
		iteem = new DoublyLinkedList<item>();
		totalPrice = 10;
		isCheckedOut = false;
		client_address = client_contact = "";
	}
	Order(string id, string name, string address, string contact) {
		iteem = new DoublyLinkedList<item>();
		this->id = id;
		if (address == "0") {
			isDeliveryRequired = false;
		}
		else {
			isDeliveryRequired = true;
		}
		this->client_address = address;
		this->client_name = name;
		this->client_contact = contact;
		isCheckedOut = false;
	}
	double getTotalPrice() {
		return totalPrice;
	}
	void setTotalPrice(double price) {
		this->totalPrice = price;
	}
	void checkOutOrder() {
		isCheckedOut = true;
	}
	void addOrder(item& items) {
		this->totalPrice += items.price;
		iteem->append(&iteem->root, items);
	}
	void removeItem(item items) {
		totalPrice -= items.price;
		iteem->remove(items.id);
	}
	Order operator = (Order const& order) {
		this->id = order.id;
		this->isDeliveryRequired = order.isDeliveryRequired;
		this->client_address = order.client_address;
		this->client_name = order.client_name;
		this->iteem = order.iteem;
		this->client_contact = order.client_contact;
		this->totalPrice = order.totalPrice;
		return *this;
	}
	void updateClient(DoublyLinkedList<item> stock) {
		cout << "\n\n\t1: Update Client Address\n\t2: Update Client Name \n\t3: Update Client Contact\n\t0: Exit" << endl;
		int input = -1;
		cin >> input;

		if (input == 1) {
			cout << "Enter New Client Address: ";
			string addr;
			cin >> addr;
			this->client_address = addr;
		}
		else if (input == 2) {
			cout << "Enter New Client Name: ";
			string name;
			cin >> name;
			this->client_name = name;
		}
		else if (input == 3) {
			cout << "Enter New Client Contact: ";
			string contact;
			cin >> contact;
			this->client_contact = contact;
		}
		else if (input == 0) {
			return;
		}
	}
	bool operator > (Order& order) {
		bool firstOne = (this->totalPrice > order.totalPrice) ? true : false;
		if (this->isDeliveryRequired && !order.isDeliveryRequired) {
			firstOne = false;
		}
		return firstOne;
	}
	bool operator < (Order& order) {
		bool firstOne = (this->totalPrice < order.totalPrice) ? true : false;
		if (this->isDeliveryRequired && !order.isDeliveryRequired) {
			firstOne = false;
		}
		return firstOne;
	}
	friend ostream& operator << (ostream& out, const Order& c);
};


ostream& operator << (ostream& out, const Order& c)
{
	out << "Order With ID " << c.id << " are as :" << endl;
	out << "To: " << c.client_name << endl;
	out << "Address: " << c.client_address << endl;
	out << "Contact: " << c.client_contact << endl;
	out << "Total Price: " << c.totalPrice << endl;
	if (c.isCheckedOut) {
		out << "Order is Checked Out." << endl;
	}
	return out;
}


//This class manages all orders and stock of Item and operation performed on them
class Manage {
public:
	Manage() {}
	DoublyLinkedList<item> dList;
	DoublyLinkedList<Order> orders;
	void addItem(item items) {
		srand((unsigned)time(0));
		if (dList.alreadyExist(items.id)) {
			cout << "Item ID already exists" << endl;
			return;
		}
		dList.append(&dList.root, items);
	}
	void printItemSortedByPrice() {
		dList.bubbleSort(dList.root);
		dList.printListForward(dList.root);
	}
	void getNewItem() {
		dList.addNewItem();
	}
	void printPromotionItems() {
		dList.printAllPromotionItems(dList.root);
	}
	void printAllItemsType() {
		string type;
		cout << "Enter Item Type: ";
		cin >> type;
		dList.ViewAllItemTypes(type);
	}
	void printOrdersSortedByPrice() {
		orders.bubbleSort(orders.root);
		orders.printListForward(orders.root);
	}
	void placeOrder() {
		int id;
		cout << "Enter Item	ID: ";
		cin >> id;
		string orderID = "0";

		string name;
		cout << "Enter Your Name: ";
		cin >> name;

		string address = "";
		cout << "Enter Your Address(If Delivery Required Press '0'): ";
		cin >> address;

		string contact = "";
		cout << "Enter Your Contact: ";
		cin >> contact;


		srand((unsigned)time(0));
		long int random_integer = rand() % 10000000;
		orderID = to_string(random_integer + 1);
		while (orders.alreadyExist(orderID)) {
			cout << "Already Exists..." << endl;
			random_integer = rand() % 10000000;
			orderID = to_string(random_integer);
		}
		dList.searchNode(id)->data.quantity -= 1;
		if (dList.searchNode(id)->data.quantity > 0) {
			Order order(orderID, name, address, contact);
			order.addOrder(dList.searchNode(id)->data);

			orders.append(&orders.root, order);
			cout << "Order Added..." << endl;
		}
		else {
			cout << "This item is out of stock!" << endl;
			dList.searchNode(id)->data.quantity = 0;
		}
	}
	void checkoutOrder() {
		string id;
		cout << "Enter Order ID To Checkout: ";
		cin >> id;
		orders.searchNode(id)->data.checkOutOrder();
		cout << "Order Checked Out!" << endl;
	}
	void modifyOrder() {
		string id;
		cout << "Enter Order ID To Update: ";
		cin >> id;
		if (orders.searchNode(id)->data.isDeliveryRequired) {
			orders.searchNode(id)->data.updateClient(dList);
		}
		else {
			cout << "This Order is for Pickup." << endl;
		}
	}
	void removeOrder() {
		string id;
		cout << "Enter Order ID To Delete: ";
		cin >> id;
		orders.remove(id);
		cout << "Order Deleted!" << endl;
		orders.printListForward(orders.root);
	}
};


//Sales executive main menu
void SalesExecutiveMainMenu() {

	cout << "\t\t-------------------------------------------------------------------------------\n";
	cout << "\t\t			             SALES EXECUTIVES MAIN MENU		                  \n";
	cout << "\t\t-------------------------------------------------------------------------------\n";
	cout << ("\n");
	cout << "1: Display All Type of Items\n2: Display Items on Promotion\n3: Place An Order\n4: Order ChechOut\n5: Display Order Details\n6: Update Order\n7: Removed Order\n0: Log Out" << endl;

	Manage manager;
	int id = 0;
	string type = "Dress";
	int quantity = 15;
	double price = 12.0;
	bool isForSale = true;
	item item1(id, type, quantity, price, isForSale);

	id = 1;
	type = "Jeans";
	quantity = 10;
	price = 80.0;
	isForSale = false;
	item item2(id, type, quantity, price, isForSale);

	id = 2;
	type = "Shorts";
	quantity = 15;
	price = 45.0;
	isForSale = false;
	item item3(id, type, quantity, price, isForSale);

	id = 3;
	type = "Shirt";
	quantity = 15;
	price = 50.0;
	isForSale = false;
	item item4(id, type, quantity, price, isForSale);

	id = 4;
	type = "T-Shirt";
	quantity = 10;
	price = 35.0;
	isForSale = true;
	item item5(id, type, quantity, price, isForSale);

	id = 5;
	type = "Trouser";
	quantity = 20;
	price = 75.0;
	isForSale = false;
	item item6(id, type, quantity, price, isForSale);

	id = 6;
	type = "Party Dress";
	quantity = 20;
	price = 95.0;
	isForSale = false;
	item item7(id, type, quantity, price, isForSale);

	id = 7;
	type = "Summer Dress";
	quantity = 25;
	price = 45.0;
	isForSale = true;
	item item8(id, type, quantity, price, isForSale);

	id = 8;
	type = "Slacks";
	quantity = 15;
	price = 75.0;
	isForSale = false;
	item item9(id, type, quantity, price, isForSale);

	id = 9;
	type = "Shirt";
	quantity = 20;
	price = 45.0;
	isForSale = false;
	item item10(id, type, quantity, price, isForSale);

	id = 10;
	type = "Skirt";
	quantity = 40;
	price = 30.0;
	isForSale = false;
	item item11(id, type, quantity, price, isForSale);

	manager.addItem(item1);
	manager.addItem(item2);
	manager.addItem(item3);
	manager.addItem(item4);
	manager.addItem(item5);
	manager.addItem(item6);
	manager.addItem(item7);
	manager.addItem(item8);
	manager.addItem(item9);
	manager.addItem(item10);

	int input;
	while (true) {
		cout << "Enter Your Selection: ";
		cin >> input;
		if (input == 1) {
			manager.printAllItemsType();
		}
		else if (input == 2) {
			manager.printPromotionItems();
		}
		else if (input == 3) {
			manager.placeOrder();
		}
		else if (input == 4) {
			manager.checkoutOrder();
		}
		else if (input == 5) {
			manager.printOrdersSortedByPrice();
		}
		else if (input == 6) {
			manager.modifyOrder();
		}
		else if (input == 7) {
			manager.removeOrder();
		}
		else if (input == 0) {
			login();
			break;
		}
		else {
			cout << "Invalid Input!" << endl;
		}
	}
}



int adminMainMenu() {
	int input;
	do {
		cout << "\t\t-------------------------------------------------------------------------------\n";
		cout << "\t\t			             ADMIN MAIN MENU		                  \n";
		cout << "\t\t-------------------------------------------------------------------------------\n";
		cout << ("\n");
		cout << "1: Add New Item\n2: Display All Items Available.\n3: Dsiplay Items based on Type\n4: Log Out" << endl;


		Manage manager;
		int id = 0;
		string type = "Dress";
		int quantity = 15;
		double price = 12.0;
		bool isForSale = true;
		item item1(id, type, quantity, price, isForSale);

		id = 1;
		type = "Jeans";
		quantity = 10;
		price = 80.0;
		isForSale = false;
		item item2(id, type, quantity, price, isForSale);

		id = 2;
		type = "Shorts";
		quantity = 15;
		price = 45.0;
		isForSale = false;
		item item3(id, type, quantity, price, isForSale);

		id = 3;
		type = "Shirt";
		quantity = 15;
		price = 50.0;
		isForSale = false;
		item item4(id, type, quantity, price, isForSale);

		id = 4;
		type = "T-Shirt";
		quantity = 10;
		price = 35.0;
		isForSale = true;
		item item5(id, type, quantity, price, isForSale);

		id = 5;
		type = "Trouser";
		quantity = 20;
		price = 75.0;
		isForSale = false;
		item item6(id, type, quantity, price, isForSale);

		id = 6;
		type = "Party Dress";
		quantity = 20;
		price = 95.0;
		isForSale = false;
		item item7(id, type, quantity, price, isForSale);

		id = 7;
		type = "Summer Dress";
		quantity = 25;
		price = 45.0;
		isForSale = true;
		item item8(id, type, quantity, price, isForSale);

		id = 8;
		type = "Slacks";
		quantity = 15;
		price = 75.0;
		isForSale = false;
		item item9(id, type, quantity, price, isForSale);

		id = 9;
		type = "Shirt";
		quantity = 20;
		price = 45.0;
		isForSale = false;
		item item10(id, type, quantity, price, isForSale);

		id = 10;
		type = "Skirt";
		quantity = 40;
		price = 30.0;
		isForSale = false;
		item item11(id, type, quantity, price, isForSale);

		manager.addItem(item1);
		manager.addItem(item2);
		manager.addItem(item3);
		manager.addItem(item4);
		manager.addItem(item5);
		manager.addItem(item6);
		manager.addItem(item7);
		manager.addItem(item8);
		manager.addItem(item9);
		manager.addItem(item10);

		cin >> input;
		if (input == 1) {
			manager.getNewItem();
		}
		else if (input == 2) {
			manager.printItemSortedByPrice();
		}
		else if (input == 3) {
			manager.printAllItemsType();
		}
		else if (input == 4) {
			login();
		}
		else if (input > 4 || input < 1) {
			cout << "Invalid Input." << endl;
		}
	} while (input > 4 || input < 1);
	return 0;
}

int login() {

	string user;
	string pass;
	cout << ("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	cout << ("\t\t$                                                                         $\n");
	cout << ("\t\t$  			  PURCHASE ORDER (PO) MANAGEMENT SYSTEM           $\n");
	cout << ("\t\t$                                                                         $\n");
	cout << ("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	cout << ("\n");
	cout << ("1. ADMINASTRATOR\n");
	cout << ("\n");
	cout << ("2. SALE ORDER EXECUTIVES\n");
	cout << ("\n");
	cout << ("3. EXIT PROGRAM\n");
	cout << ("\n");
	cout << ("PLEASE KINDLY ENTER YOUR LOGIN DETAILS: ");

	int loginUser;
	cin >> loginUser;
	switch (loginUser) {
	case 1:
		cout << "\nUsername : "; cin >> user;
		cout << "\nPassword : "; cin >> pass;
		if (user == "admin" && pass == "admin") {
			cout << "\nLogin Sucessfull! " << endl;
			cout << " \nWelcome Admin! \n" << endl << endl;
			adminMainMenu();
			break;
		}
		else {
			cout << "\nLogin unsucessfull " << endl;
			cout << "\nAdmin Username or Password is incorrect " << endl;
			cout << "\nRe-Enter Credentails";
			cout << endl << endl;
			login();
			break;
		}
	case 2:
		cout << "\nLogin Into the System" << endl;
		cout << "\nUsername :"; cin >> user;
		cout << "\nPassword :";	cin >> pass;
		if (user == "user" && pass == "user") {
			cout << " \nLogin Sucessfull" << endl;
			cout << " \nWelcome!\n" << endl << endl;
			SalesExecutiveMainMenu();
			break;
		}
		else {
			cout << "\nLogin Unsucessfull " << endl;
			cout << "\nUsername or Password is incorrect " << endl;
			cout << "\nRe-Enter Credentails";
			cout << endl << endl;
			login();
			break;
		}
	case 3:
		exit(0);
		break;
	default:
		cout << "Not a Valid Choice.\n";
		login();
		break;
	}
}

int main() {
	login();
}