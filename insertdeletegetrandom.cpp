#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet{
  private:
  vector<int>vec;
  unordered_map<int,int>mpp;

public:
RandomizedSet() {}
bool insert(int val){
  if(mpp.find(val)!=mpp.end()) return false;
  vec.push_back(val);
  mpp[val]=vec.size()-1;
  return true;


}
bool remove(int val){
  if(mpp.find(val)==mpp.end()) return false;
  int index=mpp[val];
  int lastelement=vec.back();
  vec.back()=val;
  vec[index]=lastelement;
  
  mpp[lastelement]=index;
  vec.pop_back();

   mpp.erase(val);
   return true;



}
int getrandom(){
  int randomindex=rand()%vec.size();
  return vec[randomindex];
}

};
int main() {

    RandomizedSet rs;

    cout << rs.insert(1) << endl;   // true
    cout << rs.remove(2) << endl;   // false
    cout << rs.insert(2) << endl;   // true
    cout << rs.getrandom() << endl; // 1 or 2
    cout << rs.remove(1) << endl;   // true
    cout << rs.insert(2) << endl;   // false
    cout << rs.getrandom() << endl; // 2

    return 0;
}

