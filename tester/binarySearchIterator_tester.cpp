#include <iostream>
#include <vector>
#include "../include/utils/binarySearchTreeIterator.hpp"
#include "../include/utils/AVLTree.hpp"
// #include "../include/utils/utils.hpp"

int main(void)
{

    // ft::Node<int> root;
    // ft::AVLTree<int, int> root;
    // root.insert(8);
    // left = new ft::Node<int>(9);
    // root.left = new ft::Node<int>(3);
    // root.left->left = new ft::Node<int>(2);
    // root.left->right = new ft::Node<int>(4);
    // root.left->right->right = new ft::Node<int>(5);

    // ft::AVLTree<int, int>::iterator itr = root.begin();
    // std::cout << '\n';
    // std::cout << *itr << '\n';

    ft::pair<char, int> p = ft::make_pair('a', 100);
    ft::AVLTree<char, int> mytree;
    // mytree.insert(p);
    ft::AVLTree<char, int>::iterator it = mytree.begin();
    std::cout << *it << '\n';

    // ft::AVLTree<char, int> v(begin(p), end(p));
    // std::cout << v[0] << " " << v[1] << "\n";
    // first insert function version (single parameter):
    // mytree.insert(100);
    // ft::AVLTree<char, int>::iterator it = mytree.begin();
    // std::cout << *it << '\n';
    // {
    //     float numbers[] = {10.1, 20.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              X b(a): " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float, int> test1(numbers);
    //     ft::BinarySearchTreeIterator<float> until(numbers + 5);
    //     for (ft::BinarySearchTreeIterator<float> it = from; it != until; it++)
    //         std::cout << *it << '\n';
    // }
    // {
    //     float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              b = a: " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float> from(numbers);
    //     ft::BinarySearchTreeIterator<float> newFrom;
    //     newFrom = from;
    //     ft::BinarySearchTreeIterator<float> until(numbers + 5);
    //     ft::BinarySearchTreeIterator<float> newUntil = until;
    //     for (ft::BinarySearchTreeIterator<float> it = newFrom; it != newUntil; it++)
    //         std::cout << *it << '\n';
    // }
    // {
    //     float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              --a: " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float> test3_end(numbers + 4);
    //     ft::BinarySearchTreeIterator<float> test3_start(numbers - 1);
    //     for (ft::BinarySearchTreeIterator<float> it = test3_end; it != test3_start; --it)
    //         std::cout << *it << '\n';
    // }
    // {
    //     float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              a--: " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float> test4_end(numbers + 4);
    //     ft::BinarySearchTreeIterator<float> test4_start(numbers - 1);
    //     for (ft::BinarySearchTreeIterator<float> it = test4_end; it != test4_start; --it)
    //         std::cout << (*it <= *it) << '\n';
    // }
    // {
    //     float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              a += n: " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float> from(numbers);
    //     ft::BinarySearchTreeIterator<float> until(numbers + 6);
    //     for (ft::BinarySearchTreeIterator<float> it = from; it != until; it += 2)
    //         std::cout << *it << '\n';
    // }
    // {
    //     float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              a -= n: " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float> from(numbers + 5);
    //     ft::BinarySearchTreeIterator<float> until(numbers - 1);
    //     for (ft::BinarySearchTreeIterator<float> it = from; it != until; it -= 2)
    //         std::cout << *it << '\n';
    // }
    // {
    //     float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              a + n: " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float> from(numbers);
    //     for (int i = 0; i < 6; i++)
    //         std::cout << *(from + i) << '\n';
    // }
    // {
    //     float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              a - n: " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float> from(numbers + 6);
    //     for (int i = 6; i > 0; i--)
    //         std::cout << *(from - i) << '\n';
    // }
    // {
    //     float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
    //     std::cout << "\n***************************************" << '\n';
    //     std::cout << "\n              a[n]: " << '\n';
    //     std::cout << "\n***************************************" << '\n';
    //     ft::BinarySearchTreeIterator<float> from(numbers);
    //     for (int i = 0; i < 6; i++)
    //         std::cout << from[i] << '\n';
    // }
    std::cout << '\n';
    return 0;
}