#ifndef NODE_H
#define NODE_H

template<class T>
class Node{
    private:
        T data;
        Node<T>* left;
        Node<T>* right;

    public:
        Node(T data){
            this->data = data;
            left=NULL;
            right=NULL;
        }

        T getData(){
            return data;
        }

        Node<T>* getLeft(){
            return left;
        }

        Node<T>* getRight(){
            return right;
        }

        void setLeft(Node<T>* left){
            this->left = left;
        }

        void setRight(Node<T>* right){
            this->right = right;
        }
        void setData(T data){  // para eliminar 
            this->data = data; 
        }
};

#endif