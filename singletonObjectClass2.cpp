/*
//https://www.interviewsansar.com/2014/10/25/singleton-class-design-with-an-example/

Design Singleton class in C++ with example – Simple Steps
October 25, 2014 by Rakesh Singh
(Last Updated On: June 21, 2019)

Answer: Singleton class in C++ is the class that is designed to provide only one unique instance across the system. So, whenever we create c++ singleton instance, it will return the same instance created earlier if any.
About method and variables for Designing Singleton class in C++

Singleton class requires below methods and variables.

    Private singleton constructor and copy Constructor : Singleton class should not allow users to create singleton instances but they should request class to return an instance. Hence, make the constructor and copy constructor of singleton class private to prevent object instantiation.
    A public static function: As, it has blocked users to create objects, there should be a static function that returns object to the users using class name.
    A private static pointer: We need a static class pointer in singleton class to allocate object that will be returned to users. Why static pointer, as static function accepts only static variables as a parameter.

Design of C++ singleton class
[Just to focus, GetInstance() is a static method that will return class object pointer to users.

static Singleton* s_instance a private static pointer.]

C++ singleton class example
*/

#include <iostream>

using namespace std;

class Singleton{
public:
  static Singleton* GetInstance(){
    if(NULL == s_instance)
      {
        cout<<"kp: s_instance is the pointer of type Singleton class and when an"<<endl
            <<"    object is created, it's pointer is assigned to s_instance."<<endl;

        cout<<"kp: Before obj creation: s_instance = "<<s_instance<<endl;

        s_instance=new Singleton();

        cout<<"kp: After obj creation: s_instance = "<<s_instance<<endl;
      }

    return s_instance;
  }
  void display(){
    printf("Singleton class!!!\n");
  }

  ~Singleton(){
    //delete s_instance;
  }
private:
  // Make the constructor private so, user can
  //create object directly but with GetInstance() method.
  Singleton(){}
  // copy constructor private
  Singleton(const Singleton & obj){}

  static Singleton* s_instance;

};


// initialize static singleton pointer
//Singleton *Singleton::s_instance = 0;
Singleton *Singleton::s_instance; //kp: This is my line & it seems it assigns 0 by default

//Singleton class example test:

//Test method
int main(){
  //cout<<"kp: s_instance = "<<Singleton::s_instance<<endl;
  //Singleton pattern
  Singleton* s_obj1 = Singleton::GetInstance();
  s_obj1->display();

  cout<<"Address of object-1 is:"<<s_obj1<<"\n";
  Singleton* s_obj2 = Singleton::GetInstance();
  s_obj2->display();

  cout<<"Address of object-2 is:"<<s_obj2<<"\n";

  cout<<"Note that address of both object obj1 & obj2 must be same"<<endl;


  return 0;
}

/*
Output :
Singleton class!!!
Address of object is:00757948
Singleton class!!!
Address of object is:00757948

Note that in the above output addresses of the objects are same.

NOTES:

Singleton is not a keyword, it is just the concept we apply over a class that need to return only one instance.

We have make copy constructor in singleton class private, as below code will violate singleton class design, if it is public and even though constructor is private.

//Checking copy constructor
*/


      /*Singleton s_obj3 = *s_obj2;//derefrence the object to copy

      s_obj3.display();

      cout<<“Address of object is:”<<&s_obj3<<“\n”;*/
                                           /*
NOTE:
In the above single class design, the  C++ singleton thread safe program and C++ delete singleton object example has been excluded. As for this singleton class interview question, interviewers expect only concept. However, they may ask for thread safe singleton class in C++ and object deletion design as a next questions or in some interviews, it may be a direct question.
                                           */

/*
  More readings on singleton:

  http://jrruethe.github.io/blog/2015/08/02/singletons/

  The Singleton pattern is a design pattern that restricts the instantiation of a class to one object. It is typically used for solving the problem of resource contention, such that you need to manage a single instance of a resource. Singletons are misunderstood and difficult to implement correctly, hopefully this post can clear things up.

  ...
  ...

  http://www.yolinux.com/TUTORIALS/C++Singleton.html
  Why use a singleton class?

  This design pattern and methodology ensures that only one instance of the C++ class is instantiated. It assures that only one object is created and no more. It is often used for a logging class so only one object has access to log files, or when there is a single resource, where there should only be a single object in charge of accessing the single resource. The singleton pattern discussed here gives the class itself, the responsibility of enforcement of the guarantee that only one instance of the class will be allowed to be generated.
...
...
https://sourcemaking.com/design_patterns/singleton/cpp/1
A global variable is default initialized - when it is declared - but it is not initialized in earnest until its first use. This requires that the initialization code be replicated throughout the application.
...
...

Make the class responsible for its own global pointer and "initialization on first use" (by using a private static pointer and a public static accessor method). The client uses only the public accessor method.

*/
