#include<iostream>
#include<string>
#include<vector>
using namespace std;


class shop{
private:
    int cnum;
    int price;
    string name;
public:
    shop(int codenum, int cost, string item_name) {
        this->cnum = codenum;
        this->price = cost;
        this->name = item_name;
    }
    int getcode(){
        int code_number = this->cnum;
        return code_number;
    }
};

void addItem(vector<shop>& shopVector, const shop& obj){
    shopVector.push_back(obj);

}
void delItem(vector<shop>& shopVector) {
    int cnum;
    cout << "Enter the code number";
    cin >> cnum;
    for(int j = 0; j < shopVector.size(); j++)  {
        if (shopVector[j].getcode() == cnum)
            shopVector.erase(shopVector.begin() + j);
    }
}
int main() {
    vector<shop> v1;
    shop o1(293,44,"ParleG");
    addItem(v1, o1);
    delItem(v1);
    if (v1.empty())
        cout << "Empty";
    else {
        for(int j = 0; j< v1.size(); j++) {
            cout << &(v1[j]); }
    }

    return 0;
}