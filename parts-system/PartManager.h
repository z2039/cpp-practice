#include "Part.h"
#include <vector>
using namespace std;

class PartManager {
public:
    void addPart(int id, string name, string category, double price);
    void showAll() const;
    void findById(int id) const;

private:
    vector<Part> parts;
};