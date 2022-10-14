class Foo {
  public:
    int fooVar = 10;
    int getFooVar();
}
The implementation for getFooVar() would be:

   int Foo::getFooVar() {
       return fooVar;
   