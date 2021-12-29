#include <iostream>
#include <array>

using namespace std;

template<typename T> class BSNode{
public:
    explicit BSNode(T value): key(value){}

    T key;
    BSNode *left{nullptr};
    BSNode *right{nullptr};
    BSNode *parent{nullptr};
};

template<typename T> class BinarySearchTree{
public:
    BinarySearchTree() = default;
    void preOrderImpl(BSNode<T>* node){
        if(node == nullptr)
            return;
        cout<<node->key<<" ";
        preOrderImpl(node->left);
        preOrderImpl(node->right);
    }
    ///前序遍历
    void preOrder(){
        cout<<"preOrder:";
        preOrderImpl(root);
  }

  void midOrderImpl(BSNode<T>* node){
        if(node == nullptr)
            return;
        midOrderImpl(node->left);
        cout<<node->key<<" ";
        midOrderImpl(node->right);
    }
    ///中序遍历
    void midOrder(){
        cout<<"midOrder:";
        midOrderImpl(root);
    }

    void postOrderImpl(BSNode<T>* node){
        if(node == nullptr)
            return;
        postOrderImpl(node->left);
        postOrderImpl(node->right);
        cout<<node->key<<" ";
    }
    ///后序遍历
    void postOrder(){
        cout<<"postOrder:";
        postOrderImpl(root);
    }

    BSNode<T>* searchImpl(BSNode<T>* node, T key){
        if(node== nullptr || node->key==key){
            return node;
        }
        if(key < node->key){
            return searchImpl(node->left,key);
        }
        else{
            return searchImpl(node->right,key);
        }
    }
    ///查找一个具有给定关键字的节点
    BSNode<T>* search(T key){
        return searchImpl(root,key);
    }

    ///通过循环实现查找
    BSNode<T>* iterativeSearch(T key){
        auto x = root;
        while(x!= nullptr && key!=x->key){
            if(key < x->key){
                x = x->left;
            }
            else{
                x=x->right;
            }
        }
        return x;
    }


    BSNode<T>* minimum(BSNode<T>* x){
        while(x->left!= nullptr){
            x=x->left;
        }
        return x;
    }

    T minimum_tree(){
        return minimum(root)->key;
    }

    BSNode<T>* maximum(BSNode<T>* x){
        while(x->right!= nullptr){
            x=x->right;
        }
        return x;
    }

    T maximum_tree(){
        return maximum(root)->key;
    }


    ///获得一个节点的后继,以中序遍历
    BSNode<T>* successor(BSNode<T> *x){
        ///如果节点的右边的子树非空，则在右子树中寻找最小值，即为x节点的后继节点
        if(x->right!= nullptr){
            return  minimum(x->right);
        }
        ///如果节点x的右子树为空
        else{
            auto y = x->parent;
            while(y!= nullptr && x==y->right){
                x=y;
                y=y->parent;
            }
            return y;
        }
    }


    ///获得一个节点的前驱，以中序遍历
    BSNode<T>* predecessor(BSNode<T> *x){
        if(x->left!= nullptr){
            return maximum(x->left);
        }
        else{
            auto y=x->parent;
            while(y!= nullptr && x==y->left){
                x=y;
                y=y->parent;
            }
            return y;
        }
    }


    void insert(T key){
        if(auto result=search(key);result!= nullptr){
            return;
        }
        else{
            auto node=new BSNode<T>(key);
            auto x=root;
            decltype(x) y= nullptr;
            while(x!= nullptr){
                y=x;
                if(key<x->key){
                    x=x->left;
                }
                else{
                    x=x->right;
                }
            }
            node->parent=y;

            if(y== nullptr){
                root=node;
            }
            else if(node->key < y->key){
                y->left = node;
            }
            else{
                y->right=node;
            }

        }
    }

    ///用一棵以节点v为根的树 替换一棵以节点u为根的树
    void Transplant(BSNode<T>* u, BSNode<T>* v){
        //the tree is empty
        if(u== nullptr){
            root=v;
        }
        //u is a left tree
        else if( u== u->parent->left){
            u->parent->left=v;
        }
        //u is a right tree
        else{
            u->parent->right=v;
        }
        if(v!= nullptr){
            v->parent=u->parent;
        }
    }


    void remove(BSNode<T>* z){
        if(z->left== nullptr){
            Transplant(z,z->right);
        }
        else if(z->right == nullptr){
            Transplant(z,z->left);
        }
        ///z有两个孩子的情况
        else{
            //获得z的后继节点
            auto y= minimum(z->right);
            if(y->parent!=z){
                Transplant(y,y->right);
                y->right=z->right;
                y->right->parent = y;
            }
            Transplant(z,y);
            y->left=z->left;
            y->left->parent=y;
        }

    }


    void destroyImpl(BSNode<T>* node){
        if(node == nullptr)
            return;
        destroyImpl(node->left);
        destroyImpl(node->right);
        delete node;
    }
    void destroy(){
        destroyImpl(root);
    }


private:
    BSNode<T> *root;
};






