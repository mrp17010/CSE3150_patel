// Code for modeling a university's various units: department, office,
// college, etc
#include <vector>

// Generic interface. 
class ECUnit
{
public:
  virtual ~ECUnit() {}
  virtual double GetBudget() const = 0;
};

// Department
class ECDepartment : public ECUnit
{
public:
	ECDepartment(int b) : b(b)  {}
	double GetBudget() const { return b; }

private:
  int b;
};

// Office
class ECOffice : public ECUnit
{
public:
  ECOffice(int b) : b(b) {}
  double GetBudget() const { return b; }

private:
  int b;
};

// Composite
class ECCompositeUnit : public ECUnit
{
public:
  ECCompositeUnit()  {}
  ~ECCompositeUnit()
  {
    // do we need to free? 
    // yes, we should
    for(auto x : listUnits)
    {
      delete x;
    }
  }
  
  double GetBudget() const 
  { 
    double sum = 0.0;
    for(auto x : listUnits)
    {
      sum += x->GetBudget();
    }
    return sum;
  }
  void AddChild(ECUnit *pUnit)
  {
    listUnits.push_back(pUnit);
  }

private:
  std::vector<ECUnit *> listUnits;
};

