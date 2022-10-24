#include <iostream>
#include <vector>

using namespace std;

char gameboard[13][7];
int visited[13][7];
int chain, count;
bool boom;

void debug_print(string msg) {
  cout << msg << '\n';
  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= 6; j++) {
      cout << gameboard[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

void init_visited() {
  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= 6; j++) {
      visited[i][j] = 0;
    }
  }
}

void cleanup() {
  for (int i = 1; i <= 6; i++) {
    vector<char> column;
    for (int j = 12; j >= 1; j--) {
      if (gameboard[j][i] != '.') {
        column.push_back(gameboard[j][i]);
      }
    }
    int j;
    for (j = 0; j < column.size(); j++) {
      gameboard[12 - j][i] = column[j];
    }
    for (j = 12 - column.size(); j >= 1; j--) {
      gameboard[j][i] = '.';
    }
  }
}

void dfs(int i, int j, char prev) {
  visited[i][j] = 1;
  count++;
  if (i - 1 >= 1 && gameboard[i - 1][j] == prev && visited[i - 1][j] == 0) {
    dfs(i - 1, j, prev);
  }
  if (i + 1 <= 12 && gameboard[i + 1][j] == prev && visited[i + 1][j] == 0) {
    dfs(i + 1, j, prev);
  }
  if (j - 1 >= 1 && gameboard[i][j - 1] == prev && visited[i][j - 1] == 0) {
    dfs(i, j - 1, prev);
  }
  if (j + 1 <= 6 && gameboard[i][j + 1] == prev && visited[i][j + 1] == 0) {
    dfs(i, j + 1, prev);
  }
}

void erase(int i, int j, char prev) {
  visited[i][j] = 0;
  gameboard[i][j] = '.';
  if (i - 1 >= 1 && gameboard[i - 1][j] == prev && visited[i - 1][j] == 1) {
    erase(i - 1, j, prev);
  }
  if (i + 1 <= 12 && gameboard[i + 1][j] == prev && visited[i + 1][j] == 1) {
    erase(i + 1, j, prev);
  }
  if (j - 1 >= 1 && gameboard[i][j - 1] == prev && visited[i][j - 1] == 1) {
    erase(i, j - 1, prev);
  }
  if (j + 1 <= 6 && gameboard[i][j + 1] == prev && visited[i][j + 1] == 1) {
    erase(i, j + 1, prev);
  }
}

void puyo() {
  for (int i = 12; i >= 1; i--) {
    for (int j = 1; j <= 6; j++) {
      if (gameboard[i][j] != '.' && visited[i][j] == 0) {
        dfs(i, j, gameboard[i][j]);
        if (count >= 4) {
          boom = true;
          erase(i, j, gameboard[i][j]);
        }
        count = 0;
      }
    }
  }

  if (boom) {
    cleanup();
    chain++;
    boom = false;
    init_visited();
    puyo();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= 6; j++) {
      char block;
      cin >> block;
      gameboard[i][j] = block;
      visited[i][j] = 0;
    }
  }

  chain = 0;
  count = 0;
  boom = false;
  puyo();

  cout << chain << '\n';
  return 0;
}
