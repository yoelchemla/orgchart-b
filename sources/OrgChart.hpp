#pragma once
#include<queue>
#include <stack>
#include <vector>
#include <string>
#include<iostream>
#include<iterator>


using namespace std;

namespace ariel{

class OrgChart{

struct Node{
                    //defalut in struct is public, class- private
private:
    vector<Node*> child;
    string name;

public:
    Node(const string &name_){//constructor
        this->name = name_;
    }

    void add_child(Node *ch){
        child.push_back(ch);
    }

    void set_child(const vector <Node*> &ch1){
        child = ch1;
    }

    vector<Node*> get_child()const{
        return child;
    }

    void setName(const string &name_){
        name = name_;
    }

    string getName()const { 
        return name;
    }

    size_t theSize() const{
        return child.size();
    }
        
};


        //initalization
    Node* root = nullptr;
    vector<string> it;
    int size = 0;
    

 public:
        
    OrgChart &add_sub(const string &s1, const string &s2){//v
                //testing
        if(root == NULL){
            throw invalid_argument("parent doesn't exist");
            return *this;
        }
        if(s1.empty()){
            throw invalid_argument("the parent can't be empty");
        } 
         if(s2.empty()){
            throw invalid_argument("the son can't be empty");
        }  

        queue<Node*> queue1; //create a new queue
        queue1.push(root);
        
        while (!queue1.empty()){
            Node* ans =queue1.front();
            if(ans->getName() == s1){ //if is the parent
                ans->add_child(new Node(s2));
                this->size++;//update the size
                return *this;
            }
            queue1.pop(); //dequeue
            for(size_t i =0; i<ans->theSize();i++ ){
                queue1.push(ans->get_child()[i]);
            }
        }
        throw invalid_argument("error"); // the parent doesn't founded
    }

    OrgChart &add_root(const string & name){ //add a src node
        if(name.empty()){ //mikre katze
           __throw_invalid_argument("invalid");
        }

        if(root!= nullptr){
            root ->setName(name); //update
        }
            //root == nullptr, create a new
        else{
            root = new Node(name);
            size++;
        }
        return *this;
    }

    void mikreKatze(){
        if(root == NULL) {throw invalid_argument("error");}
    }


class Iterator{

 public:

    using reference = string&;
    using pointer = string*;
    
 private:

    pointer ptr;
 
 public:
    Iterator(pointer p){ //constructor
        this->ptr = p;
    }   
            // the relevant operators
    friend bool operator !=(const Iterator &iter1, const Iterator &iter2){//v
       return iter1.ptr != iter2.ptr;
    }

    pointer operator ->(){//v
        return ptr;
    }
    
    reference operator *() const{ //v
        return *ptr;
    }
    
     
    Iterator & operator ++(){//v
        ptr++;
        return *this;  
    }

};
    //function that check which action to choose
    void checkSituation(char possibility){
        if(possibility == 'a'){
            this->levelOrd(this->root);
        }
        if(possibility == 'b'){
            this->reverseLevelOrd(this->root);
        }
        if(possibility == 'c'){
            this->preOrd(this->root);
        }
    }
        //the situations:
    void reverseLevelOrd(Node * root){
        if(root == NULL) {return;}

            //create a q and stack for the reverse action
        stack<Node*>stack1;
        queue<Node*> queue2;

        queue2.push(root);

        while ((!queue2.empty())){
            root = queue2.front();
            queue2.pop();
            stack1.push(root);
            vector<Node*> child = root->get_child();
            reverse(child.begin(), child.end());
            
            for(size_t i=0; i<child.size(); i++){
                queue2.push(child[i]);
            }
        }
        while (!stack1.empty()){
            root =stack1.top();
            this->it.push_back(root->getName());
            stack1.pop();
        }
    }

    void levelOrd(Node * root){//v
        if(root == NULL){ return;}
       
       it.push_back(root->getName());//entrance the name of thr root
       queue<Node*> queue3; //create a new Q
       queue3.push(root);
       
       while (!queue3.empty()){
          Node* ans = queue3.front();
          queue3.pop();

          for(size_t i=0; i<ans->theSize(); i++){
            queue3.push(ans->get_child()[i]); //entrance the child
            it.push_back(ans->get_child()[i]->getName());  //entrance the name of the child
          }
       }
    }

    void preOrd(Node * node){//v
        if(root ==NULL) {return;}
        this->it.push_back(node->getName());

        for(size_t i=0; i< node->theSize(); i++){
            this->preOrd(node->get_child()[i]);
        }
    }
    
    
    Iterator begin_level_order(){
        mikreKatze();
        it.clear();//empty the vector
        checkSituation('a'); //level order
        return Iterator(&it[0]); //the first place
    }

    Iterator end_level_order(){
        mikreKatze();
        return Iterator(&this->it[this->it.size()]);
    }
   
    Iterator begin_reverse_order(){
        mikreKatze();
        it.clear();//empty the vector
        checkSituation('b'); //reversr level order
        return Iterator(&it[0]);
    }
    
    Iterator begin_preorder(){
       mikreKatze();
        it.clear();//empty the vector
        checkSituation('c'); //preorder 
        return Iterator(&this->it[0]);
    }
    
    Iterator end_preorder(){
        mikreKatze();
        return Iterator(&this->it[this->it.size()]);
    }

    Iterator reverse_order(){
        mikreKatze();
        return Iterator(&this->it[this->it.size()]);

    }
    
    Iterator begin(){
        mikreKatze();
        it.clear();//empty the vector
        checkSituation('a'); 
        return Iterator(&it[0]);
    }

    Iterator end(){
        mikreKatze();
        return Iterator(&this->it[this->it.size()]);
    }
 
    friend ostream &operator <<(ostream &out, OrgChart &src){ 
        if(src.root == NULL){ return out;} //default
        
        //create 2 queue:
        queue<Node*> queue4;
        queue<string> queue4_1;

        queue4.push(src.root);
        queue4_1.push(src.root->getName()); //his name
        out<< src.root->getName()<< endl;

        while (!queue4.empty()){
            Node* ans = queue4.front();
            queue4.pop(); //dequeue
            string nameOne = queue4_1.front();//the first name
            queue4_1.pop(); //dequeue
           
            for(size_t i=0; i<ans->theSize(); i++){
                queue4.push(ans->get_child()[i]);
                string nameTwo = nameOne + " "+ ans->get_child()[i]->getName(); //the second name
                out<<nameTwo<<endl;
                queue4_1 .push(nameTwo); //entrance the second name to the queue of strings
            }
        }
        return out;   
    }
};
}
 
