#include <bits/stdc++.h>

using namespace std;
//Requires c++17


void clearInput() {
  while ((getchar()) != '\n');
}

void print(string message) {
  cout << message << endl;
}

void beginQuestionSeries(string questionSeries) {
  ifstream series("./Series/" + questionSeries + ".txt");
  string line = "";
  int index = 0;
  while (!series.eof()) {
    index++;
    getline(series, line);
    if (index % 2 == 0)
    {
      clearInput();
      string answer;
      cin >> answer;
      print("Oikea vastaus: " + line);
    }
    else {
      print(line);
    }
  }
  series.close();
}

void listQuestions() {
  for (const auto &entry :  std::filesystem::directory_iterator("./Series")) {
    string name = entry.path().filename().string();
    int pos = name.find(".txt");
    name.erase(pos, 4);
    cout << "- " << name << endl;
  }
}

int main() {
  print("Tervetuloa kysymyspeliin!");
  while (true) {
    print("Valitse kysymyssarja <CTRL+C Lopettaa>: ");
    listQuestions();
    string selectedSeries;
    cin >> selectedSeries;
    beginQuestionSeries(selectedSeries);
    std::cout<< u8"\033[2J\033[1;1H";
  }

}

