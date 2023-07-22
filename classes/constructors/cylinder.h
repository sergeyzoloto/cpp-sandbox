#ifndef CYLINDER_H
#define CYLINDER_H

#include "cylinder.h"

// * CLASSES

/*
Class member variables can either be raw stack variables or pointers,
but can never be references. A reference can never be left uninitialized,
but the ability to leave these variables uninitialized is crucial.

Classes have functions - methods.
Class methods have access to the member variables, regardless of
whether they are public or private.
Private members are not accessible from the outside of the class
definition.
*/

// * Constructors
/*
Constructors are special class methods, that are called to construct
your class object.
They never have return.
They have the same name.
Can have parameters.
Usually used to initialize member variables and put the in a state
where you want them in a C++ application.
*/

// * Setters and getters
/*
These methods allows us to get the access to the member variables.
Getters return variables, setters update variables.
*/

class Cylinder
{
public:
  // Actually, an empty object will be constructed with
  // no particular constructor

  // Constructors
  Cylinder() = default;
  Cylinder(double rad_param, double height_param);
  double volume();
  double get_base_radius();
  double get_height();
  void set_base_radius(double radius_param);
  void set_height(double height_param);

  // Methods

private:
  // Member variables
  double base_radius{1};
  double height{1};
};

#endif