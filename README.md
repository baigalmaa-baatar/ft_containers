# ft_containers project

## Preparation
For each container, see and understand what are container's members, non-member overloads and iterators. Then additionally understand these keywords: friend class, difference between ```typename``` and ```class```, iterators definition, input, output, random access iterators, etc. 
You can find it from [here](https://legacy.cplusplus.com/) and [here](https://en.cppreference.com/w/).

## Containers
#### 1. Stack
There are not many things to do.
First I created the skeleton with std::vector, 
```
    template <class T, class Container = ft::vector<T> >
    class stack
    {
```
Then inherited all necessary functions from the vector. 
But after implementing your own vector, you need to change ```std::vector``` to ```ft::vector```. 

#### 2. Vector
It is stack medium interesting. The challenge will be creating ```Random Access Iterator```. Otherwise ```push_back``` and ```pop_back```, other functions are gonna be less interesting. 

#### 3. Map
Map uses Binary Search Tree. If you are like me, never cared about BST, now it is your time to understand and play with BST. 
First you have to choose between AVL tree and Red Black tree. I chose AVL tree, because it seemed easier to develop. The algorithm uses basic Binary Search Tree logic. 
AVL tree uses re-balancing for each ```inserting nodes```, ```deleting node``` actions. Re-balancing is more accurate than Red Black tree. Also, that is why it is slower when inserting node and deleting node actions, because every time it is calculating the balance of the tree. 

I watched many videos about AVL tree insertion, deletion node on Youtube:
[AVl trees insertion and deletion](https://youtu.be/otiDcwZbCo4). You can watch this channel’s videos. I really loved the BST and AVL tree videos. He explained in detail. The channel is [here](https://www.youtube.com/@SimpleSnippets). 

My friend suggested [this method](https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/), it was super helpful for me. 

You can get an impression of AVL tree balancing from [this](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html) nice visualization.

## Tester
First I created my own tester. Then I compared the result with STL container's result. 
I've used [this](https://github.com/valentinllpz/containers_unit_tests) tester's script when I created my own tester. 
So to the ```/tester``` folder. And execute ```./run_tests.sh map``` or want to execute all tests just hit ```./run_tests.sh```.
##### Checking leaks
In root folder, ```make```. In ```Makefile``` you can change which tester you want to execute. Then execute with ```valgrind```. ex: ```valgrind --leak-check=full ./ft_containers ```
