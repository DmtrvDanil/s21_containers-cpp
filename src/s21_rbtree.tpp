#include "s21_rbtree.h"

namespace s21{

    template<class Key, class Value>
    Tree<Key, Value>::Tree() {
        this->root_ = nullptr;
        this->nil_ = new ReadBlackTree<Key, Value>;
    }

    template<class key_type, class mapped_type>
    Tree<key_type, mapped_type>& Tree<key_type, mapped_type>::operator=(const Tree &other) {
        this->root_ = other.root_;
        this->nil_ = other.nil_;
        return *this;
    }


    template<class Key, class Value>
    Tree<Key, Value>::~Tree() {
        delete this->nil_;
    }

    template<class Key, class Value>
    void Tree<Key, Value>::init(Key key, Value value) {
        read_black_node tmp_tree = new ReadBlackTree<Key, Value>;
        tmp_tree->color_ = READ;
        tmp_tree->left_ = nullptr;
        tmp_tree->right_ = nullptr;
        tmp_tree->parent_ = nullptr;
        tmp_tree->data_.first = key;
        tmp_tree->data_.second = value;
        this->insert_node(this->root_, tmp_tree);


    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::insert_node(read_black_node &root, read_black_node new_tree) {
        read_black_node x = root;
        read_black_node y = nullptr;
        while (x != nullptr) {
            y = x;
            if (new_tree->data_.first > x->data_.first) {
                x = x->right_;
            } else {
                x = x->left_;
            }
        }
        new_tree->parent_ = y;
        if (y != nullptr) {
            if (new_tree->data_.first > y->data_.first) {
                y->right_ = new_tree;
            } else {
                y->left_ = new_tree;
            }
        } else {
            root = new_tree;
        }
        new_tree->color_ = READ;
        this->insert_fix(root, new_tree);
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::insert_fix(read_black_node &root, read_black_node &node) {
        read_black_node parent = node->parent_;
        bool flag = true;
        while (node != this->root_ && parent->color_ == READ) {
            read_black_node grand_parent = parent->parent_;
            if (parent == grand_parent->left_) {
                this->fix_parent_left(root, parent, grand_parent, node, flag);
            } else {
                this->fix_parent_right(root, parent, grand_parent, node, flag);
            }
        }
        this->root_->color_ = BLACK;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::fix_parent_right(read_black_node &root, read_black_node &parent,
                                                       read_black_node &grand_parent, read_black_node &node,
                                                       bool flag) {
        read_black_node uncle = grand_parent->left_;
        if (uncle != nullptr && uncle->color_ == true) {
            parent->color_ = BLACK;
            uncle->color_ = BLACK;
            grand_parent->color_ = READ;
            node = grand_parent;
            parent = node->parent_;
        } else {
            if (parent->left_ == node) {
                right_rotate(root, parent);
                std::swap(node, parent);
            }
            parent->color_ = BLACK;
            grand_parent->color_ = READ;
            left_rotate(root, grand_parent);
            flag = false;
        }
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::fix_parent_left(read_black_node &root, read_black_node &parent,
                                                      read_black_node &grand_parent, read_black_node &node, bool flag) {
        read_black_node uncle = grand_parent->right_;
        if (uncle != nullptr && uncle->color_ == true) {
            parent->color_ = BLACK;
            uncle->color_ = BLACK;
            grand_parent->color_ = READ;
            node = grand_parent;
            parent = node->parent_;
        } else {
            if (parent->right_ == node) {
                left_rotate(root, parent);
                std::swap(node, parent);
            }
            parent->color_ = BLACK;
            grand_parent->color_ = READ;
            right_rotate(root, grand_parent);
            flag = false;
        }
    }

    template<class key_type, class mapped_type>
    typename Tree<key_type, mapped_type>::read_black_node Tree<key_type, mapped_type>::search_in_root(read_black_node &root, key_type key) {
        read_black_node result = root;
        if (root == nullptr || root->data_.first == key) {
            return result;
        }
        if (root->data_.first > key) {
            return this->search_in_root(root->left_, key);
        }
        else {
            return this->search_in_root(root->right_, key);
        }
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::left_rotate(read_black_node &root, read_black_node &x) {
        read_black_node y = x->right_;
        x->right_ = y->left_;
        if (y->left_ != nullptr) {
            y->left_->parent_ = x;
        }
        y->parent_ = x->parent_;
        if (x->parent_ == nullptr) {
            root = y;
        }
        else {
            if (x == x->parent_->left_) {
                x->parent_->left_ = y;
            } else {
                x->parent_->right_ = y;
            }
        }
        y->left_ = x;
        x->parent_ = y;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::right_rotate(read_black_node &root, read_black_node &y) {
        read_black_node x = y->left_;
        y->left_ = x->right_;
        if (x->right_ != nullptr) {
            x->right_->parent_ = y;
        }
        x->parent_ = y->parent_;
        if (y->parent_ == nullptr) {
            if (y == y->parent_->right_) {
                y->parent_->right_ = x;
            } else {
                y->parent_->left_ = x;
            }
        }
        x->right_ = y;
        y->right_ = x;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::remove_node(read_black_node &root, read_black_node &node) {
        read_black_node child;
        read_black_node father;
        NodeColor color;
        if (node->left_ != nullptr && node->right_ != nullptr) {  	// Левый и правый узлы удаленного узла не пусты (не конечные узлы)
            read_black_node replace = node->right_;  // Найти узел-преемник (самый нижний левый узел правого поддерева текущего узла)
            this->find_right_replace(root, replace, node);
            child = replace->right_;
            father = replace->parent_;
            color = replace->color_;
            this->replace_with_new_node(father, replace, node, child);
        } else {
            this->remove_node_with_one_child(node, child, father, color);
        }
        if (color == BLACK) {
            this->remove_fix(root, child, father);
        }
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::remove_node_with_one_child(read_black_node &node, read_black_node &child,
                                                                 read_black_node &father, NodeColor color) {
        if (node->left_ != nullptr) {   // save a child
            child = node->right_;
        } else {
            child = node->right_;
        }
        father = node->parent_;
        color = node->color_;
        if (child) {
            child->parent_ = father;
        }
        if (father) {
            if (father->left_ == node) {
                father->left_ = child;
            } else {
                father->right_ = child;
            }
        } else {
            this->root_ = child;
        }
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::find_right_replace(read_black_node &root, read_black_node &replace,
                                                         read_black_node &node) {
        while (replace->left_ != nullptr) {  // ищем самый левый элемент в правом поддереве
            replace = replace->left_;
        }
        if (node->parent_ != nullptr) {
            if (node->parent_->left_ == node) {  // если это не корневой элемент
                node->parent_->left_ = replace;  // устанавливаем предку нового потомка
            } else {
                node->parent_->right_ = replace;
            }
        } else {
            root = replace;
        }
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::replace_with_new_node(read_black_node &father, read_black_node &replace,
                                                            read_black_node &node, read_black_node child) {
        if (father == node) {  // если правый потомок старого элемента и есть новый элемент
            father = replace;  // устанавливаем родителя для дальнейшей балансировки дерева
        } else {
            if (child != nullptr) { // сдвигаем потомка нового элемента на его место
                child->parent_ = father;
            }
            father->left_ = child;
            replace->right_ = node->right_; // родним потомка старого элемента с новым
            node->right_->parent_ = replace;
        }
        replace->parent_ = node->parent_;  // устанавливаем новый элемент на место старого
        replace->color_ = node->color_;
        replace->left_ = node->left_;
        node->left_->parent_ = replace;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::remove_fix(read_black_node &root, read_black_node &node,
                                                 read_black_node &father) {
        read_black_node brother;
        bool flag = true;
        while(((!node) || node->color_ == BLACK) && node != root && flag) {
            if (node == father->left_) {
                flag = this->fix_right_brother(brother, node, father);
            } else {
                flag = this->fix_left_brother(brother, node, father);
            }
            if (node) {
                node->color_ = BLACK;
            }
        }

    }

    template<class key_type, class mapped_type>
    bool Tree<key_type, mapped_type>::fix_left_brother(read_black_node &brother, read_black_node &node,
                                                       read_black_node father) {
        brother = father->left_;
        bool result = true;
        if (!brother || brother->color_ == BLACK) {
            if (brother && brother->left_ && brother->left_->color_ == READ) {
                brother->color_ = father->color_;
                father->color_ = BLACK;
                this->right_rotate(this->root_, father);
                brother->left_->color_ = BLACK;
                result = false;
            } else if (brother && brother->right_ && brother->right_->color_ == READ) {
                brother->color_ = READ;
                brother->right_->color_ = BLACK;
                this->left_rotate(this->root_, brother);
            }  else if (brother && ((!brother->left_ || brother->left_->color_ == false) ||
                                    (!brother->right_ || brother->right_->color_ == false))) {
                brother->color_ = true;
                if (father->color_ == true) {
                    father->color_ = false;
                    result = false;
                }
                node = father;
                father = node->parent_;
            }
        } else if (brother && brother->color_ == READ) {
            brother->color_ = BLACK;
            father->color_ = READ;
            this->right_rotate(this->root_, father);
        }
        return result;

    }

    template<class key_type, class mapped_type>
    bool Tree<key_type, mapped_type>::fix_right_brother(read_black_node &brother, read_black_node &node,
                                                        read_black_node &father) {
        brother = father->right_;
        bool result = true;
        if (!brother || brother->color_ == BLACK) {
            if (brother && brother->right_ && brother->right_->color_ == READ) {
                brother->color_ = father->color_;
                father->color_ = BLACK;
                this->left_rotate(this->root_, father);
                brother->right_->color_ = BLACK;
                result = false;
            } else if (brother && brother->left_ && brother->left_->color_ == READ) {
                brother->color_ = READ;
                brother->left_->color_ = BLACK;
                this->right_rotate(this->root_, brother);
            } else if (brother && ((!brother->left_ || brother->left_->color_ == BLACK) ||
                                    (!brother->right_ || brother->right_->color_ == BLACK ))) {
                brother->color_ == READ;
                if (father->color_ == READ) {
                    father->color_ == BLACK;
                    result = false;
                }
                node = father;
                father = node->parent_;
            }
        } else if (brother && brother->color_ == READ) {
            brother->color_ = BLACK;
            father->color_ = READ;
            this->left_rotate(this->root_, father);

            }
        return result;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::print_tree(read_black_node node) {
        if (node != nullptr){
            print_tree(node->left_);
            std::cout << root_->data_.first << " ";
            print_tree(node->right_);
        }
    }

    template<class key_type, class mapped_type>
    typename Tree<key_type, mapped_type>::read_black_node Tree<key_type, mapped_type>::search(key_type key) {
        return this->search_in_root(this->root_, key);
    }

    template <class key_type, class mapped_type>
    bool Tree<key_type, mapped_type>::insert(key_type key,Duplicate dupl,  mapped_type value) {
        bool result = false;
        if (dupl == WITHOUT_DUPLICATE) {
            if (search(key) == nullptr) {
                init(key, value);
                result = true;
            }
        } else {
            this->init(key, value);
            result = true;
            }
        return result;
    }

    template<class key_type, class mapped_type>
    void Tree<key_type, mapped_type>::remove(key_type key) {
        read_black_node node = search(key);
        if (node != nullptr) {
            this->remove_node(this->root_, node);
        }
    }



} // namespace s21
