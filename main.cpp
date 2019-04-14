#include "manager.hpp"

int main() {
  Manager *manager = new Manager(":1");

  manager->run();

  return 0;
}
