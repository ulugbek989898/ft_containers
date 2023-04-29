/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:05:44 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/23 12:18:48 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

#include <iostream>
#include <algorithm>
#include <cstring>

namespace ft
{

	struct Node {
		int key;
		int val;
		Node* left;
		Node* right;
		int height;
	};

	class AVLTree {
	public:
		AVLTree() {
			root = 0;
		}

		void insert(int key, int val) {
			root = insertNode(root, key, val);
		}

		void remove(int key) {
			root = removeNode(root, key);
		}

		int find(int key) {
			Node* node = findNode(root, key);
			if (node != 0) {
				return node->val;
			} else {
				return -1;
			}
		}

	private:
		Node* root;

		int getHeight(Node* node) {
			if (node == 0) {
				return -1;
			} else {
				return node->height;
			}
		}

		Node* rotateRight(Node* node) {
			Node* leftChild = node->left;
			node->left = leftChild->right;
			leftChild->right = node;
			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			leftChild->height = std::max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;
			return leftChild;
		}

		Node* rotateLeft(Node* node) {
			Node* rightChild = node->right;
			node->right = rightChild->left;
			rightChild->left = node;
			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			rightChild->height = std::max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;
			return rightChild;
		}

		Node* rotateLeftRight(Node* node) {
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		Node* rotateRightLeft(Node* node) {
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		int getBalanceFactor(Node* node) {
			if (node == 0) {
				return 0;
			} else {
				return getHeight(node->left) - getHeight(node->right);
			}
		}

		Node* insertNode(Node* node, int key, int val) {
			if (node == 0) {
				Node* newNode = new Node;
				newNode->key = key;
				newNode->val = val;
				newNode->left = 0;
				newNode->right = 0;
				newNode->height = 0;
				return newNode;
			}

			if (key < node->key) {
				node->left = insertNode(node->left, key, val);
				int balanceFactor = getBalanceFactor(node);
				if (balanceFactor == 2) {
					if (key < node->left->key) {
						node = rotateRight(node);
					} else {
						node = rotateLeftRight(node);
					}
				}
			} else if (key > node->key) {
				node->right = insertNode(node->right, key, val);
				int balanceFactor = getBalanceFactor(node);
				if (balanceFactor == -2) {
					if (key > node->right->key) {
						node = rotateLeft(node);
					} else {
						node = rotateRightLeft(node);
					}
				}
			} else {
				node->val = val;
			}

		node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
		return node;
		}

		Node* findNode(Node* node, int key) {
			if (node == 0) {
				return 0;
			}

			if (key < node->key) {
				return findNode(node->left, key);
			} else if (key > node->key) {
				return findNode(node->right, key);
			} else {
				return node;
			}
		}

		Node* removeNode(Node* node, int key) {
			if (node == 0) {
				return 0;
			}

			if (key < node->key) {
				node->left = removeNode(node->left, key);
			} else if (key > node->key) {
				node->right = removeNode(node->right, key);
			} else {
				if (node->left == 0 && node->right == 0) {
					delete node;
					return 0;
				} else if (node->left == 0) {
					Node* temp = node->right;
					delete node;
					return temp;
				} else if (node->right == 0) {
					Node* temp = node->left;
					delete node;
					return temp;
				} else {
					Node* temp = findMinNode(node->right);
					node->key = temp->key;
					node->val = temp->val;
					node->right = removeNode(node->right, temp->key);
				}
			}

			int balanceFactor = getBalanceFactor(node);
			if (balanceFactor == 2) {
				if (getBalanceFactor(node->left) >= 0) {
					node = rotateRight(node);
				} else {
					node = rotateLeftRight(node);
				}
			} else if (balanceFactor == -2) {
				if (getBalanceFactor(node->right) <= 0) {
					node = rotateLeft(node);
				} else {
					node = rotateRightLeft(node);
				}
			}

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			return node;
		}

		Node* findMinNode(Node* node) {
			if (node->left == 0) {
				return node;
			} else {
				return findMinNode(node->left);
			}
		}
	};
} // namespace ft


#endif