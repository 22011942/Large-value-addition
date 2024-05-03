#include <iostream>
using namespace std;

template <class T>
class List {
private:
  struct Node {
    T data;
    Node *next;
  };
  Node *front, *current;
public:
  List();
  ~List();
  void AddtoFront(T value);
  bool FirstItem(T & item);
  bool NextItem(T & item);
  bool valid();
};

class LargeValue {
private:
  List<int> digitlist;
public:
  LargeValue();
  ~LargeValue();
  void Stringtoint(string value);
  void PrintBN();
  void AddBN(LargeValue B1, LargeValue B2);
};

LargeValue number1, number2, number3;

int main() {
  string Svalue1, Svalue2;
  cin >> Svalue1;
  cin >> Svalue2;
  number1.Stringtoint(Svalue1);
  number2.Stringtoint(Svalue2);
  number3.AddBN(number1, number2);
  number3.PrintBN();
}


template <class T>
List<T>::List() {
  front = NULL;
  current = NULL;
}

template <class T>
List<T>::~List() {
}

template <class T>
void List<T>::AddtoFront(T value) {
  Node *temp;
  temp = new Node;
  temp -> data = value;
  temp -> next = front;
  front = temp;
}

template <class T>
bool List<T>::FirstItem(T & item) {
  if (front == NULL) {return false;}
  item = front -> data;
  current = front;
  return true;
}

template <class T>
bool List<T>::valid() {
  if (current == NULL) {return false;}
  return true;
}

template <class T>
bool List<T>::NextItem(T & item) {
  if (current == NULL) {return false;}
  current = current -> next;
  if (current == NULL) {return false;}
  item = current -> data;
  return true;
}


LargeValue::LargeValue() {
}

LargeValue::~LargeValue() {
}

void LargeValue::Stringtoint(string value) {
  int indx, temp;
  for (indx = 0; indx < (int) value.length(); indx++) {
    temp = value[indx] - 48;
    digitlist.AddtoFront(temp);
  }
}

void LargeValue::AddBN(LargeValue B1, LargeValue B2) {
  int carry, digit1, digit2, thing, unCompRes;
  carry = 0;
  B1.digitlist.FirstItem(thing);
  digit1 = thing;
  B2.digitlist.FirstItem(thing);
  digit2 = thing;
  while (B1.digitlist.valid() == true || B2.digitlist.valid() == true) {
    unCompRes = digit1 + digit2 + carry;
    digitlist.AddtoFront(unCompRes % 10);
    if (unCompRes <= 9) {
      carry = 0;
    } else {
      carry = 1;
    }
    if (B1.digitlist.NextItem(thing) == true) {
      digit1 = thing;
    } else {
      digit1 = 0;
    }
    if (B2.digitlist.NextItem(thing) == true) {
      digit2 = thing;
    } else {
      digit2 = 0;
    }
  }
  if (carry != 0) {
    digitlist.AddtoFront(carry);
  }
}

void LargeValue::PrintBN() {
  int thing, digit;
  digitlist.FirstItem(thing);
  digit = thing;
  while (digitlist.NextItem(thing) == true) {
    cout << digit;
    digit = thing;
  }
  cout << digit << endl;
}
