#include "knight2.h"

// Linked List : BEGIN ---------------------------

class Node {
private:
    int count;
    string itemType;
    Node* next;
public:
    Node* makeNode(int, string);
    void insertFirst(Node*&, int);
};
// Tạo Node
Node* Node::makeNode(int cnt, string ItemType) {
    Node* tmp = new Node();//Cấp phát
    tmp->count = cnt;
    tmp->itemType = ItemType;
    tmp->next = nullptr;
    return tmp;
}

void Node::insertFirst(Node*& a, int x) {
    Node* tmp = makeNode(x);//Cấp phát 1 node mới
    if (a == NULL) {
        a = tmp; //Neu a rong thi tmp la node dau tien
    }
    else {
        tmp->next = a;//Ko nen lam nguoc lai vi` no se mat het
        a = tmp;
    }
}

// Linked List : END   ---------------------------

/* * * BEGIN implementation of class BaseBag * * */

class BaseBag
{
private:
    BaseKnight* knight;
    int bag_size;
    int cnt_item;
    Node* Item;
public:
    virtual bool insertFirst(BaseItem* item);
};

bool BaseBag::insertFirst(BaseItem* item)
{
    if (cnt_item < bag_size)
    {
        Node* tmp = new Node
    }
}

BaseItem* BaseBag::get ( ItemType itemType )
{
    // duyệt tìm Node trong LinkedList trùng tên với itemType, nếu k có thì return NULL


    //  nếu tìm ra thì đổi chổ nó với thằng đầu của linkedlist rồi return về Node đó
}

string BaseBag::toString ()
{
    string res = "Bag[count=";
    int k = cnt_item;
    string Num = "";
    while(k > 0)
    {
        Num = (char)(k % 10 + '0');
        k/=10;
    }
    res += Num + ";";
    // Viết giúp t đoạn duyệt qua các phần tử và lấy tên của chúng trong LinkedList Item của lớp BaseBag
}
/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

/* * * END implementation of class KnightAdventure * * */