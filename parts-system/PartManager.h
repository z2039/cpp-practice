#include "Part.h"
#include <vector>
using namespace std;

class PartManager {
public:
    void addPart(int id, string name, string category, double price);
    void showAll() const;
    void findById(int id) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);

private:
    vector<Part> parts;
};