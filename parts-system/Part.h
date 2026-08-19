
#include<string>
using namespace std;

class Part {
public:
    Part(int id, string name, string category, double price);
    
    int getId() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    
    void display() const;

private:
    int id;
    string name;
    string category;
    double price;
};
