#include "Trees.h"
#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

struct Node {
  int value;
  Node *left;
  Node *right;
};

/* Fn to create a new node */
Node *CreateNode(int data) {
  Node *newNode = new Node();

  if (!newNode) {
    std::cout << "Memory Error\n";
  }

  newNode->value = data;
  return newNode;
}

Node *InsertNode(Node *root, int data) {
  if (root == NULL) {
    root = CreateNode(data);
    return root;
  }

  std::queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *tmp = q.front();
    q.pop();

    if (tmp->left == NULL) {
      tmp->left = CreateNode(data);
      return root;
    }

    if (tmp->right == NULL) {
      tmp->right = CreateNode(data);
      return root;
    }

    q.push(tmp->left);
    q.push(tmp->right);
  }

  return root;
}

void InorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  InorderTraversal(root->left);
  std::cout << root->value << '\n';
  InorderTraversal(root->right);
}

Trees::Trees() {
  Node *n = CreateNode(19);
  InsertNode(n, 25);
  InsertNode(n, 5);
  InsertNode(n, -20);

  InorderTraversal(n);
}
