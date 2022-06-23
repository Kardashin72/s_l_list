#pragma once
#include <iostream>

using namespace std;

struct elem {
	int val = 0;
	elem* next = nullptr;
};

class sl_list {
	elem* head = nullptr;
	elem* tail = nullptr;
	int size = 0;
public:
	//back
	//front
	//clear >> ����
	//empty
	//remove
	//size


	//reverse
	//sort
	//unique - ������� ��� ��������� ������ � ��������������� ������
	sl_list() = default;
	sl_list(const sl_list& sll) {
		elem* tmp_e = sll.head;
		while (tmp_e != nullptr) {
			this->push_back(tmp_e->val);
			tmp_e = tmp_e->next;
		}
	}

	sl_list& operator=(const sl_list& sll) {
		if (this == &sll)
			return *this;
		this->~sl_list();
		elem* tmp_e = sll.head;
		while (tmp_e != nullptr) {
			this->push_back(tmp_e->val);
			tmp_e = tmp_e->next;
		}
		return *this;
	}

	sl_list(sl_list&& sll) {
		swap(this->head, sll.head);
		swap(this->tail, sll.tail);
		swap(this->size, sll.size);
	}

	sl_list& operator=(sl_list&& sll) {
		swap(this->head, sll.head);
		swap(this->tail, sll.tail);
		swap(this->size, sll.size);
		return *this;
	}

	int front() const {
		return this->head->val;
	}

	int back() const {
		return this->tail->val;
	}

	int get_size() const {
		return this->size;
	}

	bool empty() const {
		return this->head == nullptr;
	}

	void clear() {
		this->~sl_list();
	}

	void remove(int val) {
		if (this->head == nullptr)
			return;
		elem* n_elem1 = this->head;
		int tmp = 0;
		while (n_elem1 != this->tail) {
			if (n_elem1->val == val) {
				n_elem1 = n_elem1->next;
				this->erase(tmp);
			}
			else {
				n_elem1 = n_elem1->next;
				tmp++;
			}
		}
		if (this->tail->val == val)
			this->pop_back();
		
	}



	void push_back(int val) {
		elem* n_elem = new elem;
		n_elem->val = val;
		this->size++;
		if (this->head == nullptr) {
			this->head = this->tail = n_elem;
			return;
		}
		this->tail->next = n_elem;
		this->tail = n_elem;
	}

	void push_front(int val) {
		elem* n_elem = new elem;
		n_elem->val = val;
		this->size++;
		if (this->head == nullptr) {
			this->head = this->tail = n_elem;
			return;
		}
		n_elem->next = this->head;
		this->head = n_elem;
	}

	void pop_front() {
		if (this->head == nullptr)
			return;
		if (this->head == this->tail) {
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
			this->size = 0;
			return;
		}

		elem* tmp = this->head->next;
		delete this->head;
		this->head = tmp;
		this->size--;
	}

	void pop_back() {
		if (this->head == nullptr)
			return;
		if (this->head == this->tail) {
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
			this->size = 0;
			return;
		}

		elem* tmp = this->head;
		while (tmp->next != this->tail) {
			tmp = tmp->next;
		}
		tmp->next = nullptr;
		delete this->tail;
		this->tail = tmp;
		this->size--;
	}

	void insert(int val, int index) {
		if (index < 0 || index > this->size)
			return;
		if (index == 0) {
			this->push_front(val);
			return;
		}
		if (index == this->size) {
			this->push_back(val);
			return;
		}
		elem* n_elem = new elem;
		n_elem->val = val;
		elem* tmp_e = this->head;
		int tmp = 0;
		while (tmp < index - 1) {
			tmp_e = tmp_e->next;
			tmp++;
		}
		n_elem->next = tmp_e->next;
		tmp_e->next = n_elem;
		this->size++;
	}

	void erase(int index) {
		if (index < 0 || index > this->size - 1)
			return;
		if (index == 0) {
			this->pop_front();
			return;
		}
		if (index == this->size - 1) {
			this->pop_back();
			return;
		}
		elem* tmp_e = this->head;
		int tmp = 0;
		while (tmp < index - 1) {
			tmp_e = tmp_e->next;
			tmp++;
		}
		elem* tmp_e2 = tmp_e->next->next;
		delete tmp_e->next;
		tmp_e->next = tmp_e2;
		this->size--;
	}

	void print() const {
		elem* tmp = this->head;
		while (tmp != nullptr) {
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	~sl_list() {
		while (this->head != nullptr) {
			this->pop_front();
		}
	}

};