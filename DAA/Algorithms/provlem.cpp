#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int t = n / 7;
  string strings[] = {"DU_TripleTrouble", "DU_Tennessine",  "DU_Irridescent",
                      "DU_HoneyNuts",     "DU_ClumsyCrowd", "DU_Antifragile",
                      "DU__Ascending___"};
  int s = n % 7;
  while (t--) {
    for (const std::string &str : strings) {
      std::cout << str << std::endl;
    }
  }
  int condition = 1; 

  while(s--){
    // You can change the value of 'condition' to 2, 3, etc. to print different strings.

    if (condition == 1) {
        std::string DU_TripleTrouble = "DU_TripleTrouble";
        std::cout << DU_TripleTrouble << std::endl;
    }
    else if (condition == 2) {
        std::string DU_Tennessine = "DU_Tennessine";
        std::cout << DU_Tennessine << std::endl;
    }
    else if (condition == 3) {
        std::string DU_Irridescent = "DU_Irridescent";
        std::cout << DU_Irridescent << std::endl;
    }
    else if (condition == 4) {
        std::string DU_HoneyNuts = "DU_HoneyNuts";
        std::cout << DU_HoneyNuts << std::endl;
    }
    else if (condition == 5) {
        std::string DU_ClumsyCrowd = "DU_ClumsyCrowd";
        std::cout << DU_ClumsyCrowd << std::endl;
    }
    else if (condition == 6) {
        std::string DU_Antifragile = "DU_Antifragile";
        std::cout << DU_Antifragile << std::endl;
    }
    else if (condition == 7) {
        std::string DU__Ascending___ = "DU__Ascending___";
        std::cout << DU__Ascending___ << std::endl;
    }
    else {
        std::cout << "Invalid condition" << std::endl;
    }

    condition++;
  }
  return 0;
}
