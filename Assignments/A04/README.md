## Assignment 4 - Binary Trees 

### Problems

- UVA 12347 https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3769 about pre,in, and postfix
- UVA 1264 https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=247&page=show_problem&problem=3705 about permutation

### Example List Based Tree

- This is a List Based Binary Search Tree using a class  
- It uses dynamic memory allocation so that there aren't any spacing issues for if you don't know the input size
- It doesn't deal with deleting nodes, but that could be added.
- It also has a method from the class that will print the Binary Tree Inorder.

```cpp
#include <iostream> 
using namespace std; 
  
class BST 
{ 
    int data; 
    BST *left, *right; 
  
    public: 
      
    // Default constructor. 
    BST(); 
      
    // Parameterized constructor. 
    BST(int); 
      
    // Insert function. 
    BST* Insert(BST *, int); 
      
    // Inorder traversal. 
    void Inorder(BST *); 
}; 
  
// Default Constructor definition. 
BST :: BST() : data(0), left(NULL), right(NULL){} 
  
// Parameterized Constructor definition. 
BST :: BST(int value) 
{ 
    data = value; 
    left = right = NULL; 
} 
  
// Insert function definition. 
BST* BST :: Insert(BST *root, int value) 
{ 
    if(!root) 
    { 
        // Insert the first node, if root is NULL. 
        return new BST(value); 
    } 
  
    // Insert data. 
    if(value > root->data) 
    { 
        // Insert right node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 
          
        // Process right nodes. 
        root->right = Insert(root->right, value); 
    } 
    else
    { 
        // Insert left node data, if the 'value'  
        // to be inserted is greater than 'root' node data. 
          
        // Process left nodes. 
        root->left = Insert(root->left, value); 
    } 
      
    // Return 'root' node, after insertion. 
    return root; 
} 
  
// Inorder traversal function. 
// This gives data in sorted order. 
void BST :: Inorder(BST *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    Inorder(root->left); 
    cout << root->data << endl; 
    Inorder(root->right); 
} 
  
// Driver code 
int main() 
{ 
    BST b, *root = NULL; 
    root = b.Insert(root, 50); 
    b.Insert(root, 30); 
    b.Insert(root, 20); 
    b.Insert(root, 40); 
    b.Insert(root, 70); 
    b.Insert(root, 60); 
    b.Insert(root, 80); 
  
    b.Inorder(root); 
    return 0; 
} 
```
- Source: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

### Example Array Based Tree

- This is a Array Based Binary Search Tree using a class 
- It uses an dynamic array with an extendsize method so no need to worry about size
- It doesn't deal with deleting nodes, but that could be added.
- It also has methods to print the tree out int pre,in, or postfix if need be

```cpp
#include<iostream>
using namespace std;


public:
    int size;
    int* array;

    void insertElement(int x);
    void searchElement(int x);
    void inOrder(int currentIndex);
    void preOrder(int currentIndex);
    void postOrder(int currentIndex);
    void parent(int x);
    int extendSize(int x);

    BinarySearchTree (int size) {
        this -> size = extendSize(size);
        //cout << this -> size << endl;
        this -> array = new int[this -> size];
        for(int x = 0; x < this -> size; x++){
            array[x] = NULL;
        }
    }
};

int BinarySearchTree::extendSize(int x) {
    int value = 0;
    for(int y = 0; y < x + 1; y++) {
        value = (2 * value) + 2;
    }
    return value;
}

void BinarySearchTree::insertElement(int x) {
    int currentIndex = 0;
    cout << "Adding: " << x;
    while(true) {
        if(array[currentIndex] == NULL){
            array[currentIndex] = x;
            cout << " Inserted at index: " << currentIndex << endl;
            break;
        }else if(array[currentIndex] <= x) {
            if(array[currentIndex] == x){
                cout << "ERROR!-- Repeating element" << endl;
                break;
            }else
            cout << " Right ";
            currentIndex = (2 * currentIndex + 2);
        }else if(array[currentIndex] >= x) {
             if(array[currentIndex] == x){
                cout << "ERROR!-- Repeating element" << endl;
                break;
            }else
            cout << " Left ";
            currentIndex = (2 * currentIndex + 1);
        }

    }
}

void BinarySearchTree::searchElement(int x){
    int currentIndex = 0;
    while (true) {
            if (array[currentIndex] == NULL) {
            cout << "Not Found" << endl;
            break;
            }
            if (array[currentIndex] == x) {
            cout << "Found at index: " << currentIndex << endl;
            break;
            }
            else if(array[currentIndex] < x) {
            currentIndex = (2 * currentIndex + 2);
        }
            else if(array[currentIndex] > x) {
            currentIndex = (2 * currentIndex + 1);
        }

    }

}

void BinarySearchTree::parent(int x){
    while (x != 0) {
        x = (x-1) / 2;
        cout << "---";
    }

}

void BinarySearchTree::inOrder(int currentIndex){
    if(array[currentIndex] != NULL) {
            inOrder(2 * currentIndex + 1);
            parent(currentIndex);
            cout << array[currentIndex] << endl;
            inOrder(2 * currentIndex + 2);

    }
}

void BinarySearchTree::postOrder(int currentIndex) {
    if(array[currentIndex] != NULL){
        postOrder(2 * currentIndex + 1);
        postOrder(2 * currentIndex + 2);
        parent(currentIndex);
        cout << array[currentIndex] << " " << endl;
    }

}

void BinarySearchTree::preOrder(int currentIndex) {
    if(array[currentIndex] != NULL) {
        preOrder(2 * currentIndex + 1);
        parent(currentIndex);
        cout << array[currentIndex] << " " << endl;
        preOrder(2 * currentIndex + 2);
    }
}

int main () {
    BinarySearchTree frank(5);
    frank.insertElement(4);
    frank.insertElement(6);
    frank.insertElement(9);
    frank.insertElement(3);
    frank.insertElement(2);
    frank.searchElement(1);
    frank.inOrder(0);
};
}
```
- Source: https://www.daniweb.com/programming/software-development/threads/466340/c-binary-search-tree-array-implementation