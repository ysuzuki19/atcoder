#include <iostream>
#include <vector>
#include <tuple>
#define _dbg(var) do{std::cerr << #var << " : " << std::endl; view(var);}while(0)
using namespace std;
using ll = long long;
template<typename T> void view(const T e){ std::cerr << e << std::endl;}
template<typename T> void view(const vector<T>& v){ for(const auto& e : v) std::cerr << e << " "; std::cerr << std::endl; }
template<typename T> void view(const std::vector<std::vector<T>>& vv){ for(const auto& v : vv){ view(v); } }

void mapping ( vector<vector<char>>& map, vector<int>& block_grid_y, vector<int>& block_grid_x, int goal_grid_y, int goal_grid_x) {
  for(int i=0; i<block_grid_y.size(); ++i){
    map[block_grid_x[i]][block_grid_y[i]] = 'b';
  }
  map[goal_grid_x][goal_grid_y] = 'G';
}

void view_map(vector<vector<char>> & map) {
  for(int i=0; i<map.size()*2; ++i) {
    cerr << "_";
  }
  cerr << "_" << endl;
  for(int i=0; i<map.size(); ++i) {
    cerr << "|";
    for(int j=0; j<map[i].size(); ++j) {
      cerr << map[j][i] << " ";
    }
    cerr << "|" << endl;
  }
  for(int i=0; i<map.size()*2; ++i) {
    cerr << "-";
  }
  cerr << "-" << endl;
  return ;
}

void search_arround(int map_size, vector<int>& arround_y, vector<int>& arround_x, int search_grid_y, int search_grid_x){
  arround_x[0] = search_grid_x==0? map_size-1 : search_grid_x-1; arround_x[1] = search_grid_x==0? map_size-1 : search_grid_x-1; arround_x[2] = search_grid_x==0? map_size-1 : search_grid_x-1;
  arround_x[3] = search_grid_x; arround_x[4] = search_grid_x;
  arround_x[5] = search_grid_x==map_size-1? 0 : search_grid_x+1; arround_x[6] = search_grid_x==map_size-1? 0 : search_grid_x+1; arround_x[7] = search_grid_x==map_size-1? 0 : search_grid_x+1;
  arround_y[0] = search_grid_y==0? map_size-1 : search_grid_y-1; arround_y[1] = search_grid_y; arround_y[2] = search_grid_y==map_size-1? 0 : search_grid_y+1;
  arround_y[3] = search_grid_y==0? map_size-1 : search_grid_y-1;                        arround_y[4] = search_grid_y==map_size-1? 0 : search_grid_y+1;
  arround_y[5] = search_grid_y==0? map_size-1 : search_grid_y-1; arround_y[6] = search_grid_y; arround_y[7] = search_grid_y==map_size-1? 0 : search_grid_y+1;
}

std::tuple<int, int, char> make_special_command (int goal_y, int goal_x, int block_y, int block_x) {
  int diff_x = goal_x - block_x;
  int diff_y = goal_y - block_y;
  if(diff_x<0) block_x--;
  else if(diff_x>0) block_x++;
  if(diff_y<0) block_y--;
  else if(diff_y>0) block_y++;
  diff_x = goal_x - block_x;
  diff_y = goal_y - block_y;
  char command;
  if(diff_x==0){
    if(diff_y<0) command = 'U';
    else command = 'D';
  }else if(diff_x<0){
    if(diff_y==0) {
      command = 'L';
    }else if(diff_y<0){
      if(abs(diff_x)>abs(diff_y)) command = 'L';
      else command = 'U';
    }else if(diff_y>0){
      if(abs(diff_x)>abs(diff_y)) command = 'L';
      else command = 'D';
    }
  }else if(diff_x>0){
    if(diff_y==0){
      command = 'D';
    }else if(diff_y<0){
      if(abs(diff_x)>abs(diff_y)) command = 'D';
      else command = 'D';
    }else if(diff_y>0){
      if(abs(diff_x)>abs(diff_y)) command = 'R';
      else command = 'D';
    }
  }
  return std::make_tuple(block_y, block_x, command);
}

