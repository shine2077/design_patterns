#include <iostream>
#include <string>
/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */
class CanBus {
 public:
  virtual ~CanBus(){};
  virtual std::string deal_can_data() const = 0;
};

class AIV {
 public:
  virtual ~AIV(){};
  virtual std::string deal_aiv_data() const = 0;
};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class sanyCanBus : public CanBus {
 public:
  std::string deal_can_data() const override {
    return "deal sany can data.";
  }
  void sany_can_special_function(){
    std::cout << "sany can special"<< std::endl;
  }
};

class tonlyCanBus : public CanBus {
public:
  std::string deal_can_data() const override {
    return "deal tonly can data.";
  }
   void tonly_can_special_function(){
    std::cout << "tonly can special"<< std::endl;
  }
};

class sanyAIV: public AIV {
 public:
  std::string deal_aiv_data() const override {
    return "deal sany aiv data.";
  }

};

class tonlyAIV : public AIV {
public:
  std::string deal_aiv_data() const override {
    return "deal tonly aiv data.";
  }
};

class CanusFactory {
 public:
  virtual CanBus *CreateCanBus() const = 0;
};

class SanyCanBusFactory : public CanusFactory{
public:
    CanBus *CreateCanBus() const override {
        return new sanyCanBus();
    }
};

class TonlyCanBusFactory : public CanusFactory{
public:
    CanBus *CreateCanBus() const override {
        return new tonlyCanBus();
    } 
};


int main() 
{
  //CanusFactory *canbus_factory = new SanyCanBusFactory();
  CanusFactory *canbus_factory = new TonlyCanBusFactory();
  CanBus *can = canbus_factory->CreateCanBus();
  std::cout << can->deal_can_data() << std::endl;
  delete canbus_factory;
  return 0;
}