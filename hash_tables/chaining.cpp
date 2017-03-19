/*
    SIMPLE CHAINING
*/

#include <iostream>
#define TABLE_SIZE 10
using namespace std;

class HashNode{

public:
  int value;
  HashNode *next;
  HashNode(int value){
    this->value = value;
    this->next = NULL;
  }
};

class HashTable{

private:
  HashNode **table;
public:
  HashTable(){
    table = new HashNode*[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++){
      table[i] = NULL;
    }
  }

  //Hash Function
  int hash(int key){
    return key % TABLE_SIZE;
  }

  //Insert
  void insert(int value){
    HashNode *node = new HashNode(value);
    int hashVal = hash(value);
    HashNode *head = table[hashVal], *cur;
    if(!head){
      head = node;
    } else{
      cur = head;
      while(cur->next != NULL){
        cur = cur->next;
      }
      cur->next = node;
    }
    table[hashVal] = head;
  }

  //Show
  void show(){
    for(int i=0; i<TABLE_SIZE; i++){
      cout << "  " << i << " :\t";
      HashNode *head = table[i];
      while(head!=NULL){
        cout << head->value << "  ";
        head = head->next;
      }
      cout << "\n";
    }
    cout << "\n";
  }

  //Search
  bool search(int value){
    int hashVal = hash(value);
    HashNode *head = table[hashVal];
    while(head!=NULL){
      if(head->value == value)
        return true;
      head = head->next;
    }
    return false;
  }

  //Delete
  void remove(int value){
    int hashVal = hash(value);
    if(this->search(value)){
      HashNode *head = table[hashVal], *curr, *prev;
      curr = head;
      prev = NULL;

      while(curr != NULL){
        if(curr->value == value){
          if(prev)
            prev->next = curr->next;
          else
            table[hashVal] = curr->next;
          break;
        }
        prev = curr;
        curr = curr->next;
      }
    }
  }

};

int main(){

  HashTable table;
  table.insert(24);
  table.insert(4);
  table.insert(14);
  table.insert(5);
  table.show();
  table.remove(24);
  table.remove(14);
  table.remove(5);
  table.show();
  table.insert(14);
  table.insert(5);
  table.show();
  return 0;
}
