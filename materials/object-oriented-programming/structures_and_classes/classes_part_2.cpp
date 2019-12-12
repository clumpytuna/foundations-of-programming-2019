#include <iostream>
#include <string>
#include <vector>

using namespace std;

double ComputeDistance(const string& source, const string& destination) {
  return 0.0;
}

class Route {
 public:
  Route(const string& source, const string& destination) {
    source_ = source;
    destination_ = destination;
    change_route_log.push_back(source_ + " - " + destination_);
    UpdateLength();
  }

  ~Route() {
    for (const string& s: change_route_log) {
      cout << s << endl;
    }
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

  string GetSource() const {
    return source_;
  }

  string GetDestination() const {
    return destination_;
  }

  int GetLength() const {
    return length_;
  }

 private:
   void UpdateLength() {
     length_ = ComputeDistance(source_, destination_);
   }

   string source_;
   string destination_;
   int length_;
   vector<string> change_route_log;
};

void PrintRoute(const Route& route) {
  cout << "Source: " << route.GetSource()
       << " -> Destination: " << route.GetDestination();
}

int main() {
  Route route;
  route.SetSource("Murmansk");
  route.SetDestination("Samara");
  return 0;
}