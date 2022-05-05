#include<bits/stdc++.h>
#define SPACE 10
using namespace std;
class TreeNode
{
    public:
    int value;
    TreeNode* right;
    TreeNode* left;
    TreeNode()
    {
        this->value=0;
        this->left=NULL;
        this->right=NULL;
    }
    TreeNode(int value)
    {
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }
};
class BST
{
    public:
    TreeNode* root;
    BST()
    {
        root=NULL;
    }
    BST(TreeNode* newNode)
    {
        root=newNode;
    }
    bool isEmpty()
    {
        if(root==NULL)
        {
            return true;
        }
        else return false;
    }
    void insertNode(TreeNode* newNode)
    {
        if(root==NULL)
        {
            root=newNode;
        }
        else{
        TreeNode* temp=root;
        while(temp!=NULL)
        {
            if(newNode->value==temp->value)
            {
                cout<<"Same value not allowed";
                return;
            }
            else if(((newNode->value)<(temp->value)) && temp->left==NULL)
            {
                temp->left=newNode;
                break;
            }
            else if(((newNode->value)<(temp->value)))
            {
                temp=temp->left;
            }
            else if(((newNode->value)>(temp->value)) && temp->right==NULL)
            {
                temp->right=newNode;
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
        }
    }
    void print2D(TreeNode * r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
  void preOrderTraversal(TreeNode* r)
  {
      if(r==NULL) return;
      else
      {
          cout<<r->value<<" ";
          preOrderTraversal(r->left);
          preOrderTraversal(r->right);
      }
      //cout<<endl;
  }
  void postOrderTraversal(TreeNode* r)
  {
      if(r==NULL) return;
      else
      {
          postOrderTraversal(r->left);
          postOrderTraversal(r->right);
          cout<<r->value<<" ";
      }
      //cout<<endl;
  }
  void inOrderTraversal(TreeNode* r)
  {
      if(r==NULL) return;
      else
      {
          inOrderTraversal(r->left);
          cout<<r->value<<" ";
          inOrderTraversal(r->right);
      }
      //cout<<endl;
  }
  TreeNode* iterativeSearce(int val)
  {
      if(root==NULL)
      {
          return root;
      }
      else
      {
          TreeNode* temp=root;
          while(temp!=NULL)
          {
              if(val==temp->value)
              {
                return temp;
              }
              else if(val<temp->value)
              {
                  temp=temp->left;
              }
              else
              {
                  temp=temp->right;
              }
          }
          return NULL;
      }
  }
  int height(TreeNode* r)
  {
      if(r==NULL)
      {
          return -1;
      }
      else
      {
          int lheight=height(r->left);
          int rheight=height(r->right);
          if(lheight>rheight)
          {
              return (lheight+1);
          }
          else
          {
              return (rheight+1);
          }
      }
  }
  void printBFS(TreeNode* r)
  {
      int h=height(r);
      for(int i=0;i<=h;i++)
      {
          printGivenLevel(r,i);
      }
  }
  void printGivenLevel(TreeNode* r,int level)
  {
      if(r==NULL)
      {
          return;
      }
      else
      {
          if(level==0)
          {
              cout<<r->value<<" ";
          }
          else
          {
              printGivenLevel(r->left,level-1);
              printGivenLevel(r->right,level-1);
          }
      }
  }
  TreeNode* minValue(TreeNode* node)
  {
      TreeNode* current=node;
      while(current->left!=NULL)
      {
          current=current->left;
      }
      return current;
  }
  TreeNode* deleteNode(TreeNode* r,int value)
  {
      if(r==NULL)
      {
          return NULL;
      }
      else if(value<r->value)
      {
          r->left=deleteNode(r->left,value);
      }
      else if(value>r->value)
      {
          r->right=deleteNode(r->right,value);
      }
      else
      {
          if(r->left=NULL)
          {
              TreeNode* temp=r->right;
              delete r;
              return temp;
          }
          else if(r->right==NULL)
          {
              TreeNode* temp=r->left;
              delete r;
              return temp;
          }
          else
          {
              TreeNode* temp=minValue(r->right);
              r->value=temp->value;
              r->right=deleteNode(r->right,temp->value);
          }
      }
      return r;
  }
};
int main()
{
    int option,val;
    BST obj;
    do
    {
        cout<<"\n1.Insertion"<<endl;
        cout<<"2.Printing"<<endl;
        cout<<"3.Search item"<<endl;
        cout<<"4.Find the height of the tree"<<endl;
        cout<<"5.BFS printing"<<endl;
        cout<<"6.Deleting"<<endl;
        cout<<"Please enter your option: ";
        cin>>option;
        TreeNode* tr=new TreeNode();
        switch (option)
        {
        case 1:
            cout<<"Enter a number you want to insert: ";
            cin>>val;
            tr->value=val;
            obj.insertNode(tr);
            cout<<"Node inserted"<<endl;
            break;
        case 2:
            obj.print2D(obj.root,5);
            cout<<"Preorder Traversal: ";   
            obj.preOrderTraversal(obj.root); 
            cout<<endl;
            cout<<"Postorder Traversal: ";
            obj.postOrderTraversal(obj.root);
            cout<<endl;
            cout<<"In-order Traversal: ";
            obj.inOrderTraversal(obj.root);
            break;
        case 3: 
            cout<<"Enter the value you want to search: ";
            cin>>val;
            tr=obj.iterativeSearce(val);
            if(tr!=NULL)
            {
                cout<<"Value found!"<<endl;
            }
            else cout<<"Value not found"<<endl;
            break;
        case 4:
            cout<<"Height of the tree is: ";
            cout<<obj.height(obj.root)<<endl;
            
            break;
        case 5:
            cout<<"BFS printing: ";
            obj.printBFS(obj.root);
            break;
        case 6:
            cout<<"Delete"<<endl;
            cout<<"Delete the item you want to delete: ";
            cin>>val;
            tr=obj.iterativeSearce(val);
            if(tr!=NULL)
            {
                obj.deleteNode(obj.root,val);
                cout<<"Node deleted";
            }        
            else
            {
                cout<<"Node doesn't exist";
            }
            break;
        default:
            break;
        }
    } while (option!=0);
    
}