void advanced_right_method(vector<vector<char>>& map, vector<vector<char>>& command_map, int goal_y, int goal_x) {
  int map_size = map.size();
  for(int cell_x=0; cell_x<map_size; ++cell_x) {
    for(int cell_y=0; cell_y<map_size; ++cell_y) {
      if(map[cell_x][cell_y] == 'b') {
        vector<int> arround_x(7);
        vector<int> arround_y(7);
        // 0  3  5
        // 1     6
        // 2  4  7
        search_arround(map_size, arround_y, arround_x, cell_y, cell_x);
//        if(map[arround_x[0]][arround_y[0]]==' ') if(command_map[arround_x[0]][arround_y[0]]==' ') command_map[arround_x[0]][arround_y[0]] = 'D';
//        if(map[arround_x[1]][arround_y[1]]==' ') if(command_map[arround_x[1]][arround_y[1]]==' ') command_map[arround_x[1]][arround_y[1]] = 'D';
//        if(map[arround_x[2]][arround_y[2]]==' ') if(command_map[arround_x[2]][arround_y[2]]==' ') command_map[arround_x[2]][arround_y[2]] = 'R';
//        if(map[arround_x[3]][arround_y[3]]==' ') if(command_map[arround_x[3]][arround_y[3]]==' ') command_map[arround_x[3]][arround_y[3]] = 'L';
//        if(map[arround_x[4]][arround_y[4]]==' ') if(command_map[arround_x[4]][arround_y[4]]==' ') command_map[arround_x[4]][arround_y[4]] = 'R';
//        if(map[arround_x[5]][arround_y[5]]==' ') if(command_map[arround_x[5]][arround_y[5]]==' ') command_map[arround_x[5]][arround_y[5]] = 'L';
//        if(map[arround_x[6]][arround_y[6]]==' ') if(command_map[arround_x[6]][arround_y[6]]==' ') command_map[arround_x[6]][arround_y[6]] = 'U';
//        if(map[arround_x[7]][arround_y[7]]==' ') if(command_map[arround_x[7]][arround_y[7]]==' ') command_map[arround_x[7]][arround_y[7]] = 'U';
        int special_x, special_y;
        char special_command;
//        tie(special_y, special_x, special_command) = make_special_command(goal_y, goal_x, cell_y, cell_x);
//        if(map[special_x][special_y]==' ') if(command_map[special_x][special_y]== ' ')  command_map[special_x][special_y] = special_command;
      }
    }
  }
  vector<int> arround_x(7);
  vector<int> arround_y(7);
  search_arround(map_size, arround_y, arround_x, goal_y, goal_x);
  // 0  3  5
  // 1     6
  // 2  4  7
  if(map[arround_x[1]][arround_y[1]]==' ') {
    if(map[arround_y[0]][arround_y[0]]==' ') command_map[arround_x[0]][arround_y[0]] = 'D';
  }else{
    if(map[arround_y[0]][arround_y[0]]==' ') command_map[arround_x[0]][arround_y[0]] = 'R';
  }
  if(map[arround_y[1]][arround_y[1]]==' ') command_map[arround_x[1]][arround_y[1]] = 'R';
  if(map[arround_x[1]][arround_y[1]]==' '){
    if(map[arround_y[2]][arround_y[2]]==' ') command_map[arround_x[2]][arround_y[2]] = 'U';
  }else{
    if(map[arround_y[2]][arround_y[2]]==' ') command_map[arround_x[2]][arround_y[2]] = 'R';
  }
  if(map[arround_y[3]][arround_y[3]]==' ') command_map[arround_x[3]][arround_y[3]] = 'D';
  if(map[arround_y[4]][arround_y[4]]==' ') command_map[arround_x[4]][arround_y[4]] = 'U';
  if(map[arround_x[6]][arround_y[6]]==' '){
    if(map[arround_y[5]][arround_y[5]]==' ') command_map[arround_x[5]][arround_y[5]] = 'D';
  }else{
    if(map[arround_y[5]][arround_y[5]]==' ') command_map[arround_x[5]][arround_y[5]] = 'L';
  }
  if(map[arround_y[6]][arround_y[6]]==' ') command_map[arround_x[6]][arround_y[6]] = 'L';
  if(map[arround_x[6]][arround_y[6]]==' '){
    if(map[arround_y[7]][arround_y[7]]==' ') command_map[arround_x[7]][arround_y[7]] = 'D';
  }else{
    if(map[arround_y[7]][arround_y[7]]==' ') command_map[arround_x[7]][arround_y[7]] = 'L';
  }
}

