// this is the design of taskmanagment in which every task has its own priority and userid ,based on the highest priority we execute the task, if two task has same priority ,the one with higher taskid will be executed..
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class TaskManager{
  public:
  typedef pair<int,int>P;
  priority_queue<P>maxheap;
  unordered_map<int,int>taskownwermpp;
  unordered_map<int,int>taskprioritympp;
  TaskManager(vector<vector<int>>&tasks){
    for(auto &task:tasks){
      add(task[0],task[1],task[2]);
    }
  }
  void add(int userid,int taskid,int priority){
    maxheap.push({priority,taskid});
    taskownwermpp[taskid]=userid;
    taskprioritympp[taskid]=priority;

  }
void edit(int taskid,int newpriority){
  maxheap.push({newpriority,taskid});
  taskprioritympp[taskid]=newpriority;
}
void rmv(int taskid){
  taskprioritympp[taskid]=-1;
}
int exectop(){
  while(!maxheap.empty()){
     pair<int,int> p = maxheap.top();
    int prior = p.first;
    int taskid = p.second;
    maxheap.pop();
    if(prior==taskprioritympp[taskid]){
      taskprioritympp[taskid]=-1;
      return taskownwermpp[taskid];


    }
  }
  return -1;
}



  

};
int main() {

    vector<vector<int>> tasks = {
        {1,101,10},
        {2,102,20},
        {3,103,15}
    };

    TaskManager obj(tasks);

    obj.add(4,104,18);

    cout << obj.exectop() << endl;

    obj.edit(101,25);

    cout << obj.exectop() << endl;

    obj.rmv(103);

    cout << obj.exectop() << endl;

    return 0;
}
