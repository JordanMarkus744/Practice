#pragma once
#include <iostream>
#include <memory>

template<typename T>
class Tree{
    struct Node{
        T data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(){
            left = nullptr;
            right = nullptr;
        }
    };
    std::shared_ptr<Node> root;

    std::shared_ptr<Node> deleteLeaf(T data, std::shared_ptr<Node>& curr){ // helper function that returns leaf we want to delete
        if (curr->data == data){
            return curr;
        }
        return deleteLeaf(data, curr->left);
        return deleteLeaf(data, curr->right);
    }


    std::shared_ptr<Node> addLeaf(T data, std::shared_ptr<Node>& curr){ // helper function for the overloaded function addLeaf(T data);
        std::cout<< "ahhh" << std::endl;
        if (data <= curr->data){
            if (curr->left == nullptr){
                return curr;
            }
            else{
                return addLeaf(data, curr->left);
            }
        }
        else{
            if (curr->right == nullptr){
                return curr;
            }
            else{
                return addLeaf(data, curr->right);
            }
        }
        return curr;
    }

    public:

    
    Tree(T data){
        root = std::make_shared<Node>();
        root->data = data;
    }

    void addLeaf(T data){
        if (!root){
            root->data = data;
        }
        else{
            std::cout << "Leaf Added!" << std::endl;
            std::shared_ptr<Node> parent;
            parent = addLeaf(data, root);
            std::shared_ptr<Node> temp;

            if (data <= parent->data){
                parent->left->data = data;
            }
            else{
                parent->right->data = data;
            }
            
        }
    }

    

    // deleting a node and cleaning up the tree

    bool deleteLeaf(T data){
        if (!root){
            std::cout << "Tree is empty!" << std::endl;
            return false;
        }
        else{
            std::shared_ptr<Node> curr = deleteLeaf(data, root);
            if (curr->data != data){
                return false;
            }
            if (curr->left && curr->right){ // if left and right exist and left->data == data
                std::shared_ptr<Node> newNode;
                std::shared_ptr<Node> rightTemp;
                newNode->data = data;
                newNode->right = curr->right;
                std::shared_ptr<Node> temp;(curr->left);
                if (temp->left){
                    newNode->left = temp->left;
                }
                if (temp->right){
                    rightTemp = temp->right;
                    if (newNode->right){
                        std::shared_ptr<Node> rightSide(newNode->right);
                        while(rightSide->left != nullptr){
                            rightSide = rightSide->left;
                        }
                        rightSide->left = rightTemp;
                    }
                    else{
                        newNode->right = rightTemp;
                    }
                }
                curr = newNode; // This deletes the node and replaces it with its left child and updates the tree
            }
            else if (curr->right && !curr->left){
                std::shared_ptr<Node> newNode;
                newNode = curr->right;
                curr = newNode;
            }
            else if (curr->left && !curr->right){
                std::shared_ptr<Node> newNode;
                newNode = curr->left;
                curr = newNode;
            }
        }
        return true;
    }

    void Traverse(){
        std::shared_ptr<Node> temp(root);
        Traverse(temp);
    }

    void Traverse(std::shared_ptr<Node> current){
        std::cout << "ahhh" << std::endl;
        if (current){
            Traverse(current->left);
            std::cout << current->data << std::endl;
            Traverse(current->right);
        }
        else{
            std::cout << "Tree is empty!" << std::endl;
        }

    }

    
};  