void defaultD_collaspR_method(vector<vector<char>>& map, vector<vector<char>>& command_map, int goal_y, int goal_x) {
  int map_size = map.size();
  vector<int> arround_x(7);
  vector<int> arround_y(7);
  search_arround(map_size, arround_y, arround_x, goal_y, goal_x);
  // 0  3  5
  // 1     6
  // 2  4  7
  if(map[arround_x[1]][arround_y[1]]==' ') {
    if(map[arround_y[0]][arround_y[0]]==' ') command_map[arround_x[0]][arround_y[0]] = 'D';
  }else{
    if(map[arround_y[0]][arround_y[0]]==' ') command_map[arround_x[0]][arround_y[0]] = 'R';
  }
  if(map[arround_y[1]][arround_y[1]]==' ') command_map[arround_x[1]][arround_y[1]] = 'R';
  if(map[arround_x[1]][arround_y[1]]==' '){
    if(map[arround_y[2]][arround_y[2]]==' ') command_map[arround_x[2]][arround_y[2]] = 'U';
  }else{
    if(map[arround_y[2]][arround_y[2]]==' ') command_map[arround_x[2]][arround_y[2]] = 'R';
  }
  if(map[arround_y[3]][arround_y[3]]==' ') command_map[arround_x[3]][arround_y[3]] = 'D';
  if(map[arround_y[4]][arround_y[4]]==' ') command_map[arround_x[4]][arround_y[4]] = 'U';
  if(map[arround_x[6]][arround_y[6]]==' '){
    if(map[arround_y[5]][arround_y[5]]==' ') command_map[arround_x[5]][arround_y[5]] = 'D';
  }else{
    if(map[arround_y[5]][arround_y[5]]==' ') command_map[arround_x[5]][arround_y[5]] = 'L';
  }
  if(map[arround_y[6]][arround_y[6]]==' ') command_map[arround_x[6]][arround_y[6]] = 'L';
  if(map[arround_x[6]][arround_y[6]]==' '){
    if(map[arround_y[7]][arround_y[7]]==' ') command_map[arround_x[7]][arround_y[7]] = 'D';
  }else{
    if(map[arround_y[7]][arround_y[7]]==' ') command_map[arround_x[7]][arround_y[7]] = 'L';
  }
  for(int loop_cell_x=0; loop_cell_x<map_size; ++loop_cell_x) {
    for(int loop_cell_y=0; loop_cell_y<map_size; ++loop_cell_y) {
      int diff_x = goal_x - loop_cell_x;
      int diff_y = goal_y - loop_cell_y;
      int cell_x = loop_cell_x;
      int cell_y = loop_cell_y;
      if(diff_x<0) cell_x--;
      else if(diff_x>0) cell_x++;
      if(diff_y<0) cell_y--;
      else if(diff_y>0) cell_y++;
      diff_x = goal_x - cell_x;
      diff_y = goal_y - cell_y;
      char command;
      if(diff_x==0){
        if(diff_y<0) command = 'U';
        else command = 'D';
      }else if(diff_x<0){
        if(diff_y==0) {
          command = 'L';
        }else if(diff_y<0){
          if(abs(diff_x)>abs(diff_y)) command = 'L';
          else command = 'U';
        }else if(diff_y>0){
          if(abs(diff_x)>abs(diff_y)) command = 'L';
          else command = 'D';
        }
      }else if(diff_x>0){
        if(diff_y==0){
          command = 'D';
        }else if(diff_y<0){
          if(abs(diff_x)>abs(diff_y)) command = 'D';
          else command = 'D';
        }else if(diff_y>0){
          if(abs(diff_x)>abs(diff_y)) command = 'R';
          else command = 'D';
        }
      }
    }
  }
}

void output_command_map(const vector<vector<char>>& command_map) {
  int command_num = 0;
  for(int i=0; i<command_map.size(); ++i) {
    for(int j=0; j<command_map.size(); ++j) {
      if(command_map[i][j] != ' ') {
        command_num++;
      }
    }
  }
  cout << command_num << endl;
  for(int i=0; i<command_map.size(); ++i) {
    for(int j=0; j<command_map.size(); ++j) {
      if(command_map[i][j] != ' ') {
//        cout << i << " " << j << " " << command_map[i][j] << endl;
        cout << j << " " << i << " " << command_map[i][j] << endl;
      }
    }
  }
}

int main(){
  int i, j;
  int grid_num, robot_num, block_grid_num;
  cin >> grid_num >> robot_num >> block_grid_num;
  int goal_grid_y, goal_grid_x;
  cin >> goal_grid_y >> goal_grid_x;
  vector<int> robot_first_grid_x(robot_num);
  vector<int> robot_first_grid_y(robot_num);
  vector<char> robot_first_command(robot_num);
  for(i=0; i<robot_num; i++) {
    cin >> robot_first_grid_y[i] >> robot_first_grid_x[i] >> robot_first_command[i];
  }
  vector<int> block_grid_x(block_grid_num);
  vector<int> block_grid_y(block_grid_num);
  for(i=0; i<block_grid_num; i++) {
    cin >> block_grid_y[i] >> block_grid_x[i];
  }
//  _dbg(block_grid_x);
//  _dbg(block_grid_y);
  vector<vector<char>> map(grid_num, vector<char>(grid_num, ' '));
  mapping(map, block_grid_y, block_grid_x, goal_grid_y, goal_grid_x);
//  view_map(map);
  vector<vector<char>> command_map(grid_num, vector<char>(grid_num, ' '));
  advanced_right_method(map, command_map, goal_grid_y, goal_grid_x);
//  defaultD_collaspR_method(map, command_map, goal_grid_y, goal_grid_x);
  output_command_map(command_map);
//  view_map(command_map);


  return 0;
}
