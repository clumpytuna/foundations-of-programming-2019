# Structures and Classes in C++
## Part II

In this notes we continue to look at classes in C++. Last time we started to create a class represents the idea of a route. We want to have an object that can store source, destination and length of a path between them. This is the code we wrote [last time](structures_and_classes.md):

   ```c++
   class Route {
    public:
   
     string GetSource() {
       return source;
     }
   
     string GetDestination() {
       return destination;
     }
   
     int GetLength() {
       return length;
     }
   
     void SetSource(const string& new_source) {
       source = new_source;
       UpdateLength();
     }
   
     void SetDestination(const string& new_destination) {
       destination = new_destination;
       UpdateLength();
     }
   
    private:
     void UpdateLength() {
       length = ComputeDistance(source, destination);
     }
   
     string source;
     string destination;
     int length;
   };
   ```
   
   **Constant methods**
   
   Let's run a simple function to print a route:
   ```c++
   void PrintRoute(const Route& route) {
     cout << "Source: " << route.GetSource() << " -> Destination: " << route.GetDestination(); 
   }
   ```
   We don't want to change an object and of course we don't want to copy an object, so we use constant reference as a type of function parameter. But if we try to run such code:
   ```
   Route route;
   route.SetSource("Moscow");
   route.SetDestination("Saint Petersburg");
   PrintRoute(route);
   ```
   
   We will get an error:
   ```c++
   error: 'this' argument to member function 'GetSource' has type 'const Route', but function is not marked const
     cout << route.GetSource() << " - " << 
     
   error: 'this' argument to member function 'GetDestination' has type 'const Route', but function is not marked const
          route.GetDestination() << endl;
          
   ```
   
   _Why did it happen?_
    
   We tried to call non constant method when we passed the object by constant reference. If we call a non constant method of an object then we can change it, and in our case compiler doesnt allow us to do it cause the object were passed by constant reference. In fact we don't want to change the object some how. We just want to get a source and a destination and then print it. In C++ you can mark methods as constant and it is a very good practice. This practice makes your code more safe and more predictable. 
   
   GetDestination, GetSource and GetLength methods don't change anything in our object. Let's mark them as constant.
   ```c++
   class Route {
    public:
     
     string GetSource() const {
       return source_;
     }
   
     string GetDestination() const {
       return destination_;
     }
   
     int GetLength() const {
       return length_;
     }
   
     void SetSource(const string& new_source) {
       source_ = new_source;
       UpdateLength();
     }
   
     void SetDestination(const string& new_destination) {
       destination_ = new_destination;
       UpdateLength();
     }
   
    private:
     void UpdateLength() {
       length_ = ComputeDistance(source_, destination_);
     }
   
     string source_;
     string destination_;
     int length_;
   };
   ```
   
   **Parametrized constructors**
   
   What if we want to create a route object between two certain cities? We can use the following code to do that:
   ```c++
   Route route;
   route.SetSource("Moscow");
   route.SetDestination("Saint Petersburg");
   ```
   
   It seems that it is too much to write 3 lines of code to such an easy thing! To make our life better we can write a function to create an object:
   ```c++
   Route CreateRoute(const string& source, const string& destination) {
       Route route;
       route.SetSource("Moscow");
       route.SetDestination("Saint Petersburg");
       return route;
   }
   ```
   
   But this solution is still not so great. A name of the function is not standardized. We can name our function to build a route by any name. If we have a name of a class we can't guess a name a function to build an object. C++ has a way to solve this problem:  constructors. You are already familiar with constructors. You used it when you worked with standard containers.
   
   For example to create a vector size of n we are calling constructor:
   ```c++
   vector<int> numbers(5);
    
   ```
   
   It will be very useful if we can create routes like this:
   ```
   Route route("Moscow", "Saint Petersburg");
   ```
   
   _To do that let's use constructors!_
   ```c++
   class Route {
    public:
     Route(const string& source, const string& destination) {
        source_ = source;
        destination_ = destination;
        UpdateLength();
     }
     
     ...
   ```
   
   To define constructor you should use syntax similar of creating a method:
   - no need to write a returning type
   - write name of a class
   - write parameters just like when you write functions or methods
   
   Now we can use the desirable syntax:
   ```c++
   Route route("Moscow", "Saint Petersburg");
   PrintRoute(route);
   ```
   
   
   Let's look at our class one more time:
   ```c++
   class Route {
    public:
     Route(const string& source, const string& destination) {
       source_ = source;
       destination_ = destination;
       UpdateLength();
     }
   
     string GetSource() const {
       return source_;
     }
   
     string GetDestination() const {
       return destination_;
     }
   
     int GetLength() const {
       return length_;
     }
   
     void SetSource(const string& new_source) {
       source_ = new_source;
       UpdateLength();
     }
   
     void SetDestination(const string& new_destination) {
       destination_ = new_destination;
       UpdateLength();
     }
   
    private:
     void UpdateLength() {
       length_ = ComputeDistance(source_, destination_);
     }
   
     string source_;
     string destination_;
     int length_;
   };

   ```
   
   **Default Constructors**
   
   
   Now let's try to create a route as we did before:
   ```c++
   Route route;
   ```
   
   Suddenly this code will cause an error!
   ```c++
   error: no matching constructor for initialization of 'Route'
     Route route;
   ```
   
   Hmm, we have a problem! We can't even create an object without parameters! But before we created a new constructor we can create objects without parameters.  
   
   To fix it let's write a default constructor:
   ```c++
   class Route {
     public:
      Route() {} // previously compiler created default constructor for us
        
      Route(const string& source, const string& destination) {
        source_ = source;
        destination_ = destination;
        UpdateLength();
      }
      ....
   ``` 
   
   If we don't want to initialize fields by some default value we can leave a constructor empty. If there is no constructor for a class, then compiler creates an empty constructor.
   
   
   If we want to initialize fields by default then we can do it in a default constructor:
   ``` c++
      class Route {
        public:
         Route() {
           source_ = "Moscow";
           destination = "Saint Petersburg";
           UpdateLength();
         } 
         ...
           
   ``` 
   
   If we declare variable without parameters then the default constructor will be called:
   ```c++
   Route myRoute; // route from Moscow to Saint Petersburg
   ```
   If we put parameters then the parameterized constructor will be called:
   ```c++
   Route myNextRoute("Saint Petersburg", "Helsinki"); // parameterized constructor
   ```
   
   If you want to pass default object by constant reference you can use empty braces to do it:
   ```c++
   void PrintRoute(const Route& route);
   
   PrintRoute({});
   PrintRoute(Route());
   ```      
   
   
   If you want to pass an object created using a parameterized constructor then you can list arguments in braces to construct it:
   ```c++
   PrintRoute(Route("Saratov", "Volgograd"));
   PrintRoute({"Saratov","Volgograd"})
   ```
   
   **Default fields in Structures**
   
   Working with structures usually we don't need to write constructors. We can use braces to create an object:
   ```c++
   struct Point {
     double x;
     double y;
   };
   
   Point A = {1.0, 2.0};
   ``` 
   
   Sometimes we want to initialize a structure by default. In this case it's enough to set default values of fields:
   ```c++
   struct Point {
     double x = 0.0;
     double y = 0.0;
   };
   
   Point A;
   cout << A.x << ' ' << A.y;
   // 0.0 0.0
   ``` 
   
   Moreover you can still use syntax with braces:
   ```c++
   Point B = {0.0, 12.0};
   
   ```
   You can pass only 1 parameter then all others will be initialize by default values:
   
   ```c++
   Point C = {1.0};
   ```
   
   
   **Destructors**
   
   Destructor is a member function which are calling when object is destructing. When a class contains a pointer to memory allocated in class, we should write a destructor to release memory before the class instance is destroyed. This must be done to avoid memory leak.
    
   A destructor function is called automatically when the object goes out of scope:
   - the function ends
   - the program ends
   - a block containing local variables ends
   - a delete operator is called
   
   Destructors have same name as the class preceded by a tilde (~). Destructors don’t take any argument and don’t return anything. If we do not write our own destructor in class, compiler creates a default destructor for us.  
   
   
   Consider Route class we created:
   ```c++
   
    class Route {
     public:
      Route(const string& source, const string& destination) {
        source_ = source;
        destination_ = destination;
        UpdateLength();
      }
    
      Route() {
        source_ = "Moscow";
        destination_ = "Saint-Petersburg";
        UpdateLength();
      }
    
    
      string GetSource() const {
        return source_;
      }
    
      string GetDestination() const {
        return destination_;
      }
    
      int GetLength() const {
        return length_;
      }
    
      void SetSource(const string& new_source) {
        source_ = new_source;
        UpdateLength();
      }
    
      void SetDestination(const string& new_destination) {
        destination_ = new_destination;
        UpdateLength();
      }
    
     private:
      void UpdateLength() {
        length_ = ComputeDistance(source_, destination_);
      }
    
      string source_;
      string destination_;
      int length_;
    };
   ```
   
   Let's log information about changes of route and write it to the console when object is destroyed.
   
   To do that we add a new field vector<string> change_route_log:
   ```c++
   ...
     private:
         ...  
       string source_;
       string destination_;
       int length_;
       // New field
       vector<string> change_route_log
   };
   ```
   
   And update the new field every time we change a route.
   ```c++
       
  class Route {
    public:
      Route(const string& source, const string& destination) {
        source_ = source;
        destination_ = destination;
        change_route_log.push_back(source_ + " - " + destination_);
        UpdateLength();
      }
        
      Route() {
        source_ = "Moscow";
        destination_ = "Saint-Petersburg";
        change_route_log.push_back(source_ + " - " + destination_);
        UpdateLength();
      }

      void SetSource(const string& new_source) {
        source_ = new_source;
        change_route_log.push_back(source_ + " - " + destination_);
        UpdateLength();
      }
       
      void SetDestination(const string& new_destination) {
        destination_ = new_destination;
        change_route_log.push_back(source_ + " - " + destination_);
        UpdateLength();
      }
    ...
   
   ```
   
   
   In the destructor we print information about changes before deleting an object:
   ```c++
   ...
   ~Route() {
     for (const string& s: change_route_log) {
       cout << s << endl;
     }
   }
   ...
   ```
   
   
   Let's check out output of the following code: 
   ```c++
   Route route;
   route.SetSource("Murmansk");
   route.SetDestination("Samara");
   ```
   
   ```
   Moscow - Saint Petersburg
   Murmansk - Saint Petersburg
   Murmansk - Samara 
   ```
  
  **You can find source code [here](classes_part_2.cpp) and more information [here](https://en.cppreference.com/w/cpp/language/classes).**
      
   
   