#ifndef ECPRODUCT_H
#define ECPRODUCT_H

#include <string>

class Product 
{
public:
  Product(int id, std::string name, double price);
  virtual ~Product() = default;

  int getId() const;
  std::string getName() const;
  double getPrice() const;
  virtual std::string getDescription() const = 0;

private:
  int id_;
  std::string name_;
  double price_;
};


// We have 3 different Products: Book, Electronics, Clothing
// Within our derived classes, provide an implementation to our pure virtual function getDescription
class Electronics: public Product
{
  public:
    Electronics(int id, std::string name, double price, std::string specs);
    ~Electronics();
    std::string getDescription() const override;

  private:
    std::string specs_;
};
class Clothing: public Product
{
  public:
    Clothing(int id, std::string name, double price, std::string specs);
    ~Clothing();
    std::string getDescription() const override;
  private:
    std::string size_;

};
class Book: public Product
{
  public:
    Book(int id, std::string name, double price, std::string author);
    ~Book();
    std::string getDescription() const override;
  private:
    std::string author_;
};
#endif  // ECPRODUCT_H
