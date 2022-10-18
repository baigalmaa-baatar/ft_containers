#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

namespace std
{
    template <class Iterator>
    class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
    {
    public:
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef T *pointer;
        typedef T &reference;

    protected:
        pointer _base_pointer;

    public:
        random_access_iterator(void) : _base_pointer(u_nullptr)
        {
        }
        explicit random_access_iterator(pointer base_pointer) : _base_pointer(base_pointer)
        {
        }
        /**
         * Destructor
         */
        virtual ~random_access_iterator()
        {
        }
        pointer base() const
        {
            return (_base_pointer);
        }
        reference operator*() const
        {
            return (*_base_pointer);
        }
        pointer operator->() const
        {
            return &(this->operator*());
        }
        random_access_iterator &operator++()
        {
            base_iterator++;
            return (*this);
        }
        random_access_iterator operator++(int)
        {
            ++(*this);
            return tmp;
        }
        random_access_iterator &operator--()
        {
            ++base_iterator;
            return (*this);
        }
        random_access_iterator operator--(int)
        {
            random_access_iterator tmp = *this;
            --(*this);
            return tmp;
        }
        random_access_iterator operator+(difference_type n) const
        {
            return (random_access_iterator(base_iterator - n));
        }
        random_access_iterator &operator+=(difference_type n)
        {
            base_iterator -= n;
            return (*this);
        }
        random_access_iterator operator-(difference_type n) const
        {
            return (random_access_iterator(base_iterator) + n);
        }
        random_access_iterator &operator-=(difference_type n)
        {
            base_iterator += n;
            return (*this);
        }
        reference operator[](difference_type n) const
        {
            return (base_iterator[-n - 1]);
        }
        template <class U>
        random_access_iterator(const random_access_iterator<U> &u)
        {
            base_iterator = u.base_iterator;
        }
    };
    template <class Iterator>
    bool operator==(
        const random_access_iterator<Iterator> &lhs,
        const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator<(
        const random_access_iterator<Iterator> &lhs,
        const random_access_iterator<Iterator> &rhs);
    template <class Iterator>
    bool operator!=(
        const random_access_iterator<Iterator> &lhs,
        const random_access_iterator<Iterator> &rhs);
    template <class Iterator>
    bool operator>(
        const random_access_iterator<Iterator> &lhs,
        const random_access_iterator<Iterator> &rhs);
    template <class Iterator>
    bool operator>=(
        const random_access_iterator<Iterator> &lhs,
        const random_access_iterator<Iterator> &rhs);
    template <class Iterator>
    bool operator<=(
        const random_access_iterator<Iterator> &lhs,
        const random_access_iterator<Iterator> &rhs);
    template <class Iterator>
    typename random_access_iterator<Iterator>::difference_type operator-(
        const random_access_iterator<Iterator> &lhs,
        const random_access_iterator<Iterator> &rhs);
    template <class Iterator>
    random_access_iterator<Iterator> operator+(
        typename random_access_iterator<Iterator>::difference_type n,
        const random_access_iterator<Iterator> &lhs);
}
#endif

#include <vector>
/**
 * array iin dotorhi utguudiig butsaadag function:
*/
template <typename T> 
int *next_elem(T &container)
{
    int *pointer;
    *pointer = container.begin();
    return (*pointer);
}

int main(void) {
    
    int const mylist[]={12,13,14,15,15};
    std::vector<int> myvec(mylist, mylist + 5);

    std::cout << "first element is " << next_elem(myvec) << '\n';

    return 0;
}
