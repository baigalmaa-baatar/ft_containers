#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
    typedef __PTRDIFF_TYPE__ ptrdiff_t;
    static class nullptr_t
    {
    public:
        template <class T>   /* convertible to any type       */
        operator T *() const /* of null non-member            */
        {
            return 0;
        } /* pointer...                    */

        template <class C, class T> /* or any type of null           */
        operator T C::*() const     /* member pointer...             */
        {
            return 0;
        }

    private:
        void operator&() const; /* Can't take address of nullptr */

    } ft_nullptr = {}; /* and whose name is nullptr     */

    struct random_access_iterator_tag
    {
    };

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };
    template <class T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef random_access_iterator_tag iterator_category;
        typedef T *pointer;
        typedef T &reference;
    };

    template <class T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef random_access_iterator_tag iterator_category;
        typedef const T *pointer;
        typedef const T &reference;
    };
}

#endif