enum class Color{
    Red,
    Black
};

template<typename T> class RBNode{
public:
    explicit RBNode(T value,Color color_):key(value),color(color_){}
    T key;
    Color color;
    RBNode<T> *parent{nullptr};
    RBNode<T> *right{nullptr};
    RBNode<T> *left{nullptr};
};

///红黑树的性质：
/*
1.每个节点要么是黑色的要么是红色的
2.根结点是黑色的
3.每个叶节点是黑色的
4.如果一个节点是红色的，则它的的两个叶节点是黑色的。
5.对于每个节点，从该节点到其它所有后代节点的简单路径上，均包含相同数目的黑色节点
*/
template<typename T> class RBTree{
public:
    RBTree(){
        nil=new RBNode<T>(0,Color::Black);
    }
    ~RBTree(){
        delete nil;
    }

    RBNode<T>* searchImpl(RBNode<T>* node,T key){
        if(node== nullptr || node->key==key)
            return node;
        else if(key < node->key){
            return searchImpl(node->left,key);
        }
        else{
            return searchImpl(node->right,key);
        }
    }

    RBNode<T>* search(T key){
        return searchImpl(root,key);
    }

    ///左旋
    void leftRotation(RBNode<T>* x){
        //将y放到x的位置
        auto y = x->right;
        y->parent=x->parent;
        if(x->parent == nil){
            root=y;
        }
        else if(x==x->parent->left){
            x->parent->left=y;
        }
        else{
            x->parent->right=y;
        }
        x->parent=y;

        //将y.left连接到x.right
        x->right = y->left;
        if(y->left != nil){
            y->left->parent = x;
        }

        y->left=x;
    }


    ///右旋
    void rightRotation(RBNode<T>* y){
        auto x = y->left;
        x->parent = y->parent;
        if(y->parent == nil){
            root=x;
        }
        else if(y == y->parent->left){
            y->parent->left=x;
        }
        else{
            y->parent->right=x;
        }

        y->parent=x;
        y->left = x->right;
        if(y->left!=nil){
            y->left->parent = y;
        }

        x->right = y;
    }

    ///保持红黑性质
    void insert_fixup(RBNode<T>* z){
        while(z->parent->color==Color::Red)
        {
            //z的父节点是左节点
            if(z->parent == z->parent->parent->left){
                //z的叔叔节点
                auto y=z->parent->parent->right;
                //叔节点是红色的
                if(y->color==Color::Red){
                    z->parent->color = Color::Black;//将父节点变黑色
                    y->color=Color::Black;//将叔节点变黑色。
                    z->parent->parent->color = Color::Red;//爷爷节点设置为红色
                    z = z->parent->parent;//将z点转移到爷爷节点
                }
                //叔节点是黑色的，且z是右节点
                else if(z==z->parent->right){
                    z = z->parent;
                    leftRotation(z);
                }
                //叔节点是黑色的，且z是左节点
                z->parent->color=Color::Black;
                z->parent->parent->color = Color::Red;
                rightRotation(z->parent->parent);
            }
            else{
                auto y=z->parent->parent->right;


            }
        }
        root->color=Color::Black;
    }


    void insert(T value){
        auto z=new RBNode<T>(value,Color::Red);
        auto y=nil;
        auto x=root;

        while(x!=nil){
            y=x;
            if(z->key < x->key){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        z->parent = y;
        if(y==nil){
            root=z;
        }
        else if(z->key < y->key){
            y->left = z;
        }
        else{
            y->right=z;
        }

        z->left=nil;
        z->right=nil;

        insert_fixup(z);
    }



    RBNode<T> *root;
    RBNode<T> *nil;///哨兵，用来简化处理边界条件
};




int main() {
    std::cout << "Hello, World!" << std::endl;

    std::array<int,10> values={7,5,3,1,4,2,8,9,0,6};

    BinarySearchTree<int> tree{};

    for(auto n: values){
        tree.insert(n);
    }

    tree.preOrder();
    tree.midOrder();
    tree.postOrder();

    tree.destroy();

    return 0;
}
