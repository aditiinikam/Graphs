#include<iostream>
#include<list>
using namespace std;

class Graph{
public:
  int V;
  list<int> *l;        //declaring a list of integers and assigning a pointer to it.

  //constructor
  Graph(int V){
    this->V=V;
    l=new list<int>[V];   //initializing the pointer l with an array of lists
  }

  //adding an edge in the directed graph
  void addEdge(int from, int to){
    l[from].push_back(to);  //since we are using a directed graph, we are adding it to only one adjecency list ie. the to list
  }

  //displaying it
  void display(){
    //iterate over all vertices
    for(int i=0;i<V;i++){
      cout<<" Vertex "<<i<<" : ";
      for(int itr:l[i]){      //iterator to iterate over every list associated with the vertex
        cout<<itr<<" ";
      }
      cout<<endl;
    }
  }

  void displayParticular(int vertex){
    if(vertex<0 || vertex>6){
      cout<<" Invalid vertex entered !! ";
      // continue;
    }
    else{
        cout<<" The locations accessible from vertex "<<vertex<<" are : ";
        for(int itr:l[vertex]){      //iterator to iterate over the array associated with that particular vertex
          cout<<itr<<" ";
        }
        cout<<endl;
      }
  }

  bool check(int vertex, int input){
    bool b=false;
    for(int itr:l[vertex]){      //iterator to iterate over the array associated with that particular vertex
      if(itr==input){
        b=true;
      }
    }
    return b;
  }

};

//linked list to store the user path
class Node
{
    public:
    int data;
    Node *next;
};

//function to append it at the end of the linkedList
void append(Node** head_ref, int new_data){
    Node* new_node = new Node();    //allocate a node
    Node *last = *head_ref;   //for later use
    new_node->data = new_data;
    new_node->next = NULL;    //this will be the last node, so pointer will be NULL
    if (*head_ref == NULL){       //if the linked list is empty then new_node=head
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL){    //if not empty, traverse till the end
        last = last->next;
    }
    last->next = new_node;
    return;
}

//print the linkedList
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" ----> "<<node->data;
        node = node->next;
    }
}


//variable declaration
int input;
//creating an object of Graph class and adding edges of the directed graph
Graph g_user(6);
Graph g(6);
Node* head = NULL;

//function to get the data regarding the next place to go
int getData(int start_loc){
  g.displayParticular(start_loc);
  cout<<"\n Where would you like to go from vertex "<<start_loc<<" ? ";
  cin>>input;
  bool b=g.check(start_loc,input);  //returns true if there exists a path from start_loc to input vertex

  if(b){
    append(&head,input);
    printList(head);
  }
  else{
    cout<<"\n There doesn't exist a path from "<<start_loc<<" to "<<input;
  }
  return b;
}

int main(){

  int start;
  char decision2;

  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,0);
  g.addEdge(2,1);
  g.addEdge(2,3);
  g.addEdge(1,3);
  g.addEdge(3,1);
  g.addEdge(1,4);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.addEdge(5,3);

  cout<<"\t\t ------------- WELCOME ------------";

  cout<<"\n\n FOLLOWING ARE THE LOCATIONS ACCESSIBLE FROM THE VERTICES 0 TO 5 : "<<endl;
  g.display();

  cout<<"\n Enter the starting vertex : ";
  cin>>input;
  append(&head,input);
  int input2;
  // the loop will execute until the user doesn't enter n or any character except y
  do{
    input2=input;
    bool b=getData(input2);  //execute getData and get the boolean value
    //input2 variable was used instead of input because it took the starting value into consideration
    // instead of the current input value, while the user was trying again

    if(b==false){
      cout<<"\n Try again ? y/n ";
      char decision;
      cin>>decision;
      if(decision=='y'){
        b=getData(input2);   //if the user wants to try again, execute the getData function with the same input value again
      }
      else{
        cout<<"\n See you next time!!";
        exit(0);
      }
    }
    else{
      cout<<"\n Do you want to continue travelling? y/n ";
      cin>>decision2;
    }
  }while (decision2=='y');

  cout<<"\n\t ------------ THANK YOU ---------------";

  return 0;

}

