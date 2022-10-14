class Foo {
  public:
    int fooVar = 10;
    int getFooVar();
};

int Foo::getFooVar() {
    return fooVar;
}

template <class T>
class Foo1 {
  public:
    int fooVar1 = 10;
    int getFooVar1();
};

template <class T>
int Foo1<T>::getFooVar1() {
    return fooVar;
}
