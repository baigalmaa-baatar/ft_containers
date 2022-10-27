#include <iostream>

class Box 
{
    private:
        double _length;
        double _breadth;
        double _height;
    public:
        // Box() {}
        // ~Box () {}
        //Box1=Box2
        Box& operator=(const Box& rhs)
        {
            this->_length = rhs._length;
            this->_breadth = rhs._breadth;
            this->_height = rhs._height;
            return (*this);
        }

        Box operator+(const Box& rhs)
        {
            Box tmp;
            tmp._length = this->_length + rhs._length;
            tmp._breadth = this->_breadth + rhs._breadth;
            tmp._height = this->_height + rhs._height;
            return (tmp);
        }
        void setLength (double length) {
            this->_length = length;
        }
        void setBreadth (double breadth) {
            this->_breadth = breadth;
        }
        void setHeight (double height) {
            this->_height = height;
        }
        double getVolume (void) {
            return (_length * _breadth * _height);
        }
};

// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   // volume of box 1
   volume = Box1.getVolume();
   std::cout << "Volume of Box1 : " << volume << std::endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   std::cout << "Volume of Box2 : " << volume << std::endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;

   // volume of box 3
   volume = Box3.getVolume();
   std::cout << "Volume of Box3 : " << volume << std::endl;

   return 0;
}