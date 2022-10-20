#include <iostream>

class TestClass {
    private:
        int _count;
    public:
        TestClass (int count = 5) : _count(count) {}
        ~TestClass () {}

        TestClass operator--(){
            this->_count = this->_count - 3;
            return (*this);
        }

        void Display(void) {
            std::cout << this->_count << '\n';
        }
};

int main() 
{
	TestClass tc;
	--tc;
	tc.Display();
	return 0;
}