#include "List.hpp"

int main() {
  List<int> list = List<int>();
  std::cout << "----- EMPTY LIST -----" << std::endl;
  std::cout << "Size: " << list.size() << std::endl;
  list.print();

  list.append(5);
  list.append(6);
  list.append(7);
  list.append(8);
  list.appendAt(4, 9);
  std::cout << "----- UPDATED LIST -----" << std::endl;
  std::cout << "Size: " << list.size() << std::endl;
  list.print();

  list.removeAt(2);
  list.removeAt(2);
  list.append(11);
  std::cout << "----- UPDATED LIST -----" << std::endl;
  std::cout << "Size: " << list.size() << std::endl;
  list.print();

  List<std::string> textList = List<std::string>();
  std::cout << "----- EMPTY LIST -----" << std::endl;
  std::cout << "Size: " << textList.size() << std::endl;
  textList.print();

  textList.append("c++");
  textList.append("is");
  textList.append("super");
  textList.append("interesting");
  std::cout << "----- UPDATED LIST -----" << std::endl;
  std::cout << "Size: " << textList.size() << std::endl;
  textList.print();

  textList.removeAt(2);
  textList.append("and");
  textList.append("confusing");
  std::cout << "----- UPDATED LIST -----" << std::endl;
  std::cout << "Size: " << textList.size() << std::endl;
  textList.print();

  textList.remove("and");
  textList.remove("confusing");
  textList.remove("interesting");
  textList.append("cool");
  std::cout << "----- UPDATED LIST -----" << std::endl;
  std::cout << "Size: " << textList.size() << std::endl;
  textList.print();

  List<int> otherList = List<int>();
  otherList.append(75);
  otherList.append(76);
  otherList.append(77);
  otherList.removeAt(1);
  otherList.appendAt(2, 100);
  List<int> mergedList = list + otherList;
  mergedList.remove(6);
  std::cout << "----- MERGED LIST -----" << std::endl;
  std::cout << "Size: " << mergedList.size() << std::endl;
  mergedList.print();

  int array[mergedList.size()];
  mergedList.toArray(array);
  for(int item: array) std::cout << item << "\n";
  return 0;
}
