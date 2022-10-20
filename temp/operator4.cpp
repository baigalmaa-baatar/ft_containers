class Array 
{
public:
    int& operator[] (unsigned i) 
        { 
        if (i > 99) 
            error(); 
        return data[i]; 
        }
private:
    int data[100];
};

int main()
{
  Array a;
  a[10] = 42;
  a[12] += a[13];
  // ...
}