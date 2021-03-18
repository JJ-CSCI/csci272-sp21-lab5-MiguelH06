//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{
  protected:
    double a;

  public:
    Real(double b) : a{b}{};
    double GetReal()const {return a;};
    Real operator* (double c) {
      Real k(a * c);
      return k;
    };
};

class Complex : public Real{
  protected:
    double d;

  public:
    Complex(double x, double y) : Real(x), d{y}{};
    double GetImaginary()const {return d;};
    Complex operator* (double l){
      Complex h(a * l, d * l);
      return h;
    };
};

class Surreal : public Complex{
  protected:
    double c;
  
  public:
    Surreal(double x, double y, double z) : Complex(x,y){c = z;};
    double GetSurreal()const {return c;}
    Surreal operator* (double f){
      Surreal n(a * f, d * f, c *f);
      return n;
    };